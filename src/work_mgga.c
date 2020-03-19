/*
 Copyright (C) 2006-2018 M.A.L. Marques
 Copyright (C) 2019 X. Andrade

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/**
 * @file work_mgga.c
 * @brief This file is to be included in MGGA functionals.
 */
   
/* hack to avoid compiler warnings */
#define NOARG

#ifdef XC_NO_EXC
#define OUT_PARAMS MGGA_OUT_PARAMS_NO_EXC(NOARG)
#else
#define OUT_PARAMS zk, MGGA_OUT_PARAMS_NO_EXC(NOARG)
#endif

#ifdef HAVE_CUDA
__global__ static void 
work_mgga_gpu(const XC(func_type) *p, int order, size_t np, const double *rho, const double *sigma, const double *lapl, const double *tau,
              double *zk, MGGA_OUT_PARAMS_NO_EXC(double *));
#endif

/**
 * @param[in,out] func_type: pointer to functional structure
 */
static void 
work_mgga(const XC(func_type) *p, size_t np,
         const double *rho, const double *sigma, const double *lapl, const double *tau,
          double *zk, MGGA_OUT_PARAMS_NO_EXC(double *))
{

  int order = -1;
  if(zk     != NULL) order = 0;
  if(vrho   != NULL) order = 1;
  if(v2rho2 != NULL) order = 2;
  if(v3rho3 != NULL) order = 3;

  if(order < 0) return;
  
#ifdef HAVE_CUDA

  //make a copy of 'p' since it might be in host-only memory
  XC(func_type) * pcuda = (XC(func_type) *) libxc_malloc(sizeof(XC(func_type)));

  *pcuda = *p;

  auto nblocks = np/CUDA_BLOCK_SIZE;
  if(np != nblocks*CUDA_BLOCK_SIZE) nblocks++;
  
  work_mgga_gpu<<<nblocks, CUDA_BLOCK_SIZE>>>(pcuda, order, np, rho, sigma, lapl, tau, zk, MGGA_OUT_PARAMS_NO_EXC(NOARG));
 
  libxc_free(pcuda);
  
#else

  size_t ip;
  double my_rho[2] = {0.0, 0.0}, my_sigma[3] = {0.0, 0.0, 0.0}, my_tau[2] = {0.0, 0.0};
  double dens, zeta;

  for(ip = 0; ip < np; ip++){
    /* sanity check on input parameters */
    my_rho[0]   = max(0.0, rho[0]);
    my_sigma[0] = max(0.0, sigma[0]);
    my_tau[0]   = max(0.0, tau[0]);
    /* lapl can have any values */
    if(p->nspin == XC_POLARIZED){
      my_rho[1]   = max(0.0, rho[1]);
      my_sigma[1] = sigma[1];
      my_sigma[2] = max(0.0, sigma[2]);
      my_tau[1]   = max(0.0, tau[1]);
    }
    
    xc_rho2dzeta(p->nspin, my_rho, &dens, &zeta);

    if(dens > p->dens_threshold){
      if(p->nspin == XC_UNPOLARIZED){             /* unpolarized case */
        func_unpol(p, order, my_rho, my_sigma, lapl, my_tau, OUT_PARAMS);
      
      }else if(zeta >  1.0 - 1e-10){              /* ferromagnetic case - spin 0 */
        func_ferr(p, order, my_rho, my_sigma, lapl, my_tau, OUT_PARAMS);
        
      }else if(zeta < -1.0 + 1e-10){              /* ferromagnetic case - spin 1 */
        internal_counters_mgga_next(&(p->dim), -1, &rho, &sigma, &lapl, &tau, &zk, MGGA_OUT_PARAMS_NO_EXC(&));
        func_ferr(p, order, &my_rho[1], &my_sigma[2], lapl, &my_tau[1], OUT_PARAMS);
        internal_counters_mgga_prev(&(p->dim), -1, &rho, &sigma, &lapl, &tau, &zk, MGGA_OUT_PARAMS_NO_EXC(&));
      }else{                                      /* polarized (general) case */
        func_pol(p, order, my_rho, my_sigma, lapl, my_tau, OUT_PARAMS);
      } /* polarization */
    }

    /* check for NaNs */
#ifdef XC_DEBUG
    {
      size_t ii;
      const xc_dimensions *dim = &(p->dim);
      int is_OK = 1;
      
      if(zk != NULL)
        is_OK = is_OK & isfinite(*zk);

      if(vrho != NULL){
        for(ii=0; ii < dim->vrho; ii++)
          is_OK = is_OK && isfinite(vrho[ii]);
        for(ii=0; ii < dim->vsigma; ii++)
          is_OK = is_OK && isfinite(vsigma[ii]);
        if(p->info->flags & XC_FLAGS_NEEDS_LAPLACIAN)
          for(ii=0; ii < dim->vlapl; ii++)
            is_OK = is_OK && isfinite(vlapl[ii]);
        for(ii=0; ii < dim->vtau; ii++)
          is_OK = is_OK && isfinite(vtau[ii]);
      }
      
      if(!is_OK){
        printf("Problem in the evaluation of the functional\n");
        if(p->nspin == XC_UNPOLARIZED){
          printf("./xc-get_data %d 1 ", p->info->number);
          if(p->info->flags & XC_FLAGS_NEEDS_LAPLACIAN)
            printf("%le 0.0 %le 0.0 0.0 %le 0.0 %le 0.0\n",
                   *rho, *sigma, *lapl, *tau);
          else
            printf("%le 0.0 %le 0.0 0.0 0.0 0.0 %le 0.0\n",
                  *rho, *sigma, *tau);
        }else{
          printf("./xc-get_data %d 2 ", p->info->number);
          if(p->info->flags & XC_FLAGS_NEEDS_LAPLACIAN)
            printf("%le %le %le %le %le %le %le %le %le\n",
                   rho[0], rho[1], sigma[0], sigma[1], sigma[2], lapl[0], lapl[1], tau[0], tau[1]);
          else
            printf("%le %le %le %le %le 0.0 0.0 %le %le\n",
                   rho[0], rho[1], sigma[0], sigma[1], sigma[2], tau[0], tau[1]);
        }
      }
    }
#endif
    
    internal_counters_mgga_next(&(p->dim), 0, &rho, &sigma, &lapl, &tau, &zk, MGGA_OUT_PARAMS_NO_EXC(&));
  }   /* for(ip) */

#endif

}

#ifdef HAVE_CUDA
__global__ static void 
work_mgga_gpu(const XC(func_type) *p, int order, size_t np,
              const double *rho, const double *sigma, const double *lapl, const double *tau,
              double *zk, MGGA_OUT_PARAMS_NO_EXC(double *))
{

  size_t ip = blockIdx.x * blockDim.x + threadIdx.x;

  if(ip >= np) return;
  
  double my_rho[2] = {0.0, 0.0}, my_sigma[3] = {0.0, 0.0, 0.0}, my_tau[2] = {0.0, 0.0};
  double dens, zeta;

  internal_counters_mgga_random(&(p->dim), ip, 0, &rho, &sigma, &lapl, &tau, &zk, MGGA_OUT_PARAMS_NO_EXC(&));
  
  /* sanity check on input parameters */
  my_rho[0]   = max(0.0, rho[0]);
  my_sigma[0] = max(0.0, sigma[0]);
  my_tau[0]   = max(0.0, tau[0]);
  /* lapl can have any values */
  if(p->nspin == XC_POLARIZED){
    my_rho[1]   = max(0.0, rho[1]);
    my_sigma[1] = sigma[1];
    my_sigma[2] = max(0.0, sigma[2]);
    my_tau[1]   = max(0.0, tau[1]);
  }  
  xc_rho2dzeta(p->nspin, my_rho, &dens, &zeta);
  
  if(dens > p->dens_threshold){
    if(p->nspin == XC_UNPOLARIZED){             /* unpolarized case */
      func_unpol(p, order, my_rho, my_sigma, lapl, my_tau, OUT_PARAMS);
      
    }else if(zeta >  1.0 - 1e-10){              /* ferromagnetic case - spin 0 */
      func_ferr(p, order, my_rho, my_sigma, lapl, my_tau, OUT_PARAMS);
      
    }else if(zeta < -1.0 + 1e-10){              /* ferromagnetic case - spin 1 */
      internal_counters_mgga_next(&(p->dim), -1, &rho, &sigma, &lapl, &tau, &zk, MGGA_OUT_PARAMS_NO_EXC(&));
      func_ferr(p, order, &my_rho[1], &my_sigma[2], lapl, &my_tau[1], OUT_PARAMS);

    }else{                                      /* polarized (general) case */
      func_pol(p, order, my_rho, my_sigma, lapl, my_tau, OUT_PARAMS);

    } /* polarization */
  }
  
}
#endif

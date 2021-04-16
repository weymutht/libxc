/*
 Copyright (C) 2021 V. von Burg

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

/************************************************************************
 Implements a short-range version of the Perdew, Burke & Ernzerhof
 Generalized Gradient Approximation exchange functional
************************************************************************/

#define XC_GGA_X_GWS        997 /* Short-range PBE exchange functional by Goll, Werner, Stoll */

typedef struct{
  double kappa, b_pbe, alpha, mu;
} gga_x_gws_params;
  
static void gga_x_gws_init(xc_func_type *p)
{
  gga_x_gws_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = libxc_malloc(sizeof(gga_x_gws_params));
}

#define GWS_N_PAR 4
static const char  *gws_names[GWS_N_PAR] = {"_kappa","_b_pbe", "_alpha", "_mu"};
static const char  *gws_desc[GWS_N_PAR] = {
  "Asymptotic value of the enhancement function", 
  "Coefficient of the 2nd order expansion", 
  "Fit coefficient of Gaussian cut-off function",
  "Range-separation parameter"};

static const double  gws_values[GWS_N_PAR] =
  {0.8040, 0.2195149727645171, 19.0, 0.4};

static void
gws_lambda_set_ext_params(xc_func_type *p, const double *ext_params)
{
  gga_x_gws_params *params;

  assert(p != NULL && p->params != NULL);
  params = (gga_x_gws_params *) (p->params);

  params->kappa = get_ext_param(p, ext_params, 0);
  params->b_pbe = get_ext_param(p, ext_params, 1);
  params->alpha = get_ext_param(p, ext_params, 2);
  params->mu    = get_ext_param(p, ext_params, 3);
}

#include "decl_gga.h"
#include "maple2c/gga_exc/gga_x_gws.c"
#include "work_gga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_x_gws = {
  XC_GGA_X_GWS,
  XC_EXCHANGE,
  "Short-range PBE Exchange by Goll, Werner & Stoll",
  XC_FAMILY_GGA,
  {&xc_ref_Perdew1996_3865, &xc_ref_Perdew1996_3865_err, &xc_ref_Goll2005_3917, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-12,
  {GWS_N_PAR, gws_names, gws_desc, gws_values, gws_lambda_set_ext_params},
  gga_x_gws_init, NULL,
  NULL, work_gga, NULL
};

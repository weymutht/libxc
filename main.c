#include <stdio.h>

#include <xc.h>

int main()

{
  xc_func_type func;
  double rho[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
  double sigma[5] = {0.2, 0.3, 0.4, 0.5, 0.6};
  double exc[5];
  int i, vmajor, vminor, vmicro, func_id = 999; // Use func_id = 130 for standard PBE, 999 for new PBEHSERI

xc_version(&vmajor, &vminor, &vmicro);
printf("Libxc version: %d.%d.%d\n", vmajor, vminor, vmicro);

if(xc_func_init(&func, func_id, XC_UNPOLARIZED) != 0){
fprintf(stderr, "Functional '%d' not found\n", func_id);
return 1;
}

// Get default value of mu
double mu = xc_func_info_get_ext_params_default_value(func.info, 3);
printf("Default value of mu: %f\n", mu);
// Modify value of mu
mu = 1.0;
xc_func_set_ext_params_name(&func, "_mu", mu);

switch(func.info->family)
{
case XC_FAMILY_LDA:
xc_lda_exc(&func, 5, rho, exc);
break;
case XC_FAMILY_GGA:
case XC_FAMILY_HYB_GGA:
xc_gga_exc(&func, 5, rho, sigma, exc);
break;
}

for(i=0; i<5; i+=1){
printf("%lf %lf\n", rho[i], exc[i]);
}

xc_func_end(&func);
}

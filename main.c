#include <stdio.h>
#include <xc.h>
//#include <iostream>

int main()

{
  xc_func_type func;
  double rho[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
  double sigma[5] = {0.2, 0.3, 0.4, 0.5, 0.6};
  double exc[5];
  int i, vmajor, vminor, vmicro, func_id = 998; //Use func_id = 130 for standard PBE, 999 for new PBEHSERI, 524 for X_WPBEH, 997 for GWS Exchange, 998 for GWS correlation, 590 for sr-LDA correlation  

xc_version(&vmajor, &vminor, &vmicro);
printf("Libxc version: %d.%d.%d\n", vmajor, vminor, vmicro);

int a = 1000;
a = xc_func_init(&func, func_id, XC_UNPOLARIZED);

if(a != 0){
fprintf(stderr, "Functional '%d' not found\n", func_id);
return 1;
}

printf("Printing info: \n");
int  npar = xc_func_info_get_n_ext_params(func.info);
  if(npar > 0) {
    printf("\nFunctional has %i external parameters:\n",npar);
    printf("%3s %13s %8s %s\n","idx","value","name","description");
    for(i = 0; i < npar; i++)
      printf("%3i % e %8s %s\n", i,
             xc_func_info_get_ext_params_default_value(func.info, i),
             xc_func_info_get_ext_params_name(func.info, i),
             xc_func_info_get_ext_params_description(func.info, i));
  } else {
    printf("\nFunctional has no external parameters.\n");
  }


// Get default value of mu
double mu = xc_func_info_get_ext_params_default_value(func.info, 3);
//double mu = xc_func_info_get_ext_params_default_value(func.info, 0);
printf("Default value of mu: %f\n", mu);

for (int j=0;j<5;j++){
// Modify value of mu
switch(j)
{
  case 0: mu = 0.0;
          printf("\nmu now: %lf", mu);
          break;
  case 1: mu = 0.4;
          printf("\nmu now: %lf", mu);
          break;
  case 2: mu = 10;
          printf("\nmu now: %lf", mu);
          break;
  case 3: mu = 1000000;
          printf("\nmu now: %lf", mu);
          break;
  case 4: mu = 1000000000;
          printf("\nmu now: %lf", mu);
}

printf("\n Mu after loop: %lf", mu);
printf("\nSetting mu to %lf ", mu);
xc_func_set_ext_params_name(&func, "_mu", mu);
//printf("Setting omega: \n");
//xc_func_set_ext_params_name(&func, "_omega", mu);

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
printf("\n");
for(i=0; i<5; i+=1){
printf("%lf %lf\n", rho[i], exc[i]);
}

}

xc_func_end(&func);
}

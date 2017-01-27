/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/gga_k_dk.mpl
  Type of functional: work_gga_x
*/

void XC(gga_k_dk_enhance)
  (const XC(func_type) *p, int order, 
   FLOAT x, FLOAT *f, FLOAT *dfdx, FLOAT *d2fdx2, FLOAT *d3fdx3)
{
  double t3, t4, t7, t8, t11, t12, t15, t16;
  double t19, t22, t25, t28, t31, t34, t35, t38;
  double t41, t44, t47, t49, t50, t51, t60, t69;
  double t71, t75, t76, t77, t87, t105;

  gga_k_dk_params *params;
 
  assert(p->params != NULL);
  params = (gga_k_dk_params * )(p->params);

  t3 = params->aa[1];
  t4 = x * x;
  t7 = params->aa[2];
  t8 = t4 * t4;
  t11 = params->aa[3];
  t12 = t8 * t4;
  t15 = params->aa[4];
  t16 = t8 * t8;
  t19 = 0.10e1 * params->aa[0] + 0.10e1 * t3 * t4 + 0.10e1 * t7 * t8 + 0.10e1 * t11 * t12 + 0.10e1 * t15 * t16;
  t22 = params->bb[1];
  t25 = params->bb[2];
  t28 = params->bb[3];
  t31 = params->bb[4];
  t34 = 0.10e1 * params->bb[0] + 0.10e1 * t22 * t4 + 0.10e1 * t25 * t8 + 0.10e1 * t28 * t12 + 0.10e1 * t31 * t16;
  t35 = 0.1e1 / t34;
  *f = t19 * t35;

  if(order < 1) return;

  t38 = t4 * x;
  t41 = t8 * x;
  t44 = t8 * t38;
  t47 = 0.20e1 * t3 * x + 0.40e1 * t7 * t38 + 0.60e1 * t11 * t41 + 0.80e1 * t15 * t44;
  t49 = t34 * t34;
  t50 = 0.1e1 / t49;
  t51 = t19 * t50;
  t60 = 0.20e1 * t22 * x + 0.40e1 * t25 * t38 + 0.60e1 * t28 * t41 + 0.80e1 * t31 * t44;
  *dfdx = t47 * t35 - t51 * t60;

  if(order < 2) return;

  t69 = 0.20e1 * t3 + 0.120e2 * t7 * t4 + 0.300e2 * t11 * t8 + 0.560e2 * t15 * t12;
  t71 = t47 * t50;
  t75 = 0.1e1 / t49 / t34;
  t76 = t19 * t75;
  t77 = t60 * t60;
  t87 = 0.20e1 * t22 + 0.120e2 * t25 * t4 + 0.300e2 * t28 * t8 + 0.560e2 * t31 * t12;
  *d2fdx2 = t69 * t35 - t51 * t87 - 0.2e1 * t71 * t60 + 0.2e1 * t76 * t77;

  if(order < 3) return;

  t105 = t49 * t49;
  *d3fdx3 = (0.240e2 * t7 * x + 0.1200e3 * t11 * t38 + 0.3360e3 * t15 * t41) * t35 - 0.3e1 * t69 * t50 * t60 + 0.6e1 * t47 * t75 * t77 - 0.3e1 * t71 * t87 - 0.6e1 * t19 / t105 * t77 * t60 + 0.6e1 * t76 * t60 * t87 - t51 * (0.240e2 * t25 * x + 0.1200e3 * t28 * t38 + 0.3360e3 * t31 * t41);

  if(order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_k_dk_enhance)

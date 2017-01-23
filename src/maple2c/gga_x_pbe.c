/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/gga_x_pbe.mpl
  Type of functional: work_gga_x
*/

void XC(gga_x_pbe_enhance)
  (const XC(func_type) *p, int order, 
   FLOAT x, FLOAT *f, FLOAT *dfdx, FLOAT *d2fdx2, FLOAT *d3fdx3)
{
  double t1, t4, t9, t10, t12, t17, t18, t24;

  gga_x_pbe_params *params;
 
  assert(p->params != NULL);
  params = (gga_x_pbe_params * )(p->params);

  t1 = x * x;
  t4 = params->kappa + 0.16455307846020557507e-1 * params->mu * t1;
  *f = 0.10e1 + params->kappa * (0.10e1 - params->kappa / t4);

  if(order < 1) return;

  t9 = params->kappa * params->kappa;
  t10 = t4 * t4;
  t12 = t9 / t10;
  *dfdx = 0.32910615692041115014e-1 * t12 * params->mu * x;

  if(order < 2) return;

  t17 = t9 / t10 / t4;
  t18 = params->mu * params->mu;
  *d2fdx2 = -0.21662172504584457594e-2 * t17 * t18 * t1 + 0.32910615692041115014e-1 * t12 * params->mu;

  if(order < 3) return;

  t24 = t10 * t10;
  *d3fdx3 = 0.21387463030592364977e-3 * t9 / t24 * t18 * params->mu * t1 * x - 0.64986517513753372782e-2 * t17 * t18 * x;

  if(order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_x_pbe_enhance)

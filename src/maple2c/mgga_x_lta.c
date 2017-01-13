/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/mgga_x_lta.mpl
  Type of functional: work_mgga_x
*/

static void 
XC(mgga_x_lta_enhance)(const XC(func_type) *pt, XC(mgga_work_x_t) *r)
{
  double t1, t2, t3;


  t1 = pow(r->t, 0.80000000000000000000e0);
  r->f = 0.29716372829129358133e0 * t1;

  if(r->order < 1) return;

  r->dfdrs = 0;
  r->dfdx = 0;
  t2 = pow(r->t, -0.20000000000000000000e0);
  r->dfdt = 0.23773098263303486506e0 * t2;
  r->dfdu = 0;

  if(r->order < 2) return;

  r->d2fdrs2 = 0;
  r->d2fdx2 = 0;
  t3 = pow(r->t, -0.12000000000000000000e1);
  r->d2fdt2 = -0.47546196526606973012e-1 * t3;
  r->d2fdu2 = 0;
  r->d2fdrsx = 0;
  r->d2fdrst = 0;
  r->d2fdrsu = 0;
  r->d2fdxt = 0;
  r->d2fdxu = 0;
  r->d2fdtu = 0;

  if(r->order < 3) return;


}

#define maple2c_order 3
#define maple2c_func  XC(mgga_x_lta_enhance)

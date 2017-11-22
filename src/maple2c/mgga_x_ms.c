/* 
  This file was generated automatically with /nfs/data-012/marques/software/source/libxc/svn/scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ../maple/mgga_x_ms.mpl
  Type of functional: work_mgga_x
*/

static void 
xc_mgga_x_ms_enhance(const xc_func_type *pt, xc_mgga_work_x_t *r)
{
  double t1, t2, t3, t4, t6, t7, t9, t10;
  double t14, t16, t17, t18, t21, t24, t25, t26;
  double t28, t29, t32, t35, t36, t39, t40, t41;
  double t42, t47, t49, t50, t52, t53, t54, t56;
  double t57, t58, t60, t63, t64, t65, t66, t70;
  double t71, t74, t75, t77, t79, t82, t84, t85;
  double t88, t90, t96, t97, t99, t101, t103, t104;
  double t106, t111, t113, t118, t126, t127, t134, t138;
  double t158, t167;

  mgga_x_ms_params *params;
 
  assert(pt->params != NULL);
  params = (mgga_x_ms_params * ) (pt->params);

  t1 = M_CBRT6;
  t2 = 0.31415926535897932385e1 * 0.31415926535897932385e1;
  t3 = POW_1_3(t2);
  t4 = t3 * t3;
  t6 = t1 / t4;
  t7 = r->x * r->x;
  t9 = 0.5e1 / 0.972e3 * t6 * t7;
  t10 = params->kappa + t9;
  t14 = params->kappa * (0.1e1 - params->kappa / t10);
  t16 = r->t - t7 / 0.8e1;
  t17 = t16 * t16;
  t18 = t1 * t1;
  t21 = 0.1e1 / t3 / t2;
  t24 = 0.1e1 - 0.25e2 / 0.81e2 * t17 * t18 * t21;
  t25 = t24 * t24;
  t26 = t25 * t24;
  t28 = t2 * t2;
  t29 = 0.1e1 / t28;
  t32 = t17 * t17;
  t35 = t28 * t28;
  t36 = 0.1e1 / t35;
  t39 = 0.1e1 + 0.250e3 / 0.243e3 * t17 * t16 * t29 + 0.62500e5 / 0.59049e5 * params->b * t32 * t17 * t36;
  t40 = 0.1e1 / t39;
  t41 = t26 * t40;
  t42 = params->kappa + t9 + params->c;
  t47 = params->kappa * (0.1e1 - params->kappa / t42) - t14;
  r->f = t41 * t47 + t14 + 0.1e1;

  if(r->order < 1) return;

  r->dfdrs = 0.0e0;
  t49 = params->kappa * params->kappa;
  t50 = t10 * t10;
  t52 = t49 / t50;
  t53 = t6 * r->x;
  t54 = t52 * t53;
  t56 = t25 * t40;
  t57 = t56 * t47;
  t58 = t16 * t18;
  t60 = t58 * t21 * r->x;
  t63 = t39 * t39;
  t64 = 0.1e1 / t63;
  t65 = t26 * t64;
  t66 = t17 * t29;
  t70 = params->b * t32 * t16;
  t71 = t36 * r->x;
  t74 = -0.125e3 / 0.162e3 * t66 * r->x - 0.31250e5 / 0.19683e5 * t70 * t71;
  t75 = t47 * t74;
  t77 = t42 * t42;
  t79 = t49 / t77;
  t82 = 0.5e1 / 0.486e3 * t79 * t53 - 0.5e1 / 0.486e3 * t54;
  r->dfdx = 0.5e1 / 0.486e3 * t54 + 0.25e2 / 0.54e2 * t57 * t60 - t65 * t75 + t41 * t82;
  t84 = t58 * t21;
  t85 = t57 * t84;
  t88 = t70 * t36;
  t90 = 0.250e3 / 0.81e2 * t66 + 0.125000e6 / 0.19683e5 * t88;
  r->dfdt = -0.50e2 / 0.27e2 * t85 - t65 * t47 * t90;
  r->dfdu = 0.0e0;

  if(r->order < 2) return;

  r->d2fdrs2 = 0.0e0;
  t96 = t18 * t21;
  t97 = t96 * t7;
  t99 = 0.25e2 / 0.118098e6 * t49 / t50 / t10 * t97;
  t101 = 0.5e1 / 0.486e3 * t52 * t6;
  t103 = t24 * t40 * t47;
  t104 = t17 * t1;
  t106 = 0.1e1 / t4 / t28;
  t111 = t25 * t64;
  t113 = t111 * t47 * t16;
  t118 = t56 * t82;
  t126 = t26 / t63 / t39;
  t127 = t74 * t74;
  t134 = t16 * t29;
  t138 = params->b * t32;
  r->d2fdx2 = -t99 + t101 + 0.625e3 / 0.729e3 * t103 * t104 * t106 * t7 - 0.25e2 / 0.27e2 * t113 * t96 * r->x * t74 + 0.25e2 / 0.27e2 * t118 * t60 - 0.25e2 / 0.216e3 * t57 * t97 + 0.25e2 / 0.54e2 * t85 + 0.2e1 * t126 * t47 * t127 - 0.2e1 * t65 * t82 * t74 - t65 * t47 * (0.125e3 / 0.324e3 * t134 * t7 - 0.125e3 / 0.162e3 * t66 + 0.78125e5 / 0.39366e5 * t138 * t36 * t7 - 0.31250e5 / 0.19683e5 * t88) + t41 * (-0.25e2 / 0.118098e6 * t49 / t77 / t42 * t97 + 0.5e1 / 0.486e3 * t79 * t6 + t99 - t101);
  t158 = t111 * t47;
  t167 = t90 * t90;
  r->d2fdt2 = 0.10000e5 / 0.729e3 * t103 * t104 * t106 + 0.100e3 / 0.27e2 * t158 * t58 * t21 * t90 - 0.50e2 / 0.27e2 * t56 * t47 * t18 * t21 + 0.2e1 * t126 * t47 * t167 - t65 * t47 * (0.500e3 / 0.81e2 * t134 + 0.625000e6 / 0.19683e5 * t138 * t36);
  r->d2fdu2 = 0.0e0;
  r->d2fdrsx = 0.0e0;
  r->d2fdrst = 0.0e0;
  r->d2fdrsu = 0.0e0;
  r->d2fdxt = -0.2500e4 / 0.729e3 * t103 * t104 * t106 * r->x - 0.25e2 / 0.54e2 * t113 * t96 * r->x * t90 + 0.25e2 / 0.54e2 * t57 * t96 * r->x + 0.50e2 / 0.27e2 * t158 * t74 * t16 * t96 + 0.2e1 * t126 * t75 * t90 - t65 * t47 * (-0.125e3 / 0.81e2 * t134 * r->x - 0.156250e6 / 0.19683e5 * t138 * t71) - 0.50e2 / 0.27e2 * t118 * t84 - t65 * t82 * t90;
  r->d2fdxu = 0.0e0;
  r->d2fdtu = 0.0e0;

  if(r->order < 3) return;


}

#define maple2c_order 3
#define maple2c_func  xc_mgga_x_ms_enhance

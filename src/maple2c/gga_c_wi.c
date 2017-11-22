/* 
  This file was generated automatically with /nfs/data-012/marques/software/source/libxc/svn/scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ../maple/gga_c_wi.mpl
  Type of functional: work_gga_c
*/

void xc_gga_c_wi_func
  (const xc_func_type *p, xc_gga_work_c_t *r)
{
  double t1, t2, t4, t6, t7, t8, t9, t10;
  double t11, t12, t13, t14, t19, t20, t21, t22;
  double t23, t24, t25, t29, t30, t33, t35, t36;
  double t37, t38, t40, t44, t45, t46, t48, t50;
  double t52, t55, t62, t64, t65, t68, t70, t73;
  double t74, t75, t76, t77, t78, t79, t80, t82;
  double t85, t87, t90, t92, t96, t107, t117, t118;

  gga_c_wi_params *params;

  assert(p->params != NULL);
  params = (gga_c_wi_params * )(p->params);

  t1 = r->xt * r->xt;
  t2 = params->b * t1;
  t4 = exp(-params->k * t1);
  t6 = t2 * t4 + params->a;
  t7 = M_CBRT4;
  t8 = params->d * t7;
  t9 = M_CBRT3;
  t10 = t9 * t9;
  t11 = cbrt(0.31415926535897932385e1);
  t12 = t10 * t11;
  t13 = t1 * r->xt;
  t14 = sqrt(r->xt);
  t19 = 0.1e1 + t8 * t12 * t14 * t13 / 0.3e1;
  t20 = r->rs * t19;
  t21 = params->c + t20;
  t22 = 0.1e1 / t21;
  r->f = t6 * t22;

  if(r->order < 1) return;

  t23 = t21 * t21;
  t24 = 0.1e1 / t23;
  t25 = t6 * t24;
  r->dfdrs = -t25 * t19;
  r->dfdz = 0.0e0;
  t29 = params->b * t13;
  t30 = params->k * t4;
  t33 = 0.2e1 * params->b * r->xt * t4 - 0.2e1 * t29 * t30;
  t35 = r->rs * params->d;
  t36 = t25 * t35;
  t37 = t7 * t10;
  t38 = t14 * t1;
  t40 = t37 * t11 * t38;
  r->dfdxt = t33 * t22 - 0.7e1 / 0.6e1 * t36 * t40;
  r->dfdxs[0] = 0.0e0;
  r->dfdxs[1] = 0.0e0;

  if(r->order < 2) return;

  t44 = 0.1e1 / t23 / t21;
  t45 = t6 * t44;
  t46 = t19 * t19;
  r->d2fdrs2 = 0.2e1 * t45 * t46;
  r->d2fdrsz = 0.0e0;
  t48 = t33 * t24;
  t50 = t45 * t20;
  t52 = t8 * t12 * t38;
  t55 = t25 * params->d;
  r->d2fdrsxt = -t48 * t19 + 0.7e1 / 0.3e1 * t50 * t52 - 0.7e1 / 0.6e1 * t55 * t40;
  r->d2fdrsxs[0] = 0.0e0;
  r->d2fdrsxs[1] = 0.0e0;
  r->d2fdz2 = 0.0e0;
  r->d2fdzxt = 0.0e0;
  r->d2fdzxs[0] = 0.0e0;
  r->d2fdzxs[1] = 0.0e0;
  t62 = t1 * t1;
  t64 = params->k * params->k;
  t65 = t64 * t4;
  t68 = 0.4e1 * params->b * t62 * t65 - 0.10e2 * t2 * t30 + 0.2e1 * params->b * t4;
  t70 = t48 * t35;
  t73 = r->rs * r->rs;
  t74 = params->d * params->d;
  t75 = t73 * t74;
  t76 = t45 * t75;
  t77 = t7 * t7;
  t78 = t77 * t9;
  t79 = t11 * t11;
  t80 = t62 * r->xt;
  t82 = t78 * t79 * t80;
  t85 = t14 * r->xt;
  t87 = t37 * t11 * t85;
  r->d2fdxt2 = t68 * t22 - 0.7e1 / 0.3e1 * t70 * t40 + 0.49e2 / 0.6e1 * t76 * t82 - 0.35e2 / 0.12e2 * t36 * t87;
  r->d2fdxtxs[0] = 0.0e0;
  r->d2fdxtxs[1] = 0.0e0;
  r->d2fdxs2[0] = 0.0e0;
  r->d2fdxs2[1] = 0.0e0;
  r->d2fdxs2[2] = 0.0e0;

  if(r->order < 3) return;

  t90 = t23 * t23;
  t92 = t6 / t90;
  r->d3fdrs3 = -0.6e1 * t92 * t46 * t19;
  r->d3fdrs2z = 0.0e0;
  r->d3fdrsz2 = 0.0e0;
  r->d3fdrszxt = 0.0e0;
  r->d3fdrszxs[0] = 0.0e0;
  r->d3fdrszxs[1] = 0.0e0;
  t96 = t33 * t44;
  r->d3fdrs2xt = 0.2e1 * t96 * t46 - 0.7e1 * t92 * t46 * r->rs * t52 + 0.14e2 / 0.3e1 * t45 * t19 * params->d * t40;
  t107 = t68 * t24;
  t117 = t74 * t77;
  t118 = t9 * t79;
  r->d3fdrsxt2 = -t107 * t19 + 0.14e2 / 0.3e1 * t96 * t20 * t52 - 0.7e1 / 0.3e1 * t48 * params->d * t40 - 0.49e2 / 0.2e1 * t92 * t19 * t73 * t117 * t118 * t80 + 0.49e2 / 0.3e1 * t45 * t117 * t118 * t80 * r->rs + 0.35e2 / 0.6e1 * t50 * t8 * t12 * t85 - 0.35e2 / 0.12e2 * t55 * t87;
  r->d3fdrsxtxs[0] = 0.0e0;
  r->d3fdrsxtxs[1] = 0.0e0;
  r->d3fdrs2xs[0] = 0.0e0;
  r->d3fdrs2xs[1] = 0.0e0;
  r->d3fdrsxs2[0] = 0.0e0;
  r->d3fdrsxs2[1] = 0.0e0;
  r->d3fdrsxs2[2] = 0.0e0;
  r->d3fdz3 = 0.0e0;
  r->d3fdz2xt = 0.0e0;
  r->d3fdzxt2 = 0.0e0;
  r->d3fdzxtxs[0] = 0.0e0;
  r->d3fdzxtxs[1] = 0.0e0;
  r->d3fdz2xs[0] = 0.0e0;
  r->d3fdz2xs[1] = 0.0e0;
  r->d3fdzxs2[0] = 0.0e0;
  r->d3fdzxs2[1] = 0.0e0;
  r->d3fdzxs2[2] = 0.0e0;
  r->d3fdxt3 = (-0.8e1 * params->b * t80 * t64 * params->k * t4 - 0.24e2 * params->b * params->k * r->xt * t4 + 0.36e2 * t29 * t65) * t22 - 0.7e1 / 0.2e1 * t107 * t35 * t40 + 0.49e2 / 0.2e1 * t96 * t75 * t82 - 0.35e2 / 0.4e1 * t70 * t87 - 0.343e3 * t92 * t73 * r->rs * t74 * params->d * 0.31415926535897932385e1 * t14 * t62 * t13 + 0.245e3 / 0.4e1 * t76 * t78 * t79 * t62 - 0.35e2 / 0.8e1 * t36 * t37 * t11 * t14;
  r->d3fdxt2xs[0] = 0.0e0;
  r->d3fdxt2xs[1] = 0.0e0;
  r->d3fdxtxs2[0] = 0.0e0;
  r->d3fdxtxs2[1] = 0.0e0;
  r->d3fdxtxs2[2] = 0.0e0;
  r->d3fdxs3[0] = 0.0e0;
  r->d3fdxs3[1] = 0.0e0;
  r->d3fdxs3[2] = 0.0e0;
  r->d3fdxs3[3] = 0.0e0;

  if(r->order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  xc_gga_c_wi_func

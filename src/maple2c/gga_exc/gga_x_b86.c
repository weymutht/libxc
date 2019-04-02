/* 
  This file was generated automatically with ./scripts/maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : .//maple/gga_x_b86.mpl
  Type of functional: gga_exc
*/

#define maple2c_order 3

static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, const double *sigma, double *zk, double *vrho, double *vsigma, double *v2rho2, double *v2rhosigma, double *v2sigma2, double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
  double t1, t3, t5, t6, t7, t8, t9, t10;
  double t11, t12, t13, t14, t16, t17, t20, t21;
  double t22, t25, t27, t32, t33, t34, t36, t41;
  double t42, t43, t46, t49, t50, t52, t55, t59;
  double t62, t64, t70, t73, t74, t82, t89, t95;
  double t96, t97, t98, t99, t100, t102, t103, t104;
  double t105, t106, t109, t112, t117, t123, t128, t132;
  double t133, t139, t144, t145, t150, t177, t179, t184;
  double t190, t192, t196, t197, t201, t205, t226, t227;
  double t228, t232, t240, t257, t258, t268, t280, t290;

  gga_x_b86_params *params;

  assert(p->params != NULL);
  params = (gga_x_b86_params * )(p->params);

  t1 = M_CBRT3;
  t3 = POW_1_3(0.1e1 / M_PI);
  t5 = M_CBRT4;
  t6 = t5 * t5;
  t7 = t1 * t3 * t6;
  t8 = M_CBRT2;
  t9 = t8 * t8;
  t10 = POW_1_3(rho[0]);
  t11 = t9 * t10;
  t12 = params->beta * sigma[0];
  t13 = rho[0] * rho[0];
  t14 = t10 * t10;
  t16 = 0.1e1 / t14 / t13;
  t17 = t9 * t16;
  t20 = params->gamma * sigma[0] * t17 + 0.1e1;
  t21 = pow(t20, params->omega);
  t22 = 0.1e1 / t21;
  t25 = t12 * t17 * t22 + 0.1e1;
  t27 = t7 * t11 * t25;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.16e2 * t27;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t32 = t10 * rho[0] * t1 * t3;
  t33 = t6 * t9;
  t34 = t13 * rho[0];
  t36 = 0.1e1 / t14 / t34;
  t41 = sigma[0] * sigma[0];
  t42 = params->beta * t41;
  t43 = t13 * t13;
  t46 = 0.1e1 / t10 / t43 / t13;
  t49 = t22 * params->omega;
  t50 = 0.1e1 / t20;
  t52 = t49 * params->gamma * t50;
  t55 = -0.8e1 / 0.3e1 * t12 * t9 * t36 * t22 + 0.16e2 / 0.3e1 * t42 * t8 * t46 * t52;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t27 / 0.4e1 - 0.3e1 / 0.16e2 * t32 * t33 * t55;

  t59 = params->beta * t9;
  t62 = t43 * rho[0];
  t64 = 0.1e1 / t10 / t62;
  t70 = t33 * (-0.2e1 * t12 * t8 * t64 * t52 + t59 * t16 * t22);
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.3e1 / 0.16e2 * t32 * t70;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t73 = 0.1e1 / t14;
  t74 = t9 * t73;
  t82 = 0.1e1 / t14 / t43;
  t89 = 0.1e1 / t10 / t43 / t34;
  t95 = params->beta * t41 * sigma[0];
  t96 = t43 * t43;
  t97 = t96 * t13;
  t98 = 0.1e1 / t97;
  t99 = t95 * t98;
  t100 = params->omega * params->omega;
  t102 = params->gamma * params->gamma;
  t103 = t20 * t20;
  t104 = 0.1e1 / t103;
  t105 = t102 * t104;
  t106 = t22 * t100 * t105;
  t109 = t49 * t105;
  t112 = 0.88e2 / 0.9e1 * t12 * t9 * t82 * t22 - 0.48e2 * t42 * t8 * t89 * t52 + 0.256e3 / 0.9e1 * t99 * t106 + 0.256e3 / 0.9e1 * t99 * t109;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t7 * t74 * t25 / 0.12e2 - t7 * t11 * t55 / 0.2e1 - 0.3e1 / 0.16e2 * t32 * t33 * t112;

  t117 = t10 * t1 * t3;
  t123 = params->beta * t8;
  t128 = params->omega * params->gamma * sigma[0] * t50;
  t132 = 0.1e1 / t96 / rho[0];
  t133 = t42 * t132;
  t139 = t33 * (-0.8e1 / 0.3e1 * t59 * t36 * t22 + 0.16e2 * t123 * t46 * t22 * t128 - 0.32e2 / 0.3e1 * t133 * t106 - 0.32e2 / 0.3e1 * t133 * t109);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -t117 * t70 / 0.4e1 - 0.3e1 / 0.16e2 * t32 * t139;

  t144 = 0.1e1 / t96;
  t145 = t12 * t144;
  t150 = t33 * (-0.4e1 * t123 * t64 * t52 + 0.4e1 * t145 * t106 + 0.4e1 * t145 * t109);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = -0.3e1 / 0.16e2 * t32 * t150;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t177 = t96 * t34;
  t179 = t95 / t177;
  t184 = t41 * t41;
  t190 = params->beta * t184 / t14 / t96 / t62 * t22;
  t192 = t102 * params->gamma;
  t196 = 0.1e1 / t103 / t20 * t9;
  t197 = t100 * params->omega * t192 * t196;
  t201 = t100 * t192 * t196;
  t205 = params->omega * t192 * t196;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t7 * t9 / t14 / rho[0] * t25 / 0.18e2 - t7 * t74 * t55 / 0.4e1 - 0.3e1 / 0.4e1 * t7 * t11 * t112 - 0.3e1 / 0.16e2 * t32 * t33 * (-0.1232e4 / 0.27e2 * t12 * t9 / t14 / t62 * t22 + 0.10912e5 / 0.27e2 * t42 * t8 / t10 / t96 * t52 - 0.4864e4 / 0.9e1 * t179 * t106 - 0.4864e4 / 0.9e1 * t179 * t109 + 0.2048e4 / 0.27e2 * t190 * t197 + 0.2048e4 / 0.9e1 * t190 * t201 + 0.4096e4 / 0.27e2 * t190 * t205);

  t226 = params->beta * t98 * t22;
  t227 = t100 * t102;
  t228 = t41 * t104;
  t232 = params->omega * t102;
  t240 = t95 / t14 / t96 / t43 * t22;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -t73 * t1 * t3 * t70 / 0.12e2 - t117 * t139 / 0.2e1 - 0.3e1 / 0.16e2 * t32 * t33 * (0.88e2 / 0.9e1 * t59 * t82 * t22 - 0.1040e4 / 0.9e1 * t123 * t89 * t22 * t128 + 0.544e3 / 0.3e1 * t226 * t227 * t228 + 0.544e3 / 0.3e1 * t226 * t232 * t228 - 0.256e3 / 0.9e1 * t240 * t197 - 0.256e3 / 0.3e1 * t240 * t201 - 0.512e3 / 0.9e1 * t240 * t205);

  t257 = params->beta * t132 * t22;
  t258 = t104 * sigma[0];
  t268 = t42 / t14 / t177 * t22;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -t117 * t150 / 0.4e1 - 0.3e1 / 0.16e2 * t32 * t33 * (0.64e2 / 0.3e1 * t123 * t46 * t52 - 0.160e3 / 0.3e1 * t257 * t227 * t258 - 0.160e3 / 0.3e1 * t257 * t232 * t258 + 0.32e2 / 0.3e1 * t268 * t197 + 0.32e2 * t268 * t201 + 0.64e2 / 0.3e1 * t268 * t205);

  t280 = params->beta * t144 * t22;
  t290 = t12 / t14 / t97 * t22;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.3e1 / 0.16e2 * t32 * t33 * (0.12e2 * t280 * t227 * t104 + 0.12e2 * t280 * t232 * t104 - 0.4e1 * t290 * t197 - 0.12e2 * t290 * t201 - 0.8e1 * t290 * t205);

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


static inline void
func_ferr(const xc_func_type *p, int order, const double *rho, const double *sigma, double *zk, double *vrho, double *vsigma, double *v2rho2, double *v2rhosigma, double *v2sigma2, double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
  double t1, t3, t4, t5, t6, t7, t8, t9;
  double t10, t11, t13, t16, t17, t18, t21, t23;
  double t27, t28, t29, t31, t34, t35, t36, t39;
  double t41, t42, t44, t47, t53, t55, t59, t62;
  double t63, t70, t76, t81, t82, t83, t84, t85;
  double t86, t87, t88, t89, t90, t91, t92, t95;
  double t98, t102, t109, t110, t112, t116, t117, t123;
  double t128, t131, t132, t136, t161, t163, t168, t173;
  double t179, t180, t183, t186, t205, t206, t207, t211;
  double t218, t234, t235, t244, t256, t265;

  gga_x_b86_params *params;

  assert(p->params != NULL);
  params = (gga_x_b86_params * )(p->params);

  t1 = M_CBRT3;
  t3 = POW_1_3(0.1e1 / M_PI);
  t4 = t1 * t3;
  t5 = M_CBRT4;
  t6 = t5 * t5;
  t7 = POW_1_3(rho[0]);
  t8 = t6 * t7;
  t9 = params->beta * sigma[0];
  t10 = rho[0] * rho[0];
  t11 = t7 * t7;
  t13 = 0.1e1 / t11 / t10;
  t16 = params->gamma * sigma[0] * t13 + 0.1e1;
  t17 = pow(t16, params->omega);
  t18 = 0.1e1 / t17;
  t21 = t9 * t13 * t18 + 0.1e1;
  t23 = t4 * t8 * t21;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.8e1 * t23;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t27 = t7 * rho[0] * t1;
  t28 = t3 * t6;
  t29 = t10 * rho[0];
  t31 = 0.1e1 / t11 / t29;
  t34 = sigma[0] * sigma[0];
  t35 = params->beta * t34;
  t36 = t10 * t10;
  t39 = 0.1e1 / t7 / t36 / t10;
  t41 = t18 * params->omega;
  t42 = 0.1e1 / t16;
  t44 = t41 * params->gamma * t42;
  t47 = -0.8e1 / 0.3e1 * t9 * t31 * t18 + 0.8e1 / 0.3e1 * t35 * t39 * t44;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t23 / 0.2e1 - 0.3e1 / 0.8e1 * t27 * t28 * t47;

  t53 = t36 * rho[0];
  t55 = 0.1e1 / t7 / t53;
  t59 = t28 * (params->beta * t13 * t18 - t9 * t55 * t44);
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.3e1 / 0.8e1 * t27 * t59;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t62 = 0.1e1 / t11;
  t63 = t6 * t62;
  t70 = 0.1e1 / t11 / t36;
  t76 = 0.1e1 / t7 / t36 / t29;
  t81 = params->beta * t34 * sigma[0];
  t82 = t36 * t36;
  t83 = t82 * t10;
  t84 = 0.1e1 / t83;
  t85 = t81 * t84;
  t86 = params->omega * params->omega;
  t87 = t18 * t86;
  t88 = params->gamma * params->gamma;
  t89 = t16 * t16;
  t90 = 0.1e1 / t89;
  t91 = t88 * t90;
  t92 = t87 * t91;
  t95 = t41 * t91;
  t98 = 0.88e2 / 0.9e1 * t9 * t70 * t18 - 0.24e2 * t35 * t76 * t44 + 0.64e2 / 0.9e1 * t85 * t92 + 0.64e2 / 0.9e1 * t85 * t95;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t4 * t63 * t21 / 0.6e1 - t4 * t8 * t47 - 0.3e1 / 0.8e1 * t27 * t28 * t98;

  t102 = t7 * t1;
  t109 = params->beta * t39 * t18;
  t110 = params->omega * params->gamma;
  t112 = t110 * sigma[0] * t42;
  t116 = 0.1e1 / t82 / rho[0];
  t117 = t35 * t116;
  t123 = t28 * (-0.8e1 / 0.3e1 * params->beta * t31 * t18 + 0.8e1 * t109 * t112 - 0.8e1 / 0.3e1 * t117 * t92 - 0.8e1 / 0.3e1 * t117 * t95);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -t102 * t59 / 0.2e1 - 0.3e1 / 0.8e1 * t27 * t123;

  t128 = t110 * t42;
  t131 = 0.1e1 / t82;
  t132 = t9 * t131;
  t136 = t28 * (-0.2e1 * params->beta * t55 * t18 * t128 + t132 * t92 + t132 * t95);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = -0.3e1 / 0.8e1 * t27 * t136;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t161 = t82 * t29;
  t163 = t81 / t161;
  t168 = t34 * t34;
  t173 = params->beta * t168 / t11 / t82 / t53;
  t179 = t88 * params->gamma / t89 / t16;
  t180 = t18 * t86 * params->omega * t179;
  t183 = t87 * t179;
  t186 = t41 * t179;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t4 * t6 / t11 / rho[0] * t21 / 0.9e1 - t4 * t63 * t47 / 0.2e1 - 0.3e1 / 0.2e1 * t4 * t8 * t98 - 0.3e1 / 0.8e1 * t27 * t28 * (-0.1232e4 / 0.27e2 * t9 / t11 / t53 * t18 + 0.5456e4 / 0.27e2 * t35 / t7 / t82 * t44 - 0.1216e4 / 0.9e1 * t163 * t92 - 0.1216e4 / 0.9e1 * t163 * t95 + 0.512e3 / 0.27e2 * t173 * t180 + 0.512e3 / 0.9e1 * t173 * t183 + 0.1024e4 / 0.27e2 * t173 * t186);

  t205 = params->beta * t84 * t18;
  t206 = t86 * t88;
  t207 = t34 * t90;
  t211 = params->omega * t88;
  t218 = t81 / t11 / t82 / t36;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -t62 * t1 * t59 / 0.6e1 - t102 * t123 - 0.3e1 / 0.8e1 * t27 * t28 * (0.88e2 / 0.9e1 * params->beta * t70 * t18 - 0.520e3 / 0.9e1 * params->beta * t76 * t18 * t112 + 0.136e3 / 0.3e1 * t205 * t206 * t207 + 0.136e3 / 0.3e1 * t205 * t211 * t207 - 0.64e2 / 0.9e1 * t218 * t180 - 0.64e2 / 0.3e1 * t218 * t183 - 0.128e3 / 0.9e1 * t218 * t186);

  t234 = params->beta * t116 * t18;
  t235 = t90 * sigma[0];
  t244 = t35 / t11 / t161;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -t102 * t136 / 0.2e1 - 0.3e1 / 0.8e1 * t27 * t28 * (0.32e2 / 0.3e1 * t109 * t128 - 0.40e2 / 0.3e1 * t234 * t206 * t235 - 0.40e2 / 0.3e1 * t234 * t211 * t235 + 0.8e1 / 0.3e1 * t244 * t180 + 0.8e1 * t244 * t183 + 0.16e2 / 0.3e1 * t244 * t186);

  t256 = params->beta * t131 * t18;
  t265 = t9 / t11 / t83;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.3e1 / 0.8e1 * t27 * t28 * (0.3e1 * t256 * t206 * t90 + 0.3e1 * t256 * t211 * t90 - t265 * t180 - 0.3e1 * t265 * t183 - 0.2e1 * t265 * t186);

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


static inline void
func_pol(const xc_func_type *p, int order, const double *rho, const double *sigma, double *zk, double *vrho, double *vsigma, double *v2rho2, double *v2rhosigma, double *v2sigma2, double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
  double t1, t3, t4, t5, t6, t7, t8, t9;
  double t10, t11, t13, t14, t15, t16, t17, t18;
  double t19, t20, t21, t23, t26, t27, t28, t31;
  double t33, t35, t36, t37, t38, t39, t40, t41;
  double t42, t44, t47, t48, t49, t52, t54, t56;
  double t57, t58, t59, t60, t61, t63, t64, t66;
  double t67, t68, t69, t70, t72, t73, t74, t76;
  double t79, t80, t81, t84, t86, t87, t89, t92;
  double t94, t95, t96, t97, t98, t100, t101, t102;
  double t104, t105, t109, t110, t112, t113, t114, t115;
  double t117, t118, t119, t121, t124, t125, t126, t129;
  double t131, t132, t134, t137, t139, t140, t144, t145;
  double t146, t149, t151, t154, t158, t161, t163, t166;
  double t170, t172, t173, t174, t175, t176, t177, t179;
  double t180, t181, t183, t184, t185, t187, t188, t189;
  double t190, t191, t192, t194, t195, t197, t198, t200;
  double t201, t203, t204, t206, t212, t217, t218, t219;
  double t220, t221, t222, t223, t224, t225, t226, t227;
  double t228, t231, t234, t236, t237, t238, t239, t240;
  double t241, t242, t244, t245, t246, t248, t249, t250;
  double t251, t253, t254, t255, t257, t258, t259, t261;
  double t262, t263, t264, t266, t269, t271, t273, t276;
  double t277, t278, t280, t284, t285, t286, t287, t289;
  double t292, t294, t295, t297, t300, t302, t305, t307;
  double t310, t311, t313, t314, t315, t316, t317, t319;
  double t320, t321, t322, t324, t325, t326, t327, t329;
  double t330, t331, t333, t334, t335, t337, t343, t348;
  double t349, t350, t351, t352, t353, t354, t355, t356;
  double t357, t360, t363, t365, t366, t367, t370, t372;
  double t373, t381, t382, t384, t388, t389, t394, t399;
  double t400, t401, t406, t411, t418, t420, t424, t425;
  double t430, t431, t436, t439, t440, t443, t444, t449;
  double t452, t453, t456, t457, t465, t467, t474, t476;
  double t486, t488, t490, t498, t500, t510, t513, t516;
  double t528, t530, t535, t540, t541, t543, t546, t547;
  double t550, t553, t561, t562, t568, t570, t576, t578;
  double t581, t582, t588, t590, t596, t598, t600, t606;
  double t607, t618, t629, t634, t636, t639, t646, t650;
  double t656, t664, t666, t674, t675, t681, t689, t702;
  double t707, t710, t746, t751, t764, t782, t785, t788;
  double t791, t794, t796, t799, t810, t842, t844, t849;
  double t854, t858, t859, t862, t865, t897, t901, t905;
  double t907, t927, t928, t929, t933, t940, t952, t956;
  double t968, t969, t972, t982, t988, t998, t1033, t1034;
  double t1044, t1055, t1064, t1065, t1074, t1085, t1102, t1103;
  double t1112, t1124, t1133, t1144, t1153;

  gga_x_b86_params *params;

  assert(p->params != NULL);
  params = (gga_x_b86_params * )(p->params);

  t1 = M_CBRT3;
  t3 = POW_1_3(0.1e1 / M_PI);
  t4 = t1 * t3;
  t5 = M_CBRT4;
  t6 = t5 * t5;
  t7 = t4 * t6;
  t8 = rho[0] - rho[1];
  t9 = rho[0] + rho[1];
  t10 = 0.1e1 / t9;
  t11 = t8 * t10;
  t13 = 0.1e1 / 0.2e1 + t11 / 0.2e1;
  t14 = POW_1_3(t13);
  t15 = t14 * t13;
  t16 = POW_1_3(t9);
  t17 = t15 * t16;
  t18 = params->beta * sigma[0];
  t19 = rho[0] * rho[0];
  t20 = POW_1_3(rho[0]);
  t21 = t20 * t20;
  t23 = 0.1e1 / t21 / t19;
  t26 = params->gamma * sigma[0] * t23 + 0.1e1;
  t27 = pow(t26, params->omega);
  t28 = 0.1e1 / t27;
  t31 = t18 * t23 * t28 + 0.1e1;
  t33 = t7 * t17 * t31;
  t35 = 0.1e1 / 0.2e1 - t11 / 0.2e1;
  t36 = POW_1_3(t35);
  t37 = t36 * t35;
  t38 = t37 * t16;
  t39 = params->beta * sigma[2];
  t40 = rho[1] * rho[1];
  t41 = POW_1_3(rho[1]);
  t42 = t41 * t41;
  t44 = 0.1e1 / t42 / t40;
  t47 = params->gamma * sigma[2] * t44 + 0.1e1;
  t48 = pow(t47, params->omega);
  t49 = 0.1e1 / t48;
  t52 = t39 * t44 * t49 + 0.1e1;
  t54 = t7 * t38 * t52;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.8e1 * t33 - 0.3e1 / 0.8e1 * t54;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t56 = 0.3e1 / 0.8e1 * t33;
  t57 = 0.3e1 / 0.8e1 * t54;
  t58 = t14 * t16;
  t59 = t9 * t9;
  t60 = 0.1e1 / t59;
  t61 = t8 * t60;
  t63 = t10 / 0.2e1 - t61 / 0.2e1;
  t64 = t31 * t63;
  t66 = t7 * t58 * t64;
  t67 = t66 / 0.2e1;
  t68 = t16 * t16;
  t69 = 0.1e1 / t68;
  t70 = t15 * t69;
  t72 = t7 * t70 * t31;
  t73 = t72 / 0.8e1;
  t74 = t19 * rho[0];
  t76 = 0.1e1 / t21 / t74;
  t79 = sigma[0] * sigma[0];
  t80 = params->beta * t79;
  t81 = t19 * t19;
  t84 = 0.1e1 / t20 / t81 / t19;
  t86 = t28 * params->omega;
  t87 = 0.1e1 / t26;
  t89 = t86 * params->gamma * t87;
  t92 = -0.8e1 / 0.3e1 * t18 * t76 * t28 + 0.8e1 / 0.3e1 * t80 * t84 * t89;
  t94 = t7 * t17 * t92;
  t95 = 0.3e1 / 0.8e1 * t94;
  t96 = t36 * t16;
  t97 = -t63;
  t98 = t52 * t97;
  t100 = t7 * t96 * t98;
  t101 = t100 / 0.2e1;
  t102 = t37 * t69;
  t104 = t7 * t102 * t52;
  t105 = t104 / 0.8e1;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t56 - t57 + t9 * (-t67 - t73 - t95 - t101 - t105);

  t109 = -t10 / 0.2e1 - t61 / 0.2e1;
  t110 = t31 * t109;
  t112 = t7 * t58 * t110;
  t113 = t112 / 0.2e1;
  t114 = -t109;
  t115 = t52 * t114;
  t117 = t7 * t96 * t115;
  t118 = t117 / 0.2e1;
  t119 = t40 * rho[1];
  t121 = 0.1e1 / t42 / t119;
  t124 = sigma[2] * sigma[2];
  t125 = params->beta * t124;
  t126 = t40 * t40;
  t129 = 0.1e1 / t41 / t126 / t40;
  t131 = t49 * params->omega;
  t132 = 0.1e1 / t47;
  t134 = t131 * params->gamma * t132;
  t137 = -0.8e1 / 0.3e1 * t39 * t121 * t49 + 0.8e1 / 0.3e1 * t125 * t129 * t134;
  t139 = t7 * t38 * t137;
  t140 = 0.3e1 / 0.8e1 * t139;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = -t56 - t57 + t9 * (-t113 - t73 - t118 - t105 - t140);

  t144 = t16 * t9 * t1;
  t145 = t144 * t3;
  t146 = t6 * t15;
  t149 = t81 * rho[0];
  t151 = 0.1e1 / t20 / t149;
  t154 = -t18 * t151 * t89 + params->beta * t23 * t28;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.3e1 / 0.8e1 * t145 * t146 * t154;

  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[1] = 0.0e0;

  t158 = t6 * t37;
  t161 = t126 * rho[1];
  t163 = 0.1e1 / t41 / t161;
  t166 = -t39 * t163 * t134 + params->beta * t44 * t49;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[2] = -0.3e1 / 0.8e1 * t145 * t158 * t166;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t170 = t72 / 0.4e1;
  t172 = t104 / 0.4e1;
  t173 = t14 * t14;
  t174 = 0.1e1 / t173;
  t175 = t174 * t16;
  t176 = t63 * t63;
  t177 = t31 * t176;
  t179 = t7 * t175 * t177;
  t180 = t179 / 0.6e1;
  t181 = t14 * t69;
  t183 = t7 * t181 * t64;
  t184 = t183 / 0.3e1;
  t185 = t92 * t63;
  t187 = t7 * t58 * t185;
  t188 = t59 * t9;
  t189 = 0.1e1 / t188;
  t190 = t8 * t189;
  t191 = -t60 + t190;
  t192 = t31 * t191;
  t194 = t7 * t58 * t192;
  t195 = t194 / 0.2e1;
  t197 = 0.1e1 / t68 / t9;
  t198 = t15 * t197;
  t200 = t7 * t198 * t31;
  t201 = t200 / 0.12e2;
  t203 = t7 * t70 * t92;
  t204 = t203 / 0.4e1;
  t206 = 0.1e1 / t21 / t81;
  t212 = 0.1e1 / t20 / t81 / t74;
  t217 = params->beta * t79 * sigma[0];
  t218 = t81 * t81;
  t219 = t218 * t19;
  t220 = 0.1e1 / t219;
  t221 = t217 * t220;
  t222 = params->omega * params->omega;
  t223 = t28 * t222;
  t224 = params->gamma * params->gamma;
  t225 = t26 * t26;
  t226 = 0.1e1 / t225;
  t227 = t224 * t226;
  t228 = t223 * t227;
  t231 = t86 * t227;
  t234 = 0.88e2 / 0.9e1 * t18 * t206 * t28 - 0.24e2 * t80 * t212 * t89 + 0.64e2 / 0.9e1 * t221 * t228 + 0.64e2 / 0.9e1 * t221 * t231;
  t236 = t7 * t17 * t234;
  t237 = 0.3e1 / 0.8e1 * t236;
  t238 = t36 * t36;
  t239 = 0.1e1 / t238;
  t240 = t239 * t16;
  t241 = t97 * t97;
  t242 = t52 * t241;
  t244 = t7 * t240 * t242;
  t245 = t244 / 0.6e1;
  t246 = t36 * t69;
  t248 = t7 * t246 * t98;
  t249 = t248 / 0.3e1;
  t250 = -t191;
  t251 = t52 * t250;
  t253 = t7 * t96 * t251;
  t254 = t253 / 0.2e1;
  t255 = t37 * t197;
  t257 = t7 * t255 * t52;
  t258 = t257 / 0.12e2;
  t259 = -t180 - t184 - t187 - t195 + t201 - t204 - t237 - t245 - t249 - t254 + t258;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t66 - t170 - 0.3e1 / 0.4e1 * t94 - t100 - t172 + t9 * t259;

  t261 = t6 * t174;
  t262 = t4 * t261;
  t263 = t16 * t31;
  t264 = t109 * t63;
  t266 = t262 * t263 * t264;
  t269 = t7 * t181 * t110;
  t271 = t92 * t109;
  t273 = t7 * t58 * t271;
  t276 = 0.1e1 / t68 / t59;
  t277 = t14 * t276;
  t278 = t31 * t8;
  t280 = t7 * t277 * t278;
  t284 = t6 * t239;
  t285 = t4 * t284;
  t286 = t16 * t52;
  t287 = t114 * t97;
  t289 = t285 * t286 * t287;
  t292 = t7 * t246 * t115;
  t294 = t36 * t276;
  t295 = t52 * t8;
  t297 = t7 * t294 * t295;
  t300 = t137 * t97;
  t302 = t7 * t96 * t300;
  t305 = t7 * t102 * t137;
  t307 = -t266 / 0.6e1 - t269 / 0.6e1 - t273 / 0.2e1 - t280 / 0.2e1 - t183 / 0.6e1 + t201 - t203 / 0.8e1 - t289 / 0.6e1 - t292 / 0.6e1 + t297 / 0.2e1 - t248 / 0.6e1 + t258 - t302 / 0.2e1 - t305 / 0.8e1;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = t9 * t307 - t101 - t113 - t118 - t140 - t170 - t172 - t67 - t95;

  t310 = t109 * t109;
  t311 = t31 * t310;
  t313 = t7 * t175 * t311;
  t314 = t313 / 0.6e1;
  t315 = t269 / 0.3e1;
  t316 = t60 + t190;
  t317 = t31 * t316;
  t319 = t7 * t58 * t317;
  t320 = t319 / 0.2e1;
  t321 = t114 * t114;
  t322 = t52 * t321;
  t324 = t7 * t240 * t322;
  t325 = t324 / 0.6e1;
  t326 = t292 / 0.3e1;
  t327 = t137 * t114;
  t329 = t7 * t96 * t327;
  t330 = -t316;
  t331 = t52 * t330;
  t333 = t7 * t96 * t331;
  t334 = t333 / 0.2e1;
  t335 = t305 / 0.4e1;
  t337 = 0.1e1 / t42 / t126;
  t343 = 0.1e1 / t41 / t126 / t119;
  t348 = params->beta * t124 * sigma[2];
  t349 = t126 * t126;
  t350 = t349 * t40;
  t351 = 0.1e1 / t350;
  t352 = t348 * t351;
  t353 = t49 * t222;
  t354 = t47 * t47;
  t355 = 0.1e1 / t354;
  t356 = t224 * t355;
  t357 = t353 * t356;
  t360 = t131 * t356;
  t363 = 0.88e2 / 0.9e1 * t39 * t337 * t49 - 0.24e2 * t125 * t343 * t134 + 0.64e2 / 0.9e1 * t352 * t357 + 0.64e2 / 0.9e1 * t352 * t360;
  t365 = t7 * t38 * t363;
  t366 = 0.3e1 / 0.8e1 * t365;
  t367 = -t314 - t315 - t320 + t201 - t325 - t326 - t329 - t334 + t258 - t335 - t366;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = -t112 - t170 - t117 - t172 - 0.3e1 / 0.4e1 * t139 + t9 * t367;

  t370 = t7 * t17 * t154;
  t372 = t6 * t14;
  t373 = t154 * t63;
  t381 = params->beta * t84 * t28;
  t382 = params->omega * params->gamma;
  t384 = t382 * sigma[0] * t87;
  t388 = 0.1e1 / t218 / rho[0];
  t389 = t80 * t388;
  t394 = -0.8e1 / 0.3e1 * params->beta * t76 * t28 + 0.8e1 * t381 * t384 - 0.8e1 / 0.3e1 * t389 * t228 - 0.8e1 / 0.3e1 * t389 * t231;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -t370 / 0.2e1 - t145 * t372 * t373 / 0.2e1 - 0.3e1 / 0.8e1 * t145 * t146 * t394;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[1] = 0.0e0;

  t399 = t7 * t38 * t166;
  t400 = t6 * t36;
  t401 = t166 * t97;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[2] = -t145 * t400 * t401 / 0.2e1 - t399 / 0.2e1;

  t406 = t372 * t154 * t109;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[3] = -t145 * t406 / 0.2e1 - t370 / 0.2e1;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[4] = 0.0e0;

  t411 = t400 * t166 * t114;
  t418 = params->beta * t129 * t49;
  t420 = t382 * sigma[2] * t132;
  t424 = 0.1e1 / t349 / rho[1];
  t425 = t125 * t424;
  t430 = -0.8e1 / 0.3e1 * params->beta * t121 * t49 + 0.8e1 * t418 * t420 - 0.8e1 / 0.3e1 * t425 * t357 - 0.8e1 / 0.3e1 * t425 * t360;
  t431 = t158 * t430;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[5] = -t399 / 0.2e1 - t145 * t411 / 0.2e1 - 0.3e1 / 0.8e1 * t145 * t431;

  t436 = t382 * t87;
  t439 = 0.1e1 / t218;
  t440 = t18 * t439;
  t443 = -0.2e1 * params->beta * t151 * t28 * t436 + t440 * t228 + t440 * t231;
  t444 = t146 * t443;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = -0.3e1 / 0.8e1 * t145 * t444;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[1] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[2] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[3] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[4] = 0.0e0;

  t449 = t382 * t132;
  t452 = 0.1e1 / t349;
  t453 = t39 * t452;
  t456 = -0.2e1 * params->beta * t163 * t49 * t449 + t453 * t357 + t453 * t360;
  t457 = t158 * t456;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[5] = -0.3e1 / 0.8e1 * t145 * t457;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t465 = t200 / 0.4e1;
  t467 = t257 / 0.4e1;
  t474 = t7 * t181 * t185;
  t476 = t7 * t181 * t192;
  t486 = t59 * t59;
  t488 = t8 / t486;
  t490 = 0.3e1 * t189 - 0.3e1 * t488;
  t498 = 0.5e1 / 0.36e2 * t7 * t15 * t276 * t31;
  t500 = t7 * t246 * t251;
  t510 = 0.5e1 / 0.36e2 * t7 * t37 * t276 * t52;
  t513 = t7 * t198 * t92;
  t516 = t7 * t70 * t234;
  t528 = t218 * t74;
  t530 = t217 / t528;
  t535 = t79 * t79;
  t540 = params->beta * t535 / t21 / t218 / t149;
  t541 = t222 * params->omega;
  t543 = t224 * params->gamma;
  t546 = t543 / t225 / t26;
  t547 = t28 * t541 * t546;
  t550 = t223 * t546;
  t553 = t86 * t546;
  t561 = 0.1e1 / t173 / t13;
  t562 = t561 * t16;
  t568 = t174 * t69;
  t570 = t7 * t568 * t177;
  t576 = t14 * t197;
  t578 = t7 * t576 * t64;
  t581 = 0.1e1 / t238 / t35;
  t582 = t581 * t16;
  t588 = t239 * t69;
  t590 = t7 * t588 * t242;
  t596 = t36 * t197;
  t598 = t7 * t596 * t98;
  t600 = t513 / 0.4e1 - 0.3e1 / 0.8e1 * t516 - 0.3e1 / 0.8e1 * t7 * t17 * (-0.1232e4 / 0.27e2 * t18 / t21 / t149 * t28 + 0.5456e4 / 0.27e2 * t80 / t20 / t218 * t89 - 0.1216e4 / 0.9e1 * t530 * t228 - 0.1216e4 / 0.9e1 * t530 * t231 + 0.512e3 / 0.27e2 * t540 * t547 + 0.512e3 / 0.9e1 * t540 * t550 + 0.1024e4 / 0.27e2 * t540 * t553) + t7 * t562 * t31 * t176 * t63 / 0.9e1 - t570 / 0.6e1 - t262 * t263 * t63 * t191 / 0.2e1 + t578 / 0.3e1 + t7 * t582 * t52 * t241 * t97 / 0.9e1 - t590 / 0.6e1 - t285 * t286 * t97 * t250 / 0.2e1 + t598 / 0.3e1;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.3e1 / 0.4e1 * t203 - t179 / 0.2e1 - t183 - t244 / 0.2e1 - t248 - 0.3e1 * t187 - 0.3e1 / 0.2e1 * t194 + t465 - 0.3e1 / 0.2e1 * t253 + t467 - 0.9e1 / 0.8e1 * t236 + t9 * (-t7 * t175 * t92 * t176 / 0.2e1 - t474 - t476 / 0.2e1 - 0.3e1 / 0.2e1 * t7 * t58 * t234 * t63 - 0.3e1 / 0.2e1 * t7 * t58 * t92 * t191 - t7 * t58 * t31 * t490 / 0.2e1 - t498 - t500 / 0.2e1 + t7 * t96 * t52 * t490 / 0.2e1 - t510 + t600);

  t606 = t266 / 0.3e1;
  t607 = t289 / 0.3e1;
  t618 = t7 * t255 * t137;
  t629 = t7 * t181 * t271 / 0.3e1;
  t634 = -t498 - t510 + t513 / 0.6e1 - t516 / 0.8e1 - t7 * t277 * t31 / 0.2e1 + t7 * t294 * t52 / 0.2e1 + t618 / 0.12e2 - t474 / 0.3e1 - t476 / 0.6e1 - t500 / 0.6e1 - t570 / 0.18e2 + 0.2e1 / 0.9e1 * t578 - t590 / 0.18e2 + 0.2e1 / 0.9e1 * t598 - t629 - t7 * t58 * t234 * t109 / 0.2e1;
  t636 = 0.1e1 / t68 / t188;
  t639 = t7 * t36 * t636 * t295;
  t646 = t7 * t576 * t110;
  t650 = t7 * t14 * t636 * t278;
  t656 = t7 * t596 * t115;
  t664 = t7 * t246 * t300 / 0.3e1;
  t666 = t4 * t6 * t561;
  t674 = t262 * t69 * t31 * t264 / 0.9e1;
  t675 = t276 * t31;
  t681 = t4 * t6 * t581;
  t689 = t285 * t69 * t52 * t287 / 0.9e1;
  t702 = t276 * t52;
  t707 = -0.7e1 / 0.6e1 * t639 - t7 * t96 * t137 * t250 / 0.2e1 + t646 / 0.9e1 + 0.7e1 / 0.6e1 * t650 - t7 * t277 * t92 * t8 + t656 / 0.9e1 - t7 * t240 * t137 * t241 / 0.6e1 - t664 + t666 * t263 * t109 * t176 / 0.9e1 - t674 - t262 * t675 * t8 * t63 / 0.3e1 + t681 * t286 * t114 * t241 / 0.9e1 - t689 - t262 * t16 * t92 * t264 / 0.3e1 - t262 * t263 * t109 * t191 / 0.6e1 - t285 * t286 * t114 * t250 / 0.6e1 + t285 * t702 * t8 * t97 / 0.3e1;
  t710 = -t187 - t195 + t465 - t254 + t467 - t273 + t297 - t302 - t335 - t237 + t9 * (t634 + t707);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = -t203 / 0.2e1 - t180 - 0.2e1 / 0.3e1 * t183 - t245 - 0.2e1 / 0.3e1 * t248 - t606 - t315 - t280 - t607 - t326 + t710;

  t746 = t7 * t102 * t363;
  t751 = -t262 * t675 * t109 * t8 / 0.3e1 + t666 * t263 * t310 * t63 / 0.9e1 - t262 * t263 * t316 * t63 / 0.6e1 + t681 * t286 * t321 * t97 / 0.9e1 + t285 * t702 * t114 * t8 / 0.3e1 - t285 * t16 * t137 * t287 / 0.3e1 - t285 * t286 * t330 * t97 / 0.6e1 - t498 - t510 + t513 / 0.12e2 + t618 / 0.6e1 - t746 / 0.8e1 + t578 / 0.9e1 + t598 / 0.9e1 - t629 + t639 / 0.3e1;
  t764 = -t189 - 0.3e1 * t488;
  t782 = t7 * t568 * t311;
  t785 = t7 * t181 * t317;
  t788 = t7 * t588 * t322;
  t791 = t7 * t246 * t327;
  t794 = t7 * t246 * t331;
  t796 = 0.2e1 / 0.9e1 * t646 - t650 / 0.3e1 + 0.2e1 / 0.9e1 * t656 - t664 - t7 * t175 * t92 * t310 / 0.6e1 - t7 * t58 * t92 * t316 / 0.2e1 - t7 * t58 * t31 * t764 / 0.2e1 + t7 * t294 * t137 * t8 + t7 * t96 * t52 * t764 / 0.2e1 - t7 * t96 * t363 * t97 / 0.2e1 - t782 / 0.18e2 - t785 / 0.6e1 - t788 / 0.18e2 - t791 / 0.3e1 - t794 / 0.6e1 - t674 - t689;
  t799 = -t273 + t297 - t302 - t305 / 0.2e1 - t320 - t329 - t334 - t366 - t314 - t325 + t9 * (t751 + t796);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = -t204 - t184 - t249 - t606 - 0.2e1 / 0.3e1 * t269 - t280 - t607 - 0.2e1 / 0.3e1 * t292 + t465 + t467 + t799;

  t810 = -0.3e1 * t189 - 0.3e1 * t488;
  t842 = t349 * t119;
  t844 = t348 / t842;
  t849 = t124 * t124;
  t854 = params->beta * t849 / t42 / t349 / t161;
  t858 = t543 / t354 / t47;
  t859 = t49 * t541 * t858;
  t862 = t353 * t858;
  t865 = t131 * t858;
  t897 = t646 / 0.3e1 + t656 / 0.3e1 - t782 / 0.6e1 - t785 / 0.2e1 - t788 / 0.6e1 - t791 - t794 / 0.2e1 + t7 * t562 * t31 * t310 * t109 / 0.9e1 - t262 * t263 * t109 * t316 / 0.2e1 + t7 * t582 * t52 * t321 * t114 / 0.9e1 - t285 * t286 * t114 * t330 / 0.2e1;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = -t269 - t292 + t465 + t467 - 0.3e1 / 0.4e1 * t305 - 0.3e1 / 0.2e1 * t319 - 0.3e1 * t329 - 0.3e1 / 0.2e1 * t333 - 0.9e1 / 0.8e1 * t365 - t313 / 0.2e1 - t324 / 0.2e1 + t9 * (-t498 - t510 + t618 / 0.4e1 - 0.3e1 / 0.8e1 * t746 - t7 * t58 * t31 * t810 / 0.2e1 - t7 * t240 * t137 * t321 / 0.2e1 - 0.3e1 / 0.2e1 * t7 * t96 * t363 * t114 - 0.3e1 / 0.2e1 * t7 * t96 * t137 * t330 + t7 * t96 * t52 * t810 / 0.2e1 - 0.3e1 / 0.8e1 * t7 * t38 * (-0.1232e4 / 0.27e2 * t39 / t42 / t161 * t49 + 0.5456e4 / 0.27e2 * t125 / t41 / t349 * t134 - 0.1216e4 / 0.9e1 * t844 * t357 - 0.1216e4 / 0.9e1 * t844 * t360 + 0.512e3 / 0.27e2 * t854 * t859 + 0.512e3 / 0.9e1 * t854 * t862 + 0.1024e4 / 0.27e2 * t854 * t865) + t897);

  t901 = t7 * t58 * t373;
  t905 = t7 * t70 * t154 / 0.6e1;
  t907 = t7 * t17 * t394;
  t927 = params->beta * t220 * t28;
  t928 = t222 * t224;
  t929 = t79 * t226;
  t933 = params->omega * t224;
  t940 = t217 / t21 / t218 / t81;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -0.4e1 / 0.3e1 * t901 - t905 - t907 - t145 * t261 * t154 * t176 / 0.6e1 - t145 * t372 * t394 * t63 - t145 * t372 * t154 * t191 / 0.2e1 - 0.3e1 / 0.8e1 * t145 * t146 * (0.88e2 / 0.9e1 * params->beta * t206 * t28 - 0.520e3 / 0.9e1 * params->beta * t212 * t28 * t384 + 0.136e3 / 0.3e1 * t927 * t928 * t929 + 0.136e3 / 0.3e1 * t927 * t933 * t929 - 0.64e2 / 0.9e1 * t940 * t547 - 0.64e2 / 0.3e1 * t940 * t550 - 0.128e3 / 0.9e1 * t940 * t553);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[1] = 0.0e0;

  t952 = t7 * t96 * t401;
  t956 = t7 * t102 * t166 / 0.6e1;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[2] = -0.4e1 / 0.3e1 * t952 - t956 - t145 * t284 * t166 * t241 / 0.6e1 - t145 * t400 * t166 * t250 / 0.2e1;

  t968 = t16 * t1 * t3;
  t969 = t968 * t406;
  t972 = t144 * t3 * t6;
  t982 = t197 * t1 * t3;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[3] = -0.2e1 / 0.3e1 * t901 - t905 - t907 / 0.2e1 - 0.2e1 / 0.3e1 * t969 - t972 * t174 * t154 * t264 / 0.6e1 - t145 * t372 * t394 * t109 / 0.2e1 - t982 * t372 * t154 * t8 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[4] = 0.0e0;

  t988 = t968 * t411;
  t998 = t968 * t431;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[5] = -0.2e1 / 0.3e1 * t952 - t956 - 0.2e1 / 0.3e1 * t988 - t972 * t239 * t166 * t287 / 0.6e1 + t982 * t400 * t166 * t8 / 0.2e1 - t998 / 0.2e1 - t145 * t400 * t430 * t97 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[6] = -0.4e1 / 0.3e1 * t969 - t905 - t145 * t261 * t154 * t310 / 0.6e1 - t145 * t372 * t154 * t316 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[7] = 0.0e0;

  t1033 = params->beta * t351 * t49;
  t1034 = t124 * t355;
  t1044 = t348 / t42 / t349 / t126;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[8] = -0.4e1 / 0.3e1 * t988 - t956 - t998 - t145 * t284 * t166 * t321 / 0.6e1 - t145 * t400 * t430 * t114 - t145 * t400 * t166 * t330 / 0.2e1 - 0.3e1 / 0.8e1 * t145 * t158 * (0.88e2 / 0.9e1 * params->beta * t337 * t49 - 0.520e3 / 0.9e1 * params->beta * t343 * t49 * t420 + 0.136e3 / 0.3e1 * t1033 * t928 * t1034 + 0.136e3 / 0.3e1 * t1033 * t933 * t1034 - 0.64e2 / 0.9e1 * t1044 * t859 - 0.64e2 / 0.3e1 * t1044 * t862 - 0.128e3 / 0.9e1 * t1044 * t865);

  t1055 = t968 * t444;
  t1064 = params->beta * t388 * t28;
  t1065 = t226 * sigma[0];
  t1074 = t80 / t21 / t528;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -t1055 / 0.2e1 - t145 * t372 * t443 * t63 / 0.2e1 - 0.3e1 / 0.8e1 * t145 * t146 * (0.32e2 / 0.3e1 * t381 * t436 - 0.40e2 / 0.3e1 * t1064 * t928 * t1065 - 0.40e2 / 0.3e1 * t1064 * t933 * t1065 + 0.8e1 / 0.3e1 * t1074 * t547 + 0.8e1 * t1074 * t550 + 0.16e2 / 0.3e1 * t1074 * t553);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[1] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[2] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[3] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[4] = 0.0e0;

  t1085 = t968 * t457;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[5] = -t145 * t400 * t456 * t97 / 0.2e1 - t1085 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[6] = -t145 * t372 * t443 * t109 / 0.2e1 - t1055 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[7] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[8] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[9] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[10] = 0.0e0;

  t1102 = params->beta * t424 * t49;
  t1103 = t355 * sigma[2];
  t1112 = t125 / t42 / t842;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[11] = -t1085 / 0.2e1 - t145 * t400 * t456 * t114 / 0.2e1 - 0.3e1 / 0.8e1 * t145 * t158 * (0.32e2 / 0.3e1 * t418 * t449 - 0.40e2 / 0.3e1 * t1102 * t928 * t1103 - 0.40e2 / 0.3e1 * t1102 * t933 * t1103 + 0.8e1 / 0.3e1 * t1112 * t859 + 0.8e1 * t1112 * t862 + 0.16e2 / 0.3e1 * t1112 * t865);

  t1124 = params->beta * t439 * t28;
  t1133 = t18 / t21 / t219;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.3e1 / 0.8e1 * t145 * t146 * (0.3e1 * t1124 * t928 * t226 + 0.3e1 * t1124 * t933 * t226 - t1133 * t547 - 0.3e1 * t1133 * t550 - 0.2e1 * t1133 * t553);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[1] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[2] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[3] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[4] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[5] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[6] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[7] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[8] = 0.0e0;

  t1144 = params->beta * t452 * t49;
  t1153 = t39 / t42 / t350;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[9] = -0.3e1 / 0.8e1 * t145 * t158 * (0.3e1 * t1144 * t928 * t355 + 0.3e1 * t1144 * t933 * t355 - t1153 * t859 - 0.3e1 * t1153 * t862 - 0.2e1 * t1153 * t865);

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


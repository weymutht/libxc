/* 
  This file was generated automatically with ./scripts/maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : .//maple/gga_x_2d_b86_mgc.mpl
  Type of functional: gga_exc
*/

#define maple2c_order 3

static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, const double *sigma, double *zk, double *vrho, double *vsigma, double *v2rho2, double *v2rhosigma, double *v2sigma2, double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
  double t1, t2, t3, t4, t5, t6, t7, t9;
  double t11, t12, t13, t14, t15, t16, t17, t19;
  double t20, t21, t22, t23, t27, t29, t32, t33;
  double t34, t35, t40, t41, t42, t45, t49, t57;
  double t58, t59, t64, t67, t73, t74, t79, t80;
  double t85, t87, t89, t91, t95, t99, t111, t117;
  double t125, t131, t152, t157, t163;


  t1 = sqrt(M_PI);
  t2 = 0.1e1 / t1;
  t3 = M_SQRT2;
  t4 = t2 * t3;
  t5 = sqrt(rho[0]);
  t6 = M_CBRT3;
  t7 = t6 * t6;
  t9 = POW_1_3(0.1e1 / M_PI);
  t11 = t7 / t9;
  t12 = M_CBRT4;
  t13 = t11 * t12;
  t14 = rho[0] * rho[0];
  t15 = t14 * rho[0];
  t16 = 0.1e1 / t15;
  t17 = sigma[0] * t16;
  t19 = 0.1e1 + 0.16646e-1 * t17;
  t20 = POW_1_4(t19);
  t21 = t20 * t20;
  t22 = t21 * t20;
  t23 = 0.1e1 / t22;
  t27 = 0.1e1 + 0.14742222222222222222e-2 * t13 * t17 * t23;
  t29 = t4 * t5 * t27;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.4e1 / 0.3e1 * t29;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t32 = t5 * rho[0];
  t33 = t32 * t2;
  t34 = t14 * t14;
  t35 = 0.1e1 / t34;
  t40 = sigma[0] * sigma[0];
  t41 = t34 * t15;
  t42 = 0.1e1 / t41;
  t45 = 0.1e1 / t22 / t19;
  t49 = -0.44226666666666666666e-2 * t13 * sigma[0] * t35 * t23 + 0.55214781999999999999e-4 * t13 * t40 * t42 * t45;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -0.2e1 * t29 - 0.4e1 / 0.3e1 * t33 * t3 * t49;

  t57 = t34 * t14;
  t58 = 0.1e1 / t57;
  t59 = sigma[0] * t58;
  t64 = t3 * (0.14742222222222222222e-2 * t11 * t12 * t16 * t23 - 0.18404927333333333333e-4 * t13 * t59 * t45);
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.4e1 / 0.3e1 * t33 * t64;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t67 = 0.1e1 / t5;
  t73 = t34 * rho[0];
  t74 = 0.1e1 / t73;
  t79 = t34 * t34;
  t80 = 0.1e1 / t79;
  t85 = t40 * sigma[0];
  t87 = 0.1e1 / t79 / t15;
  t89 = t19 * t19;
  t91 = 0.1e1 / t22 / t89;
  t95 = 0.17690666666666666666e-1 * t13 * sigma[0] * t74 * t23 - 0.55214781999999999999e-3 * t13 * t40 * t80 * t45 + 0.48253026211529999999e-5 * t13 * t85 * t87 * t91;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t4 * t67 * t27 - 0.4e1 * t4 * t5 * t49 - 0.4e1 / 0.3e1 * t33 * t3 * t95;

  t99 = t5 * t2;
  t111 = 0.1e1 / t79 / t14;
  t117 = t3 * (-0.44226666666666666666e-2 * t11 * t12 * t35 * t23 + 0.16564434600000000000e-3 * t13 * t42 * t45 * sigma[0] - 0.16084342070510000000e-5 * t13 * t40 * t111 * t91);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -0.2e1 * t99 * t64 - 0.4e1 / 0.3e1 * t33 * t117;

  t125 = 0.1e1 / t79 / rho[0];
  t131 = t3 * (-0.36809854666666666666e-4 * t11 * t12 * t58 * t45 + 0.53614473568366666666e-6 * t13 * sigma[0] * t125 * t91);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = -0.4e1 / 0.3e1 * t33 * t131;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t152 = 0.1e1 / t79 / t34;
  t157 = t40 * t40;
  t163 = 0.1e1 / t22 / t89 / t19;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t4 / t32 * t27 / 0.2e1 - 0.3e1 * t4 * t67 * t49 - 0.6e1 * t4 * t5 * t95 - 0.4e1 / 0.3e1 * t33 * t3 * (-0.88453333333333333330e-1 * t13 * t59 * t23 + 0.50797599439999999999e-2 * t13 * t40 * t125 * t45 - 0.10133135504421300000e-3 * t13 * t85 * t152 * t91 + 0.66265639631163091349e-6 * t13 * t157 / t79 / t41 * t163);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -t67 * t2 * t64 - 0.4e1 * t99 * t117 - 0.4e1 / 0.3e1 * t33 * t3 * (0.17690666666666666666e-1 * t11 * t12 * t74 * t23 - 0.13251547680000000000e-2 * t13 * t80 * t45 * sigma[0] + 0.30560249933969000000e-4 * t13 * t87 * t91 * t40 - 0.22088546543721030450e-6 * t13 * t85 / t79 / t57 * t163);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -0.2e1 * t99 * t131 - 0.4e1 / 0.3e1 * t33 * t3 * (0.22085912800000000000e-3 * t11 * t12 * t42 * t45 - 0.80421710352549999998e-5 * t13 * t111 * t91 * sigma[0] + 0.73628488479070101499e-7 * t13 * t40 / t79 / t73 * t163);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.4e1 / 0.3e1 * t33 * t3 * (0.16084342070510000000e-5 * t11 * t12 * t125 * t91 - 0.24542829493023367166e-7 * t13 * sigma[0] * t152 * t163);

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
  double t1, t2, t3, t4, t5, t6, t8, t10;
  double t11, t12, t13, t14, t15, t16, t18, t19;
  double t20, t21, t22, t26, t27, t30, t31, t32;
  double t33, t38, t39, t40, t43, t47, t54, t55;
  double t56, t60, t64, t69, t70, t75, t76, t81;
  double t83, t85, t87, t91, t105, t110, t118, t123;
  double t141, t146, t152;


  t1 = sqrt(M_PI);
  t2 = 0.1e1 / t1;
  t3 = sqrt(rho[0]);
  t4 = t2 * t3;
  t5 = M_CBRT3;
  t6 = t5 * t5;
  t8 = POW_1_3(0.1e1 / M_PI);
  t10 = t6 / t8;
  t11 = M_CBRT4;
  t12 = t10 * t11;
  t13 = rho[0] * rho[0];
  t14 = t13 * rho[0];
  t15 = 0.1e1 / t14;
  t16 = sigma[0] * t15;
  t18 = 0.1e1 + 0.8323e-2 * t16;
  t19 = POW_1_4(t18);
  t20 = t19 * t19;
  t21 = t20 * t19;
  t22 = 0.1e1 / t21;
  t26 = 0.1e1 + 0.73711111111111111110e-3 * t12 * t16 * t22;
  t27 = t4 * t26;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.8e1 / 0.3e1 * t27;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t30 = t3 * rho[0];
  t31 = t30 * t2;
  t32 = t13 * t13;
  t33 = 0.1e1 / t32;
  t38 = sigma[0] * sigma[0];
  t39 = t32 * t14;
  t40 = 0.1e1 / t39;
  t43 = 0.1e1 / t21 / t18;
  t47 = -0.22113333333333333333e-2 * t12 * sigma[0] * t33 * t22 + 0.13803695500000000000e-4 * t12 * t38 * t40 * t43;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -0.4e1 * t27 - 0.8e1 / 0.3e1 * t31 * t47;

  t54 = t32 * t13;
  t55 = 0.1e1 / t54;
  t56 = sigma[0] * t55;
  t60 = 0.73711111111111111110e-3 * t10 * t11 * t15 * t22 - 0.46012318333333333333e-5 * t12 * t56 * t43;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.8e1 / 0.3e1 * t31 * t60;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t64 = t2 / t3;
  t69 = t32 * rho[0];
  t70 = 0.1e1 / t69;
  t75 = t32 * t32;
  t76 = 0.1e1 / t75;
  t81 = t38 * sigma[0];
  t83 = 0.1e1 / t75 / t14;
  t85 = t18 * t18;
  t87 = 0.1e1 / t21 / t85;
  t91 = 0.88453333333333333332e-2 * t12 * sigma[0] * t70 * t22 - 0.13803695500000000000e-3 * t12 * t38 * t76 * t43 + 0.60316282764412500000e-6 * t12 * t81 * t83 * t87;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.2e1 * t64 * t26 - 0.8e1 * t4 * t47 - 0.8e1 / 0.3e1 * t31 * t91;

  t105 = 0.1e1 / t75 / t13;
  t110 = -0.22113333333333333333e-2 * t10 * t11 * t33 * t22 + 0.41411086500000000000e-4 * t12 * t40 * t43 * sigma[0] - 0.20105427588137500000e-6 * t12 * t38 * t105 * t87;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -0.4e1 * t4 * t60 - 0.8e1 / 0.3e1 * t31 * t110;

  t118 = 0.1e1 / t75 / rho[0];
  t123 = -0.92024636666666666666e-5 * t10 * t11 * t55 * t43 + 0.67018091960458333333e-7 * t12 * sigma[0] * t118 * t87;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = -0.8e1 / 0.3e1 * t31 * t123;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t141 = 0.1e1 / t75 / t32;
  t146 = t38 * t38;
  t152 = 0.1e1 / t21 / t85 / t18;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t2 / t30 * t26 - 0.6e1 * t64 * t47 - 0.12e2 * t4 * t91 - 0.8e1 / 0.3e1 * t31 * (-0.44226666666666666666e-1 * t12 * t56 * t22 + 0.12699399860000000000e-2 * t12 * t38 * t118 * t43 - 0.12666419380526625000e-4 * t12 * t81 * t141 * t87 + 0.41416024769476932094e-7 * t12 * t146 / t75 / t39 * t152);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -0.2e1 * t64 * t60 - 0.8e1 * t4 * t110 - 0.8e1 / 0.3e1 * t31 * (0.88453333333333333332e-2 * t10 * t11 * t70 * t22 - 0.33128869200000000000e-3 * t12 * t76 * t43 * sigma[0] + 0.38200312417461250000e-5 * t12 * t83 * t87 * t38 - 0.13805341589825644031e-7 * t12 * t81 / t75 / t54 * t152);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -0.4e1 * t4 * t123 - 0.8e1 / 0.3e1 * t31 * (0.55214782000000000000e-4 * t10 * t11 * t40 * t43 - 0.10052713794068750000e-5 * t12 * t105 * t87 * sigma[0] + 0.46017805299418813437e-8 * t12 * t38 / t75 / t69 * t152);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.8e1 / 0.3e1 * t31 * (0.20105427588137500000e-6 * t10 * t11 * t118 * t87 - 0.15339268433139604479e-8 * t12 * sigma[0] * t141 * t152);

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
  double t1, t2, t3, t4, t5, t6, t8, t9;
  double t10, t11, t12, t13, t14, t16, t18, t19;
  double t20, t21, t22, t23, t24, t26, t27, t28;
  double t29, t30, t34, t35, t36, t38, t39, t40;
  double t41, t42, t43, t44, t45, t47, t48, t49;
  double t50, t51, t55, t56, t57, t59, t60, t61;
  double t62, t63, t64, t66, t68, t69, t70, t71;
  double t72, t73, t74, t75, t80, t81, t82, t85;
  double t89, t90, t91, t92, t93, t94, t96, t97;
  double t98, t99, t100, t104, t106, t107, t108, t110;
  double t111, t112, t113, t118, t119, t120, t123, t127;
  double t128, t129, t130, t133, t134, t139, t140, t141;
  double t145, t153, t154, t155, t159, t164, t167, t168;
  double t169, t170, t172, t173, t175, t176, t178, t179;
  double t180, t181, t182, t183, t185, t186, t187, t188;
  double t189, t190, t191, t192, t193, t194, t195, t200;
  double t201, t206, t208, t210, t212, t216, t217, t218;
  double t219, t220, t221, t222, t224, t225, t227, t228;
  double t229, t231, t232, t233, t234, t235, t236, t238;
  double t239, t240, t241, t244, t247, t250, t251, t253;
  double t257, t258, t259, t260, t263, t265, t267, t271;
  double t273, t274, t276, t281, t283, t284, t285, t286;
  double t288, t289, t290, t292, t293, t294, t296, t297;
  double t298, t300, t301, t302, t303, t304, t309, t310;
  double t315, t317, t319, t321, t325, t326, t327, t328;
  double t329, t331, t332, t334, t347, t352, t356, t357;
  double t358, t362, t366, t378, t383, t384, t392, t397;
  double t398, t406, t411, t412, t417, t419, t430, t433;
  double t441, t443, t445, t449, t451, t457, t460, t463;
  double t473, t478, t484, t493, t498, t505, t508, t513;
  double t520, t522, t525, t526, t527, t532, t533, t534;
  double t542, t544, t549, t550, t555, t560, t571, t576;
  double t583, t585, t588, t595, t601, t604, t610, t615;
  double t618, t626, t652, t658, t660, t663, t665, t668;
  double t677, t692, t695, t713, t718, t724, t755, t772;
  double t776, t780, t782, t784, t788, t818, t822, t823;
  double t832, t833, t843, t848, t858, t860, t904, t906;
  double t928, t929;


  t1 = sqrt(M_PI);
  t2 = 0.1e1 / t1;
  t3 = rho[0] - rho[1];
  t4 = rho[0] + rho[1];
  t5 = 0.1e1 / t4;
  t6 = t3 * t5;
  t8 = 0.1e1 / 0.2e1 + t6 / 0.2e1;
  t9 = sqrt(t8);
  t10 = t9 * t8;
  t11 = t2 * t10;
  t12 = sqrt(t4);
  t13 = M_CBRT3;
  t14 = t13 * t13;
  t16 = POW_1_3(0.1e1 / M_PI);
  t18 = t14 / t16;
  t19 = M_CBRT4;
  t20 = t18 * t19;
  t21 = rho[0] * rho[0];
  t22 = t21 * rho[0];
  t23 = 0.1e1 / t22;
  t24 = sigma[0] * t23;
  t26 = 0.1e1 + 0.8323e-2 * t24;
  t27 = POW_1_4(t26);
  t28 = t27 * t27;
  t29 = t28 * t27;
  t30 = 0.1e1 / t29;
  t34 = 0.1e1 + 0.73711111111111111110e-3 * t20 * t24 * t30;
  t35 = t12 * t34;
  t36 = t11 * t35;
  t38 = 0.1e1 / 0.2e1 - t6 / 0.2e1;
  t39 = sqrt(t38);
  t40 = t39 * t38;
  t41 = t2 * t40;
  t42 = rho[1] * rho[1];
  t43 = t42 * rho[1];
  t44 = 0.1e1 / t43;
  t45 = sigma[2] * t44;
  t47 = 0.1e1 + 0.8323e-2 * t45;
  t48 = POW_1_4(t47);
  t49 = t48 * t48;
  t50 = t49 * t48;
  t51 = 0.1e1 / t50;
  t55 = 0.1e1 + 0.73711111111111111110e-3 * t20 * t45 * t51;
  t56 = t12 * t55;
  t57 = t41 * t56;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.8e1 / 0.3e1 * t36 - 0.8e1 / 0.3e1 * t57;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t59 = 0.8e1 / 0.3e1 * t36;
  t60 = 0.8e1 / 0.3e1 * t57;
  t61 = t2 * t9;
  t62 = t4 * t4;
  t63 = 0.1e1 / t62;
  t64 = t3 * t63;
  t66 = t5 / 0.2e1 - t64 / 0.2e1;
  t68 = t61 * t35 * t66;
  t69 = 0.4e1 * t68;
  t70 = 0.1e1 / t12;
  t71 = t70 * t34;
  t72 = t11 * t71;
  t73 = 0.4e1 / 0.3e1 * t72;
  t74 = t21 * t21;
  t75 = 0.1e1 / t74;
  t80 = sigma[0] * sigma[0];
  t81 = t74 * t22;
  t82 = 0.1e1 / t81;
  t85 = 0.1e1 / t29 / t26;
  t89 = -0.22113333333333333333e-2 * t20 * sigma[0] * t75 * t30 + 0.13803695500000000000e-4 * t20 * t80 * t82 * t85;
  t90 = t12 * t89;
  t91 = t11 * t90;
  t92 = 0.8e1 / 0.3e1 * t91;
  t93 = t2 * t39;
  t94 = -t66;
  t96 = t93 * t56 * t94;
  t97 = 0.4e1 * t96;
  t98 = t70 * t55;
  t99 = t41 * t98;
  t100 = 0.4e1 / 0.3e1 * t99;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t59 - t60 + t4 * (-t69 - t73 - t92 - t97 - t100);

  t104 = -t5 / 0.2e1 - t64 / 0.2e1;
  t106 = t61 * t35 * t104;
  t107 = 0.4e1 * t106;
  t108 = -t104;
  t110 = t93 * t56 * t108;
  t111 = 0.4e1 * t110;
  t112 = t42 * t42;
  t113 = 0.1e1 / t112;
  t118 = sigma[2] * sigma[2];
  t119 = t112 * t43;
  t120 = 0.1e1 / t119;
  t123 = 0.1e1 / t50 / t47;
  t127 = -0.22113333333333333333e-2 * t20 * sigma[2] * t113 * t51 + 0.13803695500000000000e-4 * t20 * t118 * t120 * t123;
  t128 = t12 * t127;
  t129 = t41 * t128;
  t130 = 0.8e1 / 0.3e1 * t129;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = -t59 - t60 + t4 * (-t107 - t73 - t111 - t100 - t130);

  t133 = t12 * t4;
  t134 = t133 * t2;
  t139 = t74 * t21;
  t140 = 0.1e1 / t139;
  t141 = sigma[0] * t140;
  t145 = 0.73711111111111111110e-3 * t18 * t19 * t23 * t30 - 0.46012318333333333333e-5 * t20 * t141 * t85;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.8e1 / 0.3e1 * t134 * t10 * t145;

  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[1] = 0.0e0;

  t153 = t112 * t42;
  t154 = 0.1e1 / t153;
  t155 = sigma[2] * t154;
  t159 = 0.73711111111111111110e-3 * t18 * t19 * t44 * t51 - 0.46012318333333333333e-5 * t20 * t155 * t123;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[2] = -0.8e1 / 0.3e1 * t134 * t40 * t159;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t164 = 0.8e1 / 0.3e1 * t72;
  t167 = 0.8e1 / 0.3e1 * t99;
  t168 = 0.1e1 / t9;
  t169 = t2 * t168;
  t170 = t66 * t66;
  t172 = t169 * t35 * t170;
  t173 = 0.2e1 * t172;
  t175 = t61 * t71 * t66;
  t176 = 0.4e1 * t175;
  t178 = t61 * t90 * t66;
  t179 = 0.8e1 * t178;
  t180 = t62 * t4;
  t181 = 0.1e1 / t180;
  t182 = t3 * t181;
  t183 = -t63 + t182;
  t185 = t61 * t35 * t183;
  t186 = 0.4e1 * t185;
  t187 = 0.1e1 / t133;
  t188 = t187 * t34;
  t189 = t11 * t188;
  t190 = 0.2e1 / 0.3e1 * t189;
  t191 = t70 * t89;
  t192 = t11 * t191;
  t193 = 0.8e1 / 0.3e1 * t192;
  t194 = t74 * rho[0];
  t195 = 0.1e1 / t194;
  t200 = t74 * t74;
  t201 = 0.1e1 / t200;
  t206 = t80 * sigma[0];
  t208 = 0.1e1 / t200 / t22;
  t210 = t26 * t26;
  t212 = 0.1e1 / t29 / t210;
  t216 = 0.88453333333333333332e-2 * t20 * sigma[0] * t195 * t30 - 0.13803695500000000000e-3 * t20 * t80 * t201 * t85 + 0.60316282764412500000e-6 * t20 * t206 * t208 * t212;
  t217 = t12 * t216;
  t218 = t11 * t217;
  t219 = 0.8e1 / 0.3e1 * t218;
  t220 = 0.1e1 / t39;
  t221 = t2 * t220;
  t222 = t94 * t94;
  t224 = t221 * t56 * t222;
  t225 = 0.2e1 * t224;
  t227 = t93 * t98 * t94;
  t228 = 0.4e1 * t227;
  t229 = -t183;
  t231 = t93 * t56 * t229;
  t232 = 0.4e1 * t231;
  t233 = t187 * t55;
  t234 = t41 * t233;
  t235 = 0.2e1 / 0.3e1 * t234;
  t236 = -t173 - t176 - t179 - t186 + t190 - t193 - t219 - t225 - t228 - t232 + t235;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.8e1 * t68 - t164 - 0.16e2 / 0.3e1 * t91 - 0.8e1 * t96 - t167 + t4 * t236;

  t238 = t169 * t12;
  t239 = t34 * t104;
  t240 = t239 * t66;
  t241 = t238 * t240;
  t244 = t61 * t71 * t104;
  t247 = t61 * t90 * t104;
  t250 = 0.1e1 / t12 / t62;
  t251 = t250 * t34;
  t253 = t61 * t251 * t3;
  t257 = t221 * t12;
  t258 = t55 * t108;
  t259 = t258 * t94;
  t260 = t257 * t259;
  t263 = t93 * t98 * t108;
  t265 = t250 * t55;
  t267 = t93 * t265 * t3;
  t271 = t93 * t128 * t94;
  t273 = t70 * t127;
  t274 = t41 * t273;
  t276 = -0.2e1 * t241 - 0.2e1 * t244 - 0.4e1 * t247 - 0.4e1 * t253 - 0.2e1 * t175 + t190 - 0.4e1 / 0.3e1 * t192 - 0.2e1 * t260 - 0.2e1 * t263 + 0.4e1 * t267 - 0.2e1 * t227 + t235 - 0.4e1 * t271 - 0.4e1 / 0.3e1 * t274;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = t4 * t276 - t107 - t111 - t130 - t164 - t167 - t69 - t92 - t97;

  t281 = t104 * t104;
  t283 = t169 * t35 * t281;
  t284 = 0.2e1 * t283;
  t285 = 0.4e1 * t244;
  t286 = t63 + t182;
  t288 = t61 * t35 * t286;
  t289 = 0.4e1 * t288;
  t290 = t108 * t108;
  t292 = t221 * t56 * t290;
  t293 = 0.2e1 * t292;
  t294 = 0.4e1 * t263;
  t296 = t93 * t128 * t108;
  t297 = 0.8e1 * t296;
  t298 = -t286;
  t300 = t93 * t56 * t298;
  t301 = 0.4e1 * t300;
  t302 = 0.8e1 / 0.3e1 * t274;
  t303 = t112 * rho[1];
  t304 = 0.1e1 / t303;
  t309 = t112 * t112;
  t310 = 0.1e1 / t309;
  t315 = t118 * sigma[2];
  t317 = 0.1e1 / t309 / t43;
  t319 = t47 * t47;
  t321 = 0.1e1 / t50 / t319;
  t325 = 0.88453333333333333332e-2 * t20 * sigma[2] * t304 * t51 - 0.13803695500000000000e-3 * t20 * t118 * t310 * t123 + 0.60316282764412500000e-6 * t20 * t315 * t317 * t321;
  t326 = t12 * t325;
  t327 = t41 * t326;
  t328 = 0.8e1 / 0.3e1 * t327;
  t329 = -t284 - t285 - t289 + t190 - t293 - t294 - t297 - t301 + t235 - t302 - t328;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = -0.8e1 * t106 - t164 - 0.8e1 * t110 - t167 - 0.16e2 / 0.3e1 * t129 + t4 * t329;

  t331 = t12 * t145;
  t332 = t11 * t331;
  t334 = t9 * t145;
  t347 = 0.1e1 / t200 / t21;
  t352 = -0.22113333333333333333e-2 * t18 * t19 * t75 * t30 + 0.41411086500000000000e-4 * t20 * t82 * t85 * sigma[0] - 0.20105427588137500000e-6 * t20 * t80 * t347 * t212;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -0.4e1 * t332 - 0.4e1 * t134 * t334 * t66 - 0.8e1 / 0.3e1 * t134 * t10 * t352;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[1] = 0.0e0;

  t356 = t12 * t159;
  t357 = t41 * t356;
  t358 = t39 * t159;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[2] = -0.4e1 * t134 * t358 * t94 - 0.4e1 * t357;

  t362 = t334 * t104;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[3] = -0.4e1 * t134 * t362 - 0.4e1 * t332;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[4] = 0.0e0;

  t366 = t358 * t108;
  t378 = 0.1e1 / t309 / t42;
  t383 = -0.22113333333333333333e-2 * t18 * t19 * t113 * t51 + 0.41411086500000000000e-4 * t20 * t120 * t123 * sigma[2] - 0.20105427588137500000e-6 * t20 * t118 * t378 * t321;
  t384 = t40 * t383;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[5] = -0.4e1 * t357 - 0.4e1 * t134 * t366 - 0.8e1 / 0.3e1 * t134 * t384;

  t392 = 0.1e1 / t200 / rho[0];
  t397 = -0.92024636666666666666e-5 * t18 * t19 * t140 * t85 + 0.67018091960458333333e-7 * t20 * sigma[0] * t392 * t212;
  t398 = t10 * t397;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = -0.8e1 / 0.3e1 * t134 * t398;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[1] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[2] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[3] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[4] = 0.0e0;

  t406 = 0.1e1 / t309 / rho[1];
  t411 = -0.92024636666666666666e-5 * t18 * t19 * t154 * t123 + 0.67018091960458333333e-7 * t20 * sigma[2] * t406 * t321;
  t412 = t40 * t411;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[5] = -0.8e1 / 0.3e1 * t134 * t412;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t417 = 0.2e1 * t189;
  t419 = 0.2e1 * t234;
  t430 = t61 * t191 * t66;
  t433 = t61 * t71 * t183;
  t441 = t62 * t62;
  t443 = t3 / t441;
  t445 = 0.3e1 * t181 - 0.3e1 * t443;
  t449 = t11 * t251;
  t451 = t93 * t98 * t229;
  t457 = t41 * t265;
  t460 = t11 * t187 * t89;
  t463 = t11 * t70 * t216;
  t473 = 0.1e1 / t200 / t74;
  t478 = t80 * t80;
  t484 = 0.1e1 / t29 / t210 / t26;
  t493 = t2 / t10;
  t498 = t169 * t71 * t170;
  t505 = t61 * t188 * t66;
  t508 = t2 / t40;
  t513 = t221 * t98 * t222;
  t520 = t93 * t233 * t94;
  t522 = 0.2e1 * t460 - 0.4e1 * t463 - 0.8e1 / 0.3e1 * t11 * t12 * (-0.44226666666666666666e-1 * t20 * t141 * t30 + 0.12699399860000000000e-2 * t20 * t80 * t392 * t85 - 0.12666419380526625000e-4 * t20 * t206 * t473 * t212 + 0.41416024769476932094e-7 * t20 * t478 / t200 / t81 * t484) + t493 * t35 * t170 * t66 - 0.3e1 * t498 - 0.6e1 * t238 * t34 * t66 * t183 + 0.3e1 * t505 + t508 * t56 * t222 * t94 - 0.3e1 * t513 - 0.6e1 * t257 * t55 * t94 * t229 + 0.3e1 * t520;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.24e2 * t178 - 0.12e2 * t185 + t417 - 0.12e2 * t231 + t419 - 0.8e1 * t192 - 0.8e1 * t218 - 0.6e1 * t172 - 0.12e2 * t175 - 0.6e1 * t224 - 0.12e2 * t227 + t4 * (-0.6e1 * t169 * t90 * t170 - 0.12e2 * t61 * t90 * t183 - 0.12e2 * t61 * t217 * t66 - 0.4e1 * t61 * t35 * t445 + 0.4e1 * t93 * t56 * t445 - 0.12e2 * t430 - 0.6e1 * t433 - t449 - 0.6e1 * t451 - t457 + t522);

  t525 = 0.8e1 * t247;
  t526 = 0.8e1 * t267;
  t527 = 0.8e1 * t271;
  t532 = 0.4e1 * t241;
  t533 = 0.8e1 * t253;
  t534 = 0.4e1 * t260;
  t542 = t41 * t187 * t127;
  t544 = t493 * t12;
  t549 = 0.2e1 * t169 * t70 * t240;
  t550 = t169 * t250;
  t555 = t508 * t12;
  t560 = 0.2e1 * t221 * t70 * t259;
  t571 = t221 * t250;
  t576 = -t449 - t457 + 0.4e1 / 0.3e1 * t460 - 0.4e1 / 0.3e1 * t463 - 0.4e1 * t61 * t251 + 0.4e1 * t93 * t265 + 0.2e1 / 0.3e1 * t542 + t544 * t239 * t170 - t549 - 0.4e1 * t550 * t34 * t3 * t66 + t555 * t258 * t222 - t560 - 0.4e1 * t238 * t89 * t104 * t66 - 0.2e1 * t238 * t239 * t183 - 0.2e1 * t257 * t258 * t229 + 0.4e1 * t571 * t55 * t3 * t94;
  t583 = t61 * t188 * t104;
  t585 = 0.1e1 / t12 / t180;
  t588 = t61 * t585 * t34 * t3;
  t595 = t93 * t233 * t108;
  t601 = 0.4e1 * t93 * t273 * t94;
  t604 = 0.4e1 * t61 * t191 * t104;
  t610 = t93 * t585 * t55 * t3;
  t615 = -0.8e1 * t61 * t250 * t89 * t3 - 0.4e1 * t61 * t217 * t104 - 0.2e1 * t221 * t128 * t222 - 0.4e1 * t93 * t128 * t229 - 0.4e1 * t430 - 0.2e1 * t433 - 0.2e1 * t451 - t498 + 0.2e1 * t505 - t513 + 0.2e1 * t520 + t583 + 0.8e1 * t588 + t595 - t601 - t604 - 0.8e1 * t610;
  t618 = -t219 - t173 - 0.8e1 * t175 - t225 - 0.8e1 * t227 - t532 - t285 - t533 - t534 - t294 + t4 * (t576 + t615);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = -t179 - t186 + t417 - t232 + t419 - t525 + t526 - t527 - t302 - 0.16e2 / 0.3e1 * t192 + t618;

  t626 = t41 * t70 * t325;
  t652 = -t449 - t457 + 0.2e1 / 0.3e1 * t460 + 0.4e1 / 0.3e1 * t542 - 0.4e1 / 0.3e1 * t626 - t549 - t560 - 0.4e1 * t550 * t239 * t3 + t544 * t34 * t281 * t66 - 0.2e1 * t238 * t34 * t286 * t66 + t555 * t55 * t290 * t94 + 0.4e1 * t571 * t258 * t3 - 0.4e1 * t257 * t127 * t108 * t94 - 0.2e1 * t257 * t55 * t298 * t94 + t505 + t520;
  t658 = t169 * t71 * t281;
  t660 = t61 * t71 * t286;
  t663 = t221 * t98 * t290;
  t665 = t93 * t273 * t108;
  t668 = t93 * t98 * t298;
  t677 = -t181 - 0.3e1 * t443;
  t692 = 0.8e1 * t93 * t250 * t127 * t3 - 0.2e1 * t169 * t90 * t281 - 0.4e1 * t61 * t90 * t286 - 0.4e1 * t93 * t326 * t94 - 0.4e1 * t61 * t35 * t677 + 0.4e1 * t93 * t56 * t677 + 0.2e1 * t583 - 0.4e1 * t588 + 0.2e1 * t595 - t601 - t604 + 0.4e1 * t610 - t658 - 0.2e1 * t660 - t663 - 0.4e1 * t665 - 0.2e1 * t668;
  t695 = -t328 - t176 - t228 - t532 - 0.8e1 * t244 - t533 - t534 - 0.8e1 * t263 - t284 - t293 + t4 * (t652 + t692);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = t417 + t419 - t525 + t526 - t527 - 0.16e2 / 0.3e1 * t274 - t289 - t297 - t301 - t193 + t695;

  t713 = 0.1e1 / t309 / t112;
  t718 = t118 * t118;
  t724 = 0.1e1 / t50 / t319 / t47;
  t755 = -0.3e1 * t181 - 0.3e1 * t443;
  t772 = t493 * t35 * t281 * t104 + t508 * t56 * t290 * t108 - 0.12e2 * t93 * t326 * t108 - 0.6e1 * t221 * t128 * t290 - 0.12e2 * t93 * t128 * t298 - 0.6e1 * t238 * t239 * t286 - 0.6e1 * t257 * t258 * t298 - 0.4e1 * t61 * t35 * t755 + 0.4e1 * t93 * t56 * t755 + 0.2e1 * t542 - 0.4e1 * t626;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = t417 + t419 - 0.8e1 * t274 - 0.12e2 * t288 - 0.24e2 * t296 - 0.12e2 * t300 - 0.8e1 * t327 - 0.12e2 * t244 - 0.12e2 * t263 - 0.6e1 * t283 - 0.6e1 * t292 + t4 * (-t449 - t457 - 0.8e1 / 0.3e1 * t41 * t12 * (-0.44226666666666666666e-1 * t20 * t155 * t51 + 0.12699399860000000000e-2 * t20 * t118 * t406 * t123 - 0.12666419380526625000e-4 * t20 * t315 * t713 * t321 + 0.41416024769476932094e-7 * t20 * t718 / t309 / t119 * t724) + 0.3e1 * t583 + 0.3e1 * t595 - 0.3e1 * t658 - 0.6e1 * t660 - 0.3e1 * t663 - 0.12e2 * t665 - 0.6e1 * t668 + t772);

  t776 = t61 * t331 * t66;
  t780 = 0.2e1 * t11 * t70 * t145;
  t782 = t11 * t12 * t352;
  t784 = t168 * t145;
  t788 = t9 * t352;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -0.12e2 * t776 - t780 - 0.8e1 * t782 - 0.2e1 * t134 * t784 * t170 - 0.8e1 * t134 * t788 * t66 - 0.4e1 * t134 * t334 * t183 - 0.8e1 / 0.3e1 * t134 * t10 * (0.88453333333333333332e-2 * t18 * t19 * t195 * t30 - 0.33128869200000000000e-3 * t20 * t201 * t85 * sigma[0] + 0.38200312417461250000e-5 * t20 * t208 * t212 * t80 - 0.13805341589825644031e-7 * t20 * t206 / t200 / t139 * t484);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[1] = 0.0e0;

  t818 = t93 * t356 * t94;
  t822 = 0.2e1 * t41 * t70 * t159;
  t823 = t220 * t159;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[2] = -0.2e1 * t134 * t823 * t222 - 0.4e1 * t134 * t358 * t229 - 0.12e2 * t818 - t822;

  t832 = t12 * t2;
  t833 = t832 * t362;
  t843 = t187 * t2;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[3] = -0.2e1 * t134 * t168 * t145 * t104 * t66 - 0.4e1 * t134 * t788 * t104 - 0.4e1 * t843 * t334 * t3 - 0.6e1 * t776 - t780 - 0.4e1 * t782 - 0.6e1 * t833;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[4] = 0.0e0;

  t848 = t832 * t366;
  t858 = t832 * t384;
  t860 = t39 * t383;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[5] = -0.2e1 * t134 * t220 * t159 * t108 * t94 - 0.4e1 * t134 * t860 * t94 + 0.4e1 * t843 * t358 * t3 - 0.6e1 * t818 - t822 - 0.6e1 * t848 - 0.4e1 * t858;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[6] = -0.2e1 * t134 * t784 * t281 - 0.4e1 * t134 * t334 * t286 - t780 - 0.12e2 * t833;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[7] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[8] = -0.12e2 * t848 - t822 - 0.8e1 * t858 - 0.2e1 * t134 * t823 * t290 - 0.8e1 * t134 * t860 * t108 - 0.4e1 * t134 * t358 * t298 - 0.8e1 / 0.3e1 * t134 * t40 * (0.88453333333333333332e-2 * t18 * t19 * t304 * t51 - 0.33128869200000000000e-3 * t20 * t310 * t123 * sigma[2] + 0.38200312417461250000e-5 * t20 * t317 * t321 * t118 - 0.13805341589825644031e-7 * t20 * t315 / t309 / t153 * t724);

  t904 = t832 * t398;
  t906 = t9 * t397;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -0.4e1 * t904 - 0.4e1 * t134 * t906 * t66 - 0.8e1 / 0.3e1 * t134 * t10 * (0.55214782000000000000e-4 * t18 * t19 * t82 * t85 - 0.10052713794068750000e-5 * t20 * t347 * t212 * sigma[0] + 0.46017805299418813437e-8 * t20 * t80 / t200 / t194 * t484);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[1] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[2] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[3] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[4] = 0.0e0;

  t928 = t832 * t412;
  t929 = t39 * t411;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[5] = -0.4e1 * t134 * t929 * t94 - 0.4e1 * t928;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[6] = -0.4e1 * t134 * t906 * t104 - 0.4e1 * t904;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[7] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[8] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[9] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[10] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[11] = -0.4e1 * t928 - 0.4e1 * t134 * t929 * t108 - 0.8e1 / 0.3e1 * t134 * t40 * (0.55214782000000000000e-4 * t18 * t19 * t120 * t123 - 0.10052713794068750000e-5 * t20 * t378 * t321 * sigma[2] + 0.46017805299418813437e-8 * t20 * t118 / t309 / t303 * t724);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.8e1 / 0.3e1 * t134 * t10 * (0.20105427588137500000e-6 * t18 * t19 * t392 * t212 - 0.15339268433139604479e-8 * t20 * sigma[0] * t473 * t484);

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

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[9] = -0.8e1 / 0.3e1 * t134 * t40 * (0.20105427588137500000e-6 * t18 * t19 * t406 * t321 - 0.15339268433139604479e-8 * t20 * sigma[2] * t713 * t724);

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


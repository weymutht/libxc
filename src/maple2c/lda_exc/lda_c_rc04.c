/* 
  This file was generated automatically with ./scripts/maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ./maple/lda_c_rc04.mpl
  Type of functional: lda_exc
*/

#define maple2c_order 3

static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t3, t4, t5, t6, t7, t12, t13;
  double t16, t17, t19, t21, t23, t24, t25, t30;
  double t35, t36, t45, t65, t69;


  t1 = M_CBRT3;
  t3 = POW_1_3(0.1e1 / M_PI);
  t4 = t1 * t3;
  t5 = M_CBRT4;
  t6 = t5 * t5;
  t7 = POW_1_3(rho[0]);
  t12 = 0.4888270e1 + 0.79425925000000000000e0 * t4 * t6 / t7;
  t13 = atan(t12);
  t16 = t1 * t1;
  t17 = (-0.655868e0 * t13 + 0.897889e0) * t16;
  t19 = 0.1e1 / t3 * t5;
  t21 = t17 * t19 * t7;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = t21 / 0.3e1;

  if(order < 1) return;


  t23 = t12 * t12;
  t24 = t23 + 0.1e1;
  t25 = 0.1e1 / t24;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = 0.4e1 / 0.9e1 * t21 + 0.69457230103866666663e0 * t25;

  if(order < 2) return;


  t30 = t7 * t7;
  t35 = t24 * t24;
  t36 = 0.1e1 / t35;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = 0.92609640138488888884e0 / rho[0] * t25 + 0.4e1 / 0.27e2 * t17 * t19 / t30 + 0.36778031659583040509e0 * t36 * t12 * t1 * t3 * t6 / t7 / rho[0];

  if(order < 3) return;


  t45 = rho[0] * rho[0];
  t65 = t3 * t3;
  t69 = t65 * t5 / t30 / t45;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.61739760092325925923e0 / t45 * t25 - 0.1e-19 / t7 / t45 * t36 * t12 * t4 * t6 - 0.8e1 / 0.81e2 * t17 * t19 / t30 / rho[0] + 0.15579355649288896569e1 / t35 / t24 * t23 * t16 * t69 - 0.38948389123222241422e0 * t36 * t16 * t69;

  if(order < 4) return;



}


static inline void
func_ferr(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t3, t4, t5, t6, t7, t12, t13;
  double t16, t17, t19, t21, t23, t24, t25, t30;
  double t35, t36, t45, t65, t69;


  t1 = M_CBRT3;
  t3 = POW_1_3(0.1e1 / M_PI);
  t4 = t1 * t3;
  t5 = M_CBRT4;
  t6 = t5 * t5;
  t7 = POW_1_3(rho[0]);
  t12 = 0.4888270e1 + 0.79425925000000000000e0 * t4 * t6 / t7;
  t13 = atan(t12);
  t16 = t1 * t1;
  t17 = (-0.655868e0 * t13 + 0.897889e0) * t16;
  t19 = 0.1e1 / t3 * t5;
  t21 = t17 * t19 * t7;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = t21 / 0.6e1;

  if(order < 1) return;


  t23 = t12 * t12;
  t24 = t23 + 0.1e1;
  t25 = 0.1e1 / t24;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = 0.2e1 / 0.9e1 * t21 + 0.34728615051933333332e0 * t25;

  if(order < 2) return;


  t30 = t7 * t7;
  t35 = t24 * t24;
  t36 = 0.1e1 / t35;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = 0.46304820069244444442e0 / rho[0] * t25 + 0.2e1 / 0.27e2 * t17 * t19 / t30 + 0.18389015829791520255e0 * t36 * t12 * t1 * t3 * t6 / t7 / rho[0];

  if(order < 3) return;


  t45 = rho[0] * rho[0];
  t65 = t3 * t3;
  t69 = t65 * t5 / t30 / t45;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.30869880046162962961e0 / t45 * t25 - 0.1e-19 / t7 / t45 * t36 * t12 * t4 * t6 - 0.4e1 / 0.81e2 * t17 * t19 / t30 / rho[0] + 0.77896778246444482846e0 / t35 / t24 * t23 * t16 * t69 - 0.19474194561611120712e0 * t36 * t16 * t69;

  if(order < 4) return;



}


static inline void
func_pol(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t2, t3, t4, t5, t6, t7, t8;
  double t9, t10, t12, t13, t14, t15, t17, t18;
  double t19, t20, t21, t26, t27, t29, t31, t32;
  double t33, t34, t36, t37, t38, t40, t41, t42;
  double t43, t44, t45, t46, t48, t49, t52, t56;
  double t57, t58, t60, t61, t63, t66, t68, t71;
  double t74, t78, t79, t80, t83, t84, t85, t86;
  double t91, t92, t95, t96, t100, t101, t103, t107;
  double t108, t111, t114, t118, t119, t120, t124, t126;
  double t129, t130, t132, t133, t134, t135, t138, t140;
  double t143, t146, t149, t152, t154, t158, t160, t164;
  double t168, t171, t174, t177, t179, t185, t189, t195;
  double t198, t200, t202, t206, t207, t208, t210, t214;
  double t224, t229, t233, t236, t238, t245, t246, t247;
  double t249, t252, t254, t272, t275, t279, t284, t290;
  double t292, t295, t310, t313, t315, t318, t322, t325;
  double t356, t362, t368, t375, t377, t379, t395, t413;
  double t436;


  t1 = rho[0] - rho[1];
  t2 = rho[0] + rho[1];
  t3 = 0.1e1 / t2;
  t4 = t1 * t3;
  t5 = 0.1e1 + t4;
  t6 = POW_1_3(t5);
  t7 = t6 * t6;
  t8 = 0.1e1 - t4;
  t9 = POW_1_3(t8);
  t10 = t9 * t9;
  t12 = t7 / 0.2e1 + t10 / 0.2e1;
  t13 = t12 * t12;
  t14 = t13 * t12;
  t15 = M_CBRT3;
  t17 = POW_1_3(0.1e1 / M_PI);
  t18 = t15 * t17;
  t19 = M_CBRT4;
  t20 = t19 * t19;
  t21 = POW_1_3(t2);
  t26 = 0.4888270e1 + 0.79425925000000000000e0 * t18 * t20 / t21;
  t27 = atan(t26);
  t29 = -0.655868e0 * t27 + 0.897889e0;
  t31 = t15 * t15;
  t32 = t14 * t29 * t31;
  t33 = 0.1e1 / t17;
  t34 = t33 * t19;
  t36 = t32 * t34 * t21;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = t36 / 0.3e1;

  if(order < 1) return;


  t37 = 0.4e1 / 0.9e1 * t36;
  t38 = t21 * t2;
  t40 = t38 * t13 * t29;
  t41 = t31 * t33;
  t42 = 0.1e1 / t6;
  t43 = t2 * t2;
  t44 = 0.1e1 / t43;
  t45 = t1 * t44;
  t46 = t3 - t45;
  t48 = 0.1e1 / t9;
  t49 = -t46;
  t52 = t42 * t46 / 0.3e1 + t48 * t49 / 0.3e1;
  t56 = t26 * t26;
  t57 = t56 + 0.1e1;
  t58 = 0.1e1 / t57;
  t60 = 0.69457230103866666663e0 * t14 * t58;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = t40 * t41 * t19 * t52 + t37 + t60;

  t61 = -t3 - t45;
  t63 = -t61;
  t66 = t42 * t61 / 0.3e1 + t48 * t63 / 0.3e1;
  t68 = t41 * t19 * t66;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = t40 * t68 + t37 + t60;

  if(order < 2) return;


  t71 = t13 * t29 * t31;
  t74 = t71 * t34 * t21 * t52;
  t78 = 0.92609640138488888884e0 * t14 * t3 * t58;
  t79 = t21 * t21;
  t80 = 0.1e1 / t79;
  t83 = 0.4e1 / 0.27e2 * t32 * t34 * t80;
  t84 = t38 * t12;
  t85 = t84 * t29;
  t86 = t52 * t52;
  t91 = t13 * t58;
  t92 = t91 * t52;
  t95 = 0.1e1 / t6 / t5;
  t96 = t46 * t46;
  t100 = 0.1e1 / t43 / t2;
  t101 = t1 * t100;
  t103 = -0.2e1 * t44 + 0.2e1 * t101;
  t107 = 0.1e1 / t9 / t8;
  t108 = t49 * t49;
  t111 = -t103;
  t114 = -t95 * t96 / 0.9e1 + t42 * t103 / 0.3e1 - t107 * t108 / 0.9e1 + t48 * t111 / 0.3e1;
  t118 = t57 * t57;
  t119 = 0.1e1 / t118;
  t120 = t14 * t119;
  t124 = t18 * t20 / t38;
  t126 = 0.36778031659583040509e0 * t120 * t26 * t124;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = 0.8e1 / 0.3e1 * t74 + t78 + t83 + 0.2e1 * t85 * t41 * t19 * t86 + 0.41674338062319999998e1 * t92 + t40 * t41 * t19 * t114 + t126;

  t129 = t21 * t13 * t29;
  t130 = t129 * t68;
  t132 = t29 * t31;
  t133 = t84 * t132;
  t134 = t66 * t52;
  t135 = t34 * t134;
  t138 = t91 * t66;
  t140 = t95 * t61;
  t143 = t42 * t1;
  t146 = t107 * t63;
  t149 = t48 * t1;
  t152 = -t140 * t46 / 0.9e1 + 0.2e1 / 0.3e1 * t143 * t100 - t146 * t49 / 0.9e1 - 0.2e1 / 0.3e1 * t149 * t100;
  t154 = t41 * t19 * t152;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = 0.4e1 / 0.3e1 * t74 + t78 + t83 + 0.4e1 / 0.3e1 * t130 + 0.2e1 * t133 * t135 + 0.20837169031159999999e1 * t138 + t40 * t154 + 0.20837169031159999999e1 * t92 + t126;

  t158 = t66 * t66;
  t160 = t41 * t19 * t158;
  t164 = t61 * t61;
  t168 = 0.2e1 * t44 + 0.2e1 * t101;
  t171 = t63 * t63;
  t174 = -t168;
  t177 = -t95 * t164 / 0.9e1 + t42 * t168 / 0.3e1 - t107 * t171 / 0.9e1 + t48 * t174 / 0.3e1;
  t179 = t41 * t19 * t177;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = 0.8e1 / 0.3e1 * t130 + t78 + t83 + 0.2e1 * t85 * t160 + 0.41674338062319999998e1 * t138 + t40 * t179 + t126;

  if(order < 3) return;


  t185 = t12 * t29 * t31 * t34 * t21 * t86;
  t189 = t71 * t34 * t80 * t52;
  t195 = t13 * t119;
  t198 = t195 * t52 * t26 * t124;
  t200 = t13 * t3;
  t202 = t200 * t58 * t52;
  t206 = 0.61739760092325925923e0 * t14 * t44 * t58;
  t207 = t12 * t58;
  t208 = t207 * t86;
  t210 = t91 * t114;
  t214 = t71 * t34 * t21 * t114;
  t224 = 0.1e-19 * t14 / t21 / t43 * t119 * t26 * t15 * t17 * t20;
  t229 = 0.8e1 / 0.81e2 * t32 * t34 / t79 / t2;
  t233 = t41 * t19;
  t236 = t5 * t5;
  t238 = 0.1e1 / t6 / t236;
  t245 = t43 * t43;
  t246 = 0.1e1 / t245;
  t247 = t1 * t246;
  t249 = 0.6e1 * t100 - 0.6e1 * t247;
  t252 = t8 * t8;
  t254 = 0.1e1 / t9 / t252;
  t272 = t17 * t17;
  t275 = 0.1e1 / t79 / t43;
  t279 = 0.15579355649288896569e1 * t14 / t118 / t57 * t56 * t31 * t272 * t19 * t275;
  t284 = 0.38948389123222241422e0 * t120 * t31 * t272 * t19 * t275;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = 0.8e1 * t185 + 0.4e1 / 0.3e1 * t189 + 0.6e1 * t133 * t34 * t52 * t114 + 0.33100228493624736458e1 * t198 + 0.83348676124639999996e1 * t202 - t206 + 0.12502301418695999999e2 * t208 + 0.62511507093479999997e1 * t210 + 0.4e1 * t214 - t224 - t229 + 0.2e1 * t38 * t86 * t52 * t29 * t233 + t40 * t41 * t19 * (0.4e1 / 0.27e2 * t238 * t96 * t46 - t95 * t46 * t103 / 0.3e1 + t42 * t249 / 0.3e1 + 0.4e1 / 0.27e2 * t254 * t108 * t49 - t107 * t49 * t111 / 0.3e1 - t48 * t249 / 0.3e1) + t279 - t284;

  t290 = t80 * t13 * t29 * t68;
  t292 = t21 * t12;
  t295 = 0.16e2 / 0.3e1 * t292 * t132 * t135;
  t310 = t195 * t66 * t26 * t124;
  t313 = 0.8e1 / 0.3e1 * t185 + 0.8e1 / 0.9e1 * t189 + 0.22066818995749824306e1 * t198 + 0.4e1 / 0.9e1 * t290 + t295 + 0.2e1 * t38 * t86 * t29 * t68 + 0.4e1 * t133 * t34 * t152 * t52 + 0.2e1 * t133 * t34 * t66 * t114 + 0.11033409497874912153e1 * t310 + 0.55565784083093333330e1 * t202 - t206;
  t315 = t200 * t58 * t66;
  t318 = 0.83348676124639999996e1 * t207 * t134;
  t322 = 0.41674338062319999998e1 * t91 * t152;
  t325 = 0.8e1 / 0.3e1 * t129 * t154;
  t356 = 0.27782892041546666665e1 * t315 + t318 + 0.41674338062319999998e1 * t208 + 0.20837169031159999999e1 * t210 + t322 + 0.4e1 / 0.3e1 * t214 - t224 - t229 + t279 + t325 + t40 * t41 * t19 * (0.4e1 / 0.27e2 * t238 * t61 * t96 - 0.4e1 / 0.9e1 * t95 * t1 * t100 * t46 - t140 * t103 / 0.9e1 + 0.2e1 / 0.3e1 * t42 * t100 - 0.2e1 * t143 * t246 + 0.4e1 / 0.27e2 * t254 * t63 * t108 + 0.4e1 / 0.9e1 * t107 * t1 * t100 * t49 - t146 * t111 / 0.9e1 - 0.2e1 / 0.3e1 * t48 * t100 + 0.2e1 * t149 * t246) - t284;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = t313 + t356;

  t362 = t292 * t29 * t160;
  t368 = t129 * t179;
  t375 = 0.4e1 / 0.9e1 * t189 + 0.11033409497874912153e1 * t198 + 0.8e1 / 0.9e1 * t290 + t295 + 0.22066818995749824305e1 * t310 + 0.8e1 / 0.3e1 * t362 + 0.4e1 * t133 * t34 * t66 * t152 + 0.4e1 / 0.3e1 * t368 + 0.2e1 * t133 * t34 * t177 * t52 + 0.27782892041546666665e1 * t202 - t206;
  t377 = t207 * t158;
  t379 = t91 * t177;
  t395 = -0.2e1 * t100 - 0.6e1 * t247;
  t413 = 0.55565784083093333331e1 * t315 + t318 + t322 + 0.41674338062319999998e1 * t377 + 0.20837169031159999999e1 * t379 - t224 - t229 + t279 + t325 + 0.2e1 * t38 * t52 * t29 * t160 + t40 * t41 * t19 * (0.4e1 / 0.27e2 * t238 * t164 * t46 - 0.4e1 / 0.9e1 * t140 * t101 - t95 * t168 * t46 / 0.9e1 + t42 * t395 / 0.3e1 + 0.4e1 / 0.27e2 * t254 * t171 * t49 + 0.4e1 / 0.9e1 * t146 * t101 - t107 * t174 * t49 / 0.9e1 - t48 * t395 / 0.3e1) - t284;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = t375 + t413;

  t436 = -0.6e1 * t100 - 0.6e1 * t247;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = 0.4e1 / 0.3e1 * t290 + 0.33100228493624736458e1 * t310 + 0.8e1 * t362 + 0.4e1 * t368 + 0.6e1 * t133 * t34 * t66 * t177 - t206 + 0.83348676124639999996e1 * t315 + 0.12502301418695999999e2 * t377 + 0.62511507093479999997e1 * t379 - t224 - t229 + t279 + 0.2e1 * t38 * t158 * t66 * t29 * t233 + t40 * t41 * t19 * (0.4e1 / 0.27e2 * t238 * t164 * t61 - t140 * t168 / 0.3e1 + t42 * t436 / 0.3e1 + 0.4e1 / 0.27e2 * t254 * t171 * t63 - t146 * t174 / 0.3e1 - t48 * t436 / 0.3e1) - t284;

  if(order < 4) return;



}


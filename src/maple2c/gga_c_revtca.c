/* 
  This file was generated automatically with /nfs/data-012/marques/software/source/libxc/svn/scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ../maple/gga_c_revtca.mpl
  Type of functional: work_gga_c
*/

void xc_gga_c_revtca_func
  (const xc_func_type *p, xc_gga_work_c_t *r)
{
  double t1, t2, t3, t4, t5, t6, t8, t9;
  double t10, t12, t13, t15, t16, t17, t18, t19;
  double t20, t21, t22, t23, t24, t25, t26, t27;
  double t29, t30, t31, t32, t33, t34, t35, t36;
  double t37, t38, t39, t41, t42, t46, t47, t48;
  double t51, t52, t53, t54, t55, t56, t57, t62;
  double t63, t64, t66, t67, t68, t69, t70, t71;
  double t74, t75, t76, t77, t79, t80, t81, t82;
  double t86, t87, t88, t91, t92, t93, t97, t98;
  double t101, t102, t103, t106, t107, t108, t109, t110;
  double t112, t113, t117, t118, t119, t125, t126, t127;
  double t130, t131, t132, t133, t135, t136, t141, t145;
  double t147, t150, t153, t154, t157, t158, t159, t160;
  double t161, t163, t167, t170, t171, t176, t181, t182;
  double t183, t184, t187, t190, t195, t196, t201, t202;
  double t204, t207, t208, t212, t213, t214, t221, t222;
  double t223, t226, t227, t228, t229, t232, t233, t241;
  double t242, t245, t246, t249, t250, t252, t255, t256;
  double t259, t260, t262, t265, t269, t270, t272, t274;
  double t275, t276, t277, t278, t282, t285, t287, t290;
  double t291, t294, t302, t303, t309, t310, t311, t314;
  double t320, t332, t333, t335, t337, t338, t346, t357;
  double t362, t371, t378, t397, t407, t450, t455, t488;
  double t490, t525, t539, t605, t669, t672, t756, t759;
  double t767, t768, t769, t790, t813, t821;


  t1 = 0.1e1 + r->z;
  t2 = cbrt(t1);
  t3 = t2 * t2;
  t4 = 0.1e1 - r->z;
  t5 = cbrt(t4);
  t6 = t5 * t5;
  t8 = t3 / 0.2e1 + t6 / 0.2e1;
  t9 = t8 * t8;
  t10 = t9 * t8;
  t12 = 0.4888270e1 + 0.3177037e1 * r->rs;
  t13 = atan(t12);
  t15 = -0.655868e0 * t13 + 0.897889e0;
  t16 = t10 * t15;
  t17 = 0.1e1 / r->rs;
  t18 = M_CBRT6;
  t19 = t18 * t18;
  t20 = 0.31415926535897932385e1 * 0.31415926535897932385e1;
  t21 = cbrt(t20);
  t22 = 0.1e1 / t21;
  t23 = t19 * t22;
  t24 = M_CBRT2;
  t25 = t24 * r->xt;
  t26 = t23 * t25;
  t27 = pow(t26, 0.230e1);
  t29 = 0.1e1 + 0.47121507034422759993e-2 * t27;
  t30 = 0.1e1 / t29;
  t31 = t17 * t30;
  t32 = r->z * r->z;
  t33 = t32 * t32;
  t34 = cbrt(0.31415926535897932385e1);
  t35 = t34 * 0.31415926535897932385e1;
  t36 = cbrt(0.9e1);
  t37 = t35 * t36;
  t38 = M_CBRT4;
  t39 = t38 * t38;
  t41 = t37 * t39 * t19;
  t42 = t22 * t24;
  t46 = t41 * t42 * r->xt * t17 / 0.48e2;
  t47 = t46 == 0.0e0;
  t48 = sin(t46);
  t51 = t36 * t36;
  t52 = t51 * t38;
  t53 = t48 / t35 * t52;
  t54 = t18 * t21;
  t55 = t24 * t24;
  t56 = 0.1e1 / r->xt;
  t57 = t55 * t56;
  t62 = (t47 ? 1 : t53 * t54 * t57 * r->rs / 0.9e1);
  t63 = t62 * t62;
  t64 = 0.1e1 - t63;
  t66 = -t33 * t64 + 0.1e1;
  t67 = t31 * t66;
  r->f = t16 * t67;

  if(r->order < 1) return;

  t68 = t12 * t12;
  t69 = t68 + 0.1e1;
  t70 = 0.1e1 / t69;
  t71 = t10 * t70;
  t74 = r->rs * r->rs;
  t75 = 0.1e1 / t74;
  t76 = t75 * t30;
  t77 = t76 * t66;
  t79 = t16 * t17;
  t80 = t30 * t33;
  t81 = cos(t46);
  t82 = t17 * t81;
  t86 = -t82 + t53 * t54 * t57 / 0.9e1;
  t87 = t62 * t86;
  t88 = t80 * t87;
  r->dfdrs = -0.2083716903116e1 * t71 * t67 - t16 * t77 + 0.2e1 * t79 * t88;
  t91 = t9 * t15;
  t92 = t91 * t17;
  t93 = t30 * t66;
  t97 = 0.1e1 / t2 / 0.3e1 - 0.1e1 / t5 / 0.3e1;
  t98 = t93 * t97;
  t101 = t32 * r->z;
  t102 = t30 * t101;
  t103 = t102 * t64;
  r->dfdz = -0.4e1 * t79 * t103 + 0.3e1 * t92 * t98;
  t106 = t29 * t29;
  t107 = 0.1e1 / t106;
  t108 = t17 * t107;
  t109 = t16 * t108;
  t110 = pow(t26, 0.130e1);
  t112 = t23 * t24;
  t113 = t66 * t110 * t112;
  t117 = r->xt * r->xt;
  t118 = 0.1e1 / t117;
  t119 = t55 * t118;
  t125 = (t47 ? 0 : t81 * t56 - t53 * t54 * t119 * r->rs / 0.9e1);
  t126 = t62 * t125;
  t127 = t80 * t126;
  r->dfdxt = -0.10837946617917234798e-1 * t109 * t113 + 0.2e1 * t79 * t127;
  r->dfdxs[0] = 0.0e0;
  r->dfdxs[1] = 0.0e0;

  if(r->order < 2) return;

  t130 = t69 * t69;
  t131 = 0.1e1 / t130;
  t132 = t10 * t131;
  t133 = t132 * t17;
  t135 = 0.31060429311980e2 + 0.20187128198738e2 * r->rs;
  t136 = t93 * t135;
  t141 = t71 * t17;
  t145 = 0.1e1 / t74 / r->rs;
  t147 = t145 * t30 * t66;
  t150 = t16 * t75;
  t153 = t86 * t86;
  t154 = t80 * t153;
  t157 = t74 * t74;
  t158 = 0.1e1 / t157;
  t159 = t16 * t158;
  t160 = t62 * t35;
  t161 = t80 * t160;
  t163 = t36 * t39;
  t167 = t163 * t19 * t42 * r->xt * t48;
  r->d2fdrs2 = 0.2083716903116e1 * t133 * t136 + 0.4167433806232e1 * t71 * t77 - 0.8334867612464e1 * t141 * t88 + 0.2e1 * t16 * t147 - 0.4e1 * t150 * t88 + 0.2e1 * t79 * t154 - t159 * t161 * t167 / 0.24e2;
  t170 = t9 * t70;
  t171 = t170 * t17;
  t176 = t91 * t75;
  t181 = t91 * t31;
  t182 = t33 * t62;
  t183 = t86 * t97;
  t184 = t182 * t183;
  t187 = t102 * t87;
  r->d2fdrsz = -0.6251150709348e1 * t171 * t98 + 0.8334867612464e1 * t141 * t103 - 0.3e1 * t176 * t98 + 0.4e1 * t150 * t103 + 0.6e1 * t181 * t184 + 0.8e1 * t79 * t187;
  t190 = t71 * t108;
  t195 = t75 * t107;
  t196 = t16 * t195;
  t201 = t108 * t33;
  t202 = t16 * t201;
  t204 = t87 * t110 * t112;
  t207 = t125 * t86;
  t208 = t80 * t207;
  t212 = t75 * t35 * t163;
  t213 = t24 * t48;
  t214 = t23 * t213;
  t221 = t212 * t214 / 0.48e2 + t82 * t56 - t53 * t54 * t119 / 0.9e1;
  t222 = t62 * t221;
  t223 = t80 * t222;
  r->d2fdrsxt = 0.22583212562823026611e-1 * t190 * t113 - 0.4167433806232e1 * t141 * t127 + 0.10837946617917234798e-1 * t196 * t113 - 0.2e1 * t150 * t127 - 0.21675893235834469596e-1 * t202 * t204 + 0.2e1 * t79 * t208 + 0.2e1 * t79 * t223;
  r->d2fdrsxs[0] = 0.0e0;
  r->d2fdrsxs[1] = 0.0e0;
  t226 = t8 * t15;
  t227 = t226 * t17;
  t228 = t97 * t97;
  t229 = t93 * t228;
  t232 = t64 * t97;
  t233 = t102 * t232;
  t241 = -0.1e1 / t2 / t1 / 0.9e1 - 0.1e1 / t5 / t4 / 0.9e1;
  t242 = t93 * t241;
  t245 = t30 * t32;
  t246 = t245 * t64;
  r->d2fdz2 = 0.6e1 * t227 * t229 - 0.24e2 * t92 * t233 + 0.3e1 * t92 * t242 - 0.12e2 * t79 * t246;
  t249 = t108 * t66;
  t250 = t91 * t249;
  t252 = t97 * t110 * t112;
  t255 = t125 * t97;
  t256 = t182 * t255;
  t259 = t108 * t101;
  t260 = t16 * t259;
  t262 = t64 * t110 * t112;
  t265 = t102 * t126;
  r->d2fdzxt = -0.32513839853751704394e-1 * t250 * t252 + 0.6e1 * t181 * t256 + 0.43351786471668939192e-1 * t260 * t262 + 0.8e1 * t79 * t265;
  r->d2fdzxs[0] = 0.0e0;
  r->d2fdzxs[1] = 0.0e0;
  t269 = 0.1e1 / t106 / t29;
  t270 = t17 * t269;
  t272 = pow(t26, 0.260e1);
  t274 = t21 * t21;
  t275 = 0.1e1 / t274;
  t276 = t18 * t275;
  t277 = t276 * t55;
  t278 = t66 * t272 * t277;
  t282 = t126 * t110 * t112;
  t285 = pow(t26, 0.30e0);
  t287 = t66 * t285 * t277;
  t290 = t125 * t125;
  t291 = t80 * t290;
  t294 = t17 * t48;
  t302 = 0.1e1 / t117 / r->xt;
  t303 = t55 * t302;
  t309 = (t47 ? 0 : -t41 * t42 * t294 * t56 / 0.48e2 - 0.2e1 * t81 * t118 + 0.2e1 / 0.9e1 * t53 * t54 * t303 * r->rs);
  t310 = t62 * t309;
  t311 = t80 * t310;
  r->d2fdxt2 = 0.14095330427138835389e-2 * t16 * t270 * t278 - 0.43351786471668939192e-1 * t202 * t282 - 0.84535983619754431424e-1 * t109 * t287 + 0.2e1 * t79 * t291 + 0.2e1 * t79 * t311;
  r->d2fdxtxs[0] = 0.0e0;
  r->d2fdxtxs[1] = 0.0e0;
  r->d2fdxs2[0] = 0.0e0;
  r->d2fdxs2[1] = 0.0e0;
  r->d2fdxs2[2] = 0.0e0;

  if(r->order < 3) return;

  t314 = t71 * t158;
  t320 = t16 / t157 / r->rs;
  t332 = t34 * t34;
  t333 = t332 * t20;
  t335 = t80 * t62 * t333;
  t337 = t52 * t18;
  t338 = t275 * t55;
  t346 = t132 * t31;
  t357 = t16 * t145;
  t362 = t71 * t75;
  t371 = t135 * t135;
  t378 = t80 * t62;
  r->d3fdrs3 = 0.17364307525966666667e0 * t314 * t161 * t167 + t320 * t161 * t167 / 0.4e1 - t159 * t80 * t86 * t35 * t167 / 0.8e1 + t16 / t157 / t74 * t335 * t337 * t338 * t117 * t81 / 0.48e2 + 0.42064260253080020739e2 * t132 * t67 + 0.12502301418696e2 * t346 * t182 * t86 * t135 - 0.6e1 * t16 * t158 * t30 * t66 - 0.12502301418696e2 * t71 * t147 + 0.12e2 * t357 * t88 - 0.6e1 * t150 * t154 + 0.25004602837392e2 * t362 * t88 - 0.12502301418696e2 * t141 * t154 - 0.4167433806232e1 * t10 / t130 / t69 * t17 * t93 * t371 - 0.6251150709348e1 * t132 * t75 * t136 + 0.39947901462554922316e0 * t314 * t378 * t167;
  t397 = t170 * t31;
  t407 = t91 * t76;
  r->d3fdrs2z = 0.6251150709348e1 * t9 * t131 * t17 * t93 * t135 * t97 - 0.8334867612464e1 * t133 * t102 * t64 * t135 + 0.12502301418696e2 * t170 * t75 * t98 - 0.16669735224928e2 * t362 * t103 - 0.25004602837392e2 * t397 * t184 - 0.33339470449856e2 * t141 * t187 + 0.6e1 * t91 * t145 * t98 - 0.8e1 * t357 * t103 - 0.12e2 * t407 * t184 - 0.16e2 * t150 * t187 + 0.6e1 * t92 * t80 * t153 * t97 + 0.8e1 * t79 * t102 * t153 - t91 * t158 * t161 * t163 * t23 * t25 * t48 * t97 / 0.8e1 - t159 * t102 * t160 * t167 / 0.6e1;
  t450 = t226 * t31;
  t455 = t101 * t62;
  r->d3fdrsz2 = -0.12502301418696e2 * t8 * t70 * t17 * t229 + 0.50009205674784e2 * t171 * t233 - 0.6251150709348e1 * t171 * t242 + 0.25004602837392e2 * t141 * t246 - 0.6e1 * t226 * t75 * t229 + 0.24e2 * t176 * t233 - 0.3e1 * t176 * t242 + 0.12e2 * t150 * t246 + 0.12e2 * t450 * t182 * t86 * t228 + 0.48e2 * t181 * t455 * t183 + 0.6e1 * t181 * t182 * t86 * t241 + 0.24e2 * t79 * t245 * t87;
  t488 = t107 * t33;
  t490 = t92 * t488 * t62;
  r->d3fdrszxt = 0.67749637688469079834e-1 * t170 * t249 * t252 - 0.12502301418696e2 * t397 * t256 - 0.90332850251292106445e-1 * t71 * t259 * t262 - 0.16669735224928e2 * t141 * t265 + 0.32513839853751704394e-1 * t91 * t195 * t66 * t252 - 0.6e1 * t407 * t256 - 0.43351786471668939192e-1 * t16 * t195 * t101 * t262 - 0.8e1 * t150 * t265 - 0.65027679707503408788e-1 * t490 * t183 * t110 * t112 + 0.6e1 * t181 * t33 * t125 * t183 + 0.6e1 * t181 * t182 * t221 * t97 - 0.86703572943337878384e-1 * t260 * t204 + 0.8e1 * t79 * t102 * t207 + 0.8e1 * t79 * t102 * t222;
  r->d3fdrszxs[0] = 0.0e0;
  r->d3fdrszxs[1] = 0.0e0;
  t525 = t71 * t201;
  t539 = t16 * t195 * t33;
  r->d3fdrs2xt = -0.22583212562823026611e-1 * t132 * t249 * t135 * t110 * t112 + 0.4167433806232e1 * t346 * t182 * t125 * t135 - 0.45166425125646053223e-1 * t71 * t195 * t113 + 0.8334867612464e1 * t362 * t127 + 0.90332850251292106445e-1 * t525 * t204 - 0.8334867612464e1 * t141 * t208 - 0.8334867612464e1 * t141 * t223 - 0.21675893235834469596e-1 * t16 * t145 * t107 * t113 + 0.4e1 * t357 * t127 + 0.43351786471668939192e-1 * t539 * t204 - 0.4e1 * t150 * t208 - 0.4e1 * t150 * t223 - 0.21675893235834469596e-1 * t202 * t153 * t110 * t112 + 0.4e1 * t79 * t80 * t86 * t221 + 0.12466757539900390583e-1 * t159 * t488 * t62 * t36 * t39 * t18 * t275 * t55 * r->xt * t48 * t110 - t159 * t80 * t125 * t35 * t167 / 0.24e2 - t159 * t378 * t37 * t39 * t214 / 0.24e2 - t320 * t335 * t337 * t338 * r->xt * t81 / 0.48e2;
  t605 = t16 * t270 * t33;
  r->d3fdrsxt2 = -0.29370678266034459558e-2 * t71 * t270 * t278 + 0.90332850251292106445e-1 * t525 * t282 + 0.17614905799001960757e0 * t190 * t287 - 0.4167433806232e1 * t141 * t291 - 0.4167433806232e1 * t141 * t311 - 0.14095330427138835389e-2 * t16 * t75 * t269 * t278 + 0.43351786471668939192e-1 * t539 * t282 + 0.84535983619754431424e-1 * t196 * t287 - 0.2e1 * t150 * t291 - 0.2e1 * t150 * t311 + 0.28190660854277670779e-2 * t605 * t87 * t272 * t277 - 0.43351786471668939192e-1 * t202 * t207 * t110 * t112 - 0.43351786471668939192e-1 * t202 * t222 * t110 * t112 - 0.16907196723950886285e0 * t202 * t87 * t285 * t277 + 0.2e1 * t79 * t80 * t309 * t86 + 0.4e1 * t79 * t80 * t125 * t221 + 0.2e1 * t79 * t80 * t62 * (t145 * t333 * t52 * t276 * t55 * t81 / 0.96e2 - t212 * t23 * t213 * t56 / 0.48e2 - 0.2e1 * t82 * t118 + 0.2e1 / 0.9e1 * t53 * t54 * t303);
  r->d3fdrsxtxs[0] = 0.0e0;
  r->d3fdrsxtxs[1] = 0.0e0;
  r->d3fdrs2xs[0] = 0.0e0;
  r->d3fdrs2xs[1] = 0.0e0;
  r->d3fdrsxs2[0] = 0.0e0;
  r->d3fdrsxs2[1] = 0.0e0;
  r->d3fdrsxs2[2] = 0.0e0;
  t669 = t1 * t1;
  t672 = t4 * t4;
  r->d3fdz3 = 0.6e1 * t228 * t97 * t15 * t67 - 0.72e2 * t227 * t102 * t64 * t228 + 0.18e2 * t227 * t93 * t97 * t241 - 0.108e3 * t92 * t245 * t232 - 0.36e2 * t92 * t102 * t64 * t241 + 0.3e1 * t92 * t93 * (0.4e1 / 0.27e2 / t2 / t669 - 0.4e1 / 0.27e2 / t5 / t672) - 0.24e2 * t79 * t30 * r->z * t64;
  r->d3fdz2xt = -0.65027679707503408788e-1 * t226 * t249 * t228 * t110 * t112 + 0.12e2 * t450 * t182 * t125 * t228 + 0.26011071883001363515e0 * t91 * t259 * t232 * t110 * t112 + 0.48e2 * t181 * t455 * t255 - 0.32513839853751704394e-1 * t250 * t241 * t110 * t112 + 0.6e1 * t181 * t182 * t125 * t241 + 0.13005535941500681758e0 * t16 * t108 * t32 * t262 + 0.24e2 * t79 * t245 * t126;
  r->d3fdzxt2 = 0.42285991281416506168e-2 * t91 * t270 * t66 * t97 * t272 * t277 - 0.13005535941500681758e0 * t490 * t255 * t110 * t112 - 0.25360795085926329427e0 * t250 * t97 * t285 * t277 + 0.6e1 * t92 * t80 * t290 * t97 + 0.6e1 * t181 * t182 * t309 * t97 - 0.56381321708555341558e-2 * t16 * t270 * t101 * t64 * t272 * t277 - 0.17340714588667575677e0 * t260 * t282 + 0.33814393447901772570e0 * t260 * t64 * t285 * t277 + 0.8e1 * t79 * t102 * t290 + 0.8e1 * t79 * t102 * t310;
  r->d3fdzxtxs[0] = 0.0e0;
  r->d3fdzxtxs[1] = 0.0e0;
  r->d3fdz2xs[0] = 0.0e0;
  r->d3fdz2xs[1] = 0.0e0;
  r->d3fdzxs2[0] = 0.0e0;
  r->d3fdzxs2[1] = 0.0e0;
  r->d3fdzxs2[2] = 0.0e0;
  t756 = t106 * t106;
  t759 = pow(t26, 0.390e1);
  t767 = t269 * t66;
  t768 = pow(t26, 0.160e1);
  t769 = 0.1e1 / t20;
  t790 = pow(t26, -0.70e0);
  t813 = t117 * t117;
  t821 = (t47 ? 0 : -t333 * t51 * t38 * t18 * t338 * t75 * t81 * t56 / 0.96e2 + t41 * t42 * t294 * t118 / 0.16e2 + 0.6e1 * t81 * t302 - 0.2e1 / 0.3e1 * t53 * t54 * t55 / t813 * r->rs);
  r->d3fdxt3 = -0.55721785502542111363e-4 * t79 / t756 * t66 * t759 + 0.84571982562833012336e-2 * t605 * t126 * t272 * t277 + 0.43977430932673166414e-1 * t79 * t767 * t768 * t769 - 0.65027679707503408788e-1 * t202 * t290 * t110 * t112 - 0.65027679707503408788e-1 * t202 * t310 * t110 * t112 - 0.50721590171852658855e0 * t202 * t126 * t285 * t277 + 0.22279226778238017763e-2 * t79 * t767 * t768 - 0.30432954103111595313e0 * t79 * t107 * t66 * t790 * t769 + 0.6e1 * t79 * t80 * t125 * t309 + 0.2e1 * t79 * t80 * t62 * t821;
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
#define maple2c_func  xc_gga_c_revtca_func

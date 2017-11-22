/* 
  This file was generated automatically with /nfs/data-012/marques/software/source/libxc/svn/scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ../maple/gga_c_am05.mpl
  Type of functional: work_gga_c
*/

void xc_gga_c_am05_func
  (const xc_func_type *p, xc_gga_work_c_t *r)
{
  double t2, t3, t6, t8, t10, t13, t14, t16;
  double t17, t18, t19, t20, t22, t23, t25, t26;
  double t27, t30, t32, t37, t40, t41, t45, t50;
  double t53, t54, t55, t58, t60, t63, t64, t65;
  double t66, t67, t68, t69, t70, t73, t74, t78;
  double t81, t82, t87, t88, t89, t90, t91, t92;
  double t94, t97, t98, t99, t101, t103, t104, t105;
  double t109, t110, t111, t115, t116, t117, t121, t122;
  double t123, t127, t131, t133, t136, t137, t138, t142;
  double t143, t145, t148, t152, t154, t155, t156, t158;
  double t161, t162, t163, t165, t170, t172, t173, t174;
  double t177, t179, t181, t183, t186, t187, t188, t189;
  double t190, t191, t194, t199, t200, t201, t207, t211;
  double t212, t213, t214, t215, t221, t222, t223, t229;
  double t230, t233, t234, t235, t236, t237, t241, t242;
  double t247, t251, t255, t258, t264, t267, t270, t274;
  double t278, t281, t284, t286, t289, t290, t292, t295;
  double t299, t303, t306, t310, t314, t315, t316, t319;
  double t320, t324, t328, t329, t330, t334, t337, t340;
  double t343, t347, t354, t360, t362, t364, t369, t377;
  double t384, t387, t403, t411, t415, t440, t447, t452;
  double t455, t459, t490, t565, t609, t618;


  t2 = 0.1e1 + 0.21370e0 * r->rs;
  t3 = sqrt(r->rs);
  t6 = POW_3_2(r->rs);
  t8 = r->rs * r->rs;
  t10 = 0.75957e1 * t3 + 0.35876e1 * r->rs + 0.16382e1 * t6 + 0.49294e0 * t8;
  t13 = 0.1e1 + 0.16081979498692535067e2 / t10;
  t14 = log(t13);
  t16 = 0.621814e-1 * t2 * t14;
  t17 = r->z * r->z;
  t18 = t17 * t17;
  t19 = 0.1e1 + r->z;
  t20 = POW_1_3(t19);
  t22 = 0.1e1 - r->z;
  t23 = POW_1_3(t22);
  t25 = t20 * t19 + t23 * t22 - 0.2e1;
  t26 = t18 * t25;
  t27 = POW_1_3(0.2e1);
  t30 = 0.1e1 / (0.2e1 * t27 - 0.2e1);
  t32 = 0.1e1 + 0.20548e0 * r->rs;
  t37 = 0.141189e2 * t3 + 0.61977e1 * r->rs + 0.33662e1 * t6 + 0.62517e0 * t8;
  t40 = 0.1e1 + 0.32163958997385070134e2 / t37;
  t41 = log(t40);
  t45 = 0.1e1 + 0.11125e0 * r->rs;
  t50 = 0.10357e2 * t3 + 0.36231e1 * r->rs + 0.88026e0 * t6 + 0.49671e0 * t8;
  t53 = 0.1e1 + 0.29608749977793437516e2 / t50;
  t54 = log(t53);
  t55 = t45 * t54;
  t58 = t30 * (-0.3109070e-1 * t32 * t41 + t16 - 0.19751673498613801407e-1 * t55);
  t60 = t25 * t30;
  t63 = -t16 + t26 * t58 + 0.19751673498613801407e-1 * t60 * t55;
  t64 = POW_1_3(0.6e1);
  t65 = 0.31415926535897932385e1 * 0.31415926535897932385e1;
  t66 = POW_1_3(t65);
  t67 = t66 * t66;
  t68 = 0.1e1 / t67;
  t69 = t64 * t68;
  t70 = r->xs[0] * r->xs[0];
  t73 = 0.1e1 + 0.11683333333333333333e0 * t69 * t70;
  t74 = 0.1e1 / t73;
  t78 = r->xs[1] * r->xs[1];
  t81 = 0.1e1 + 0.11683333333333333333e0 * t69 * t78;
  t82 = 0.1e1 / t81;
  t87 = t19 * (0.1902e0 * t74 + 0.8098e0) / 0.2e1 + t22 * (0.1902e0 * t82 + 0.8098e0) / 0.2e1;
  r->f = t63 * t87;

  if(r->order < 1) return;

  t88 = 0.13288165180e-1 * t14;
  t89 = t10 * t10;
  t90 = 0.1e1 / t89;
  t91 = t2 * t90;
  t92 = 0.1e1 / t3;
  t94 = sqrt(r->rs);
  t97 = 0.37978500000000000000e1 * t92 + 0.35876e1 + 0.245730e1 * t94 + 0.98588e0 * r->rs;
  t98 = 0.1e1 / t13;
  t99 = t97 * t98;
  t101 = 0.10000000000000000000e1 * t91 * t99;
  t103 = t37 * t37;
  t104 = 0.1e1 / t103;
  t105 = t32 * t104;
  t109 = 0.70594500000000000000e1 * t92 + 0.61977e1 + 0.504930e1 * t94 + 0.125034e1 * r->rs;
  t110 = 0.1e1 / t40;
  t111 = t109 * t110;
  t115 = t50 * t50;
  t116 = 0.1e1 / t115;
  t117 = t45 * t116;
  t121 = 0.51785000000000000000e1 * t92 + 0.36231e1 + 0.1320390e1 * t94 + 0.99342e0 * r->rs;
  t122 = 0.1e1 / t53;
  t123 = t121 * t122;
  t127 = t30 * (-0.63885170360e-2 * t41 + 0.10000000000000000000e1 * t105 * t111 + t88 - t101 - 0.21973736767207854065e-2 * t54 + 0.58482236226346462070e0 * t117 * t123);
  t131 = t60 * t45;
  t133 = t116 * t121 * t122;
  t136 = -t88 + t101 + t26 * t127 + 0.21973736767207854065e-2 * t60 * t54 - 0.58482236226346462070e0 * t131 * t133;
  r->dfdrs = t136 * t87;
  t137 = t17 * r->z;
  t138 = t137 * t25;
  t142 = 0.4e1 / 0.3e1 * t20 - 0.4e1 / 0.3e1 * t23;
  t143 = t18 * t142;
  t145 = t142 * t30;
  t148 = 0.4e1 * t138 * t58 + t143 * t58 + 0.19751673498613801407e-1 * t145 * t55;
  t152 = 0.95100000000000000000e-1 * t74 - 0.95100000000000000000e-1 * t82;
  r->dfdz = t148 * t87 + t63 * t152;
  r->dfdxt = 0.0e0;
  t154 = t63 * t19;
  t155 = t73 * t73;
  t156 = 0.1e1 / t155;
  t158 = t69 * r->xs[0];
  r->dfdxs[0] = -0.22221700000000000000e-1 * t154 * t156 * t158;
  t161 = t63 * t22;
  t162 = t81 * t81;
  t163 = 0.1e1 / t162;
  t165 = t69 * r->xs[1];
  r->dfdxs[1] = -0.22221700000000000000e-1 * t161 * t163 * t165;

  if(r->order < 2) return;

  t170 = 0.42740000000000000000e0 * t90 * t97 * t98;
  t172 = 0.1e1 / t89 / t10;
  t173 = t2 * t172;
  t174 = t97 * t97;
  t177 = 0.20000000000000000000e1 * t173 * t174 * t98;
  t179 = 0.1e1 / t3 / r->rs;
  t181 = 0.1e1/sqrt(r->rs);
  t183 = -0.18989250000000000000e1 * t179 + 0.1228650e1 * t181 + 0.98588e0;
  t186 = 0.10000000000000000000e1 * t91 * t183 * t98;
  t187 = t89 * t89;
  t188 = 0.1e1 / t187;
  t189 = t2 * t188;
  t190 = t13 * t13;
  t191 = 0.1e1 / t190;
  t194 = 0.16081979498692535067e2 * t189 * t174 * t191;
  t199 = 0.1e1 / t103 / t37;
  t200 = t32 * t199;
  t201 = t109 * t109;
  t207 = -0.35297250000000000000e1 * t179 + 0.2524650e1 * t181 + 0.125034e1;
  t211 = t103 * t103;
  t212 = 0.1e1 / t211;
  t213 = t32 * t212;
  t214 = t40 * t40;
  t215 = 0.1e1 / t214;
  t221 = 0.1e1 / t115 / t50;
  t222 = t45 * t221;
  t223 = t121 * t121;
  t229 = -0.25892500000000000000e1 * t179 + 0.6601950e0 * t181 + 0.99342e0;
  t230 = t229 * t122;
  t233 = t115 * t115;
  t234 = 0.1e1 / t233;
  t235 = t45 * t234;
  t236 = t53 * t53;
  t237 = 0.1e1 / t236;
  t241 = 0.41096000000000000000e0 * t104 * t109 * t110 - 0.20000000000000000000e1 * t200 * t201 * t110 + 0.10000000000000000000e1 * t105 * t207 * t110 + 0.32163958997385070134e2 * t213 * t201 * t215 - t170 + t177 - t186 - t194 + 0.13012297560362087810e0 * t133 - 0.11696447245269292414e1 * t222 * t223 * t122 + 0.58482236226346462070e0 * t117 * t230 + 0.17315859105681463759e2 * t235 * t223 * t237;
  t242 = t30 * t241;
  t247 = t221 * t223 * t122;
  t251 = t116 * t229 * t122;
  t255 = t234 * t223 * t237;
  t258 = t170 - t177 + t186 + t194 + t26 * t242 - 0.13012297560362087810e0 * t60 * t133 + 0.11696447245269292414e1 * t131 * t247 - 0.58482236226346462070e0 * t131 * t251 - 0.17315859105681463759e2 * t131 * t255;
  r->d2fdrs2 = t258 * t87;
  t264 = t145 * t45;
  t267 = 0.4e1 * t138 * t127 + t143 * t127 + 0.21973736767207854065e-2 * t145 * t54 - 0.58482236226346462070e0 * t264 * t133;
  r->d2fdrsz = t136 * t152 + t267 * t87;
  r->d2fdrsxt = 0.0e0;
  t270 = t136 * t19;
  r->d2fdrsxs[0] = -0.22221700000000000000e-1 * t270 * t156 * t158;
  t274 = t136 * t22;
  r->d2fdrsxs[1] = -0.22221700000000000000e-1 * t274 * t163 * t165;
  t278 = t17 * t25;
  t281 = t137 * t142;
  t284 = t20 * t20;
  t286 = t23 * t23;
  t289 = 0.4e1 / 0.9e1 / t284 + 0.4e1 / 0.9e1 / t286;
  t290 = t18 * t289;
  t292 = t289 * t30;
  t295 = 0.12e2 * t278 * t58 + 0.8e1 * t281 * t58 + t290 * t58 + 0.19751673498613801407e-1 * t292 * t55;
  r->d2fdz2 = 0.2e1 * t148 * t152 + t295 * t87;
  r->d2fdzxt = 0.0e0;
  t299 = t148 * t19;
  t303 = t63 * t156;
  r->d2fdzxs[0] = -0.22221700000000000000e-1 * t299 * t156 * t158 - 0.22221699999999999999e-1 * t303 * t158;
  t306 = t148 * t22;
  t310 = t63 * t163;
  r->d2fdzxs[1] = -0.22221700000000000000e-1 * t306 * t163 * t165 + 0.22221699999999999999e-1 * t310 * t165;
  r->d2fdxt2 = 0.0e0;
  r->d2fdxtxs[0] = 0.0e0;
  r->d2fdxtxs[1] = 0.0e0;
  t314 = 0.1e1 / t155 / t73;
  t315 = t154 * t314;
  t316 = t64 * t64;
  t319 = t316 / t66 / t65;
  t320 = t319 * t70;
  t324 = t156 * t64 * t68;
  r->d2fdxs2[0] = 0.10384941133333333333e-1 * t315 * t320 - 0.22221700000000000000e-1 * t154 * t324;
  r->d2fdxs2[1] = 0.0e0;
  t328 = 0.1e1 / t162 / t81;
  t329 = t161 * t328;
  t330 = t319 * t78;
  t334 = t163 * t64 * t68;
  r->d2fdxs2[2] = 0.10384941133333333333e-1 * t329 * t330 - 0.22221700000000000000e-1 * t161 * t334;

  if(r->order < 3) return;

  t337 = t174 * t97;
  t340 = 0.60000000000000000000e1 * t189 * t337 * t98;
  t343 = 0.60000000000000000000e1 * t173 * t99 * t183;
  t347 = 0.48245938496077605201e2 * t189 * t183 * t191 * t97;
  t354 = 0.12822000000000000000e1 * t172 * t174 * t98;
  t360 = 0.96491876992155210402e2 * t2 / t187 / t10 * t337 * t191;
  t362 = 0.1e1 / t3 / t8;
  t364 = 0.1e1/POW_3_2(r->rs);
  t369 = 0.10000000000000000000e1 * t91 * (0.28483875000000000000e1 * t362 - 0.6143250e0 * t364) * t98;
  t377 = 0.51726012919273400301e3 * t2 / t187 / t89 * t337 / t190 / t13;
  t384 = 0.64110000000000000000e0 * t90 * t183 * t98;
  t387 = 0.10310157056611784231e2 * t188 * t174 * t191;
  t403 = t354 - 0.12328800000000000000e1 * t199 * t201 * t110 - 0.39036892681086263431e0 * t247 - t384 - t387 + 0.61644000000000000000e0 * t104 * t207 * t110 + 0.19827150884348052633e2 * t212 * t201 * t215 + 0.19518446340543131715e0 * t251 + 0.57791679765211885293e1 * t255 + t343 - t347 - 0.60000000000000000000e1 * t200 * t111 * t207 + 0.96491876992155210402e2 * t213 * t207 * t215 * t109;
  t411 = t201 * t109;
  t415 = t223 * t121;
  t440 = 0.1e1 / t233 / t50;
  t447 = 0.38838750000000000000e1 * t362 - 0.33009750e0 * t364;
  t452 = 0.1e1 / t233 / t115;
  t455 = 0.1e1 / t236 / t53;
  t459 = -0.35089341735807877242e1 * t222 * t123 * t229 + 0.51947577317044391277e2 * t235 * t229 * t237 * t121 - t340 + t360 - t369 - t377 + 0.60000000000000000000e1 * t213 * t411 * t110 + 0.35089341735807877242e1 * t235 * t415 * t122 - 0.19298375398431042081e3 * t32 / t211 / t37 * t411 * t215 + 0.10000000000000000000e1 * t105 * (0.52945875000000000000e1 * t362 - 0.12623250e1 * t364) * t110 + 0.20690405167709360120e4 * t32 / t211 / t103 * t411 / t214 / t40 - 0.10389515463408878255e3 * t45 * t440 * t415 * t237 + 0.58482236226346462070e0 * t117 * t447 * t122 + 0.10254018858216406658e4 * t45 * t452 * t415 * t455;
  t490 = t340 - t343 + t347 - 0.19518446340543131715e0 * t60 * t251 - 0.57791679765211885293e1 * t60 * t255 - t354 - t360 + t369 + t377 + t26 * t30 * (t403 + t459) + 0.39036892681086263431e0 * t60 * t247 + 0.10389515463408878255e3 * t131 * t440 * t415 * t237 - 0.58482236226346462070e0 * t131 * t116 * t447 * t122 - 0.10254018858216406658e4 * t131 * t452 * t415 * t455 + t384 + t387 - 0.35089341735807877242e1 * t131 * t234 * t415 * t122 + 0.35089341735807877242e1 * t131 * t221 * t121 * t230 - 0.51947577317044391277e2 * t131 * t234 * t229 * t237 * t121;
  r->d3fdrs3 = t490 * t87;
  r->d3fdrs2z = (0.4e1 * t138 * t242 + t143 * t242 - 0.13012297560362087810e0 * t145 * t133 + 0.11696447245269292414e1 * t264 * t247 - 0.58482236226346462070e0 * t264 * t251 - 0.17315859105681463759e2 * t264 * t255) * t87 + t258 * t152;
  r->d3fdrsz2 = (0.12e2 * t278 * t127 + 0.8e1 * t281 * t127 + t290 * t127 + 0.21973736767207854065e-2 * t292 * t54 - 0.58482236226346462070e0 * t292 * t45 * t133) * t87 + 0.2e1 * t267 * t152;
  r->d3fdrszxt = 0.0e0;
  r->d3fdrszxs[0] = -0.22221700000000000000e-1 * t267 * t19 * t156 * t158 - 0.22221699999999999999e-1 * t136 * t156 * t158;
  r->d3fdrszxs[1] = -0.22221700000000000000e-1 * t267 * t22 * t163 * t165 + 0.22221699999999999999e-1 * t136 * t163 * t165;
  r->d3fdrs2xt = 0.0e0;
  r->d3fdrsxt2 = 0.0e0;
  r->d3fdrsxtxs[0] = 0.0e0;
  r->d3fdrsxtxs[1] = 0.0e0;
  r->d3fdrs2xs[0] = -0.22221700000000000000e-1 * t258 * t19 * t156 * t158;
  r->d3fdrs2xs[1] = -0.22221700000000000000e-1 * t258 * t22 * t163 * t165;
  r->d3fdrsxs2[0] = 0.10384941133333333333e-1 * t270 * t314 * t320 - 0.22221700000000000000e-1 * t270 * t324;
  r->d3fdrsxs2[1] = 0.0e0;
  r->d3fdrsxs2[2] = 0.10384941133333333333e-1 * t274 * t328 * t330 - 0.22221700000000000000e-1 * t274 * t334;
  t565 = -0.8e1 / 0.27e2 / t284 / t19 + 0.8e1 / 0.27e2 / t286 / t22;
  r->d3fdz3 = (0.24e2 * r->z * t25 * t58 + 0.36e2 * t17 * t142 * t58 + 0.12e2 * t137 * t289 * t58 + t18 * t565 * t58 + 0.19751673498613801407e-1 * t565 * t30 * t55) * t87 + 0.3e1 * t295 * t152;
  r->d3fdz2xt = 0.0e0;
  r->d3fdzxt2 = 0.0e0;
  r->d3fdzxtxs[0] = 0.0e0;
  r->d3fdzxtxs[1] = 0.0e0;
  r->d3fdz2xs[0] = -0.22221700000000000000e-1 * t295 * t19 * t156 * t158 - 0.44443399999999999998e-1 * t148 * t156 * t158;
  r->d3fdz2xs[1] = -0.22221700000000000000e-1 * t295 * t22 * t163 * t165 + 0.44443399999999999998e-1 * t148 * t163 * t165;
  r->d3fdzxs2[0] = 0.10384941133333333333e-1 * t299 * t314 * t320 - 0.22221700000000000000e-1 * t299 * t324 + 0.10384941133333333333e-1 * t63 * t314 * t320 - 0.22221699999999999999e-1 * t303 * t69;
  r->d3fdzxs2[1] = 0.0e0;
  r->d3fdzxs2[2] = 0.10384941133333333333e-1 * t306 * t328 * t330 - 0.22221700000000000000e-1 * t306 * t334 - 0.10384941133333333333e-1 * t63 * t328 * t330 + 0.22221699999999999999e-1 * t310 * t69;
  r->d3fdxt3 = 0.0e0;
  r->d3fdxt2xs[0] = 0.0e0;
  r->d3fdxt2xs[1] = 0.0e0;
  r->d3fdxtxs2[0] = 0.0e0;
  r->d3fdxtxs2[1] = 0.0e0;
  r->d3fdxtxs2[2] = 0.0e0;
  t609 = t155 * t155;
  r->d3fdxs3[0] = -0.44840847956945844834e-3 * t154 / t609 * t70 * r->xs[0] + 0.31154823399999999999e-1 * t315 * t319 * r->xs[0];
  r->d3fdxs3[1] = 0.0e0;
  r->d3fdxs3[2] = 0.0e0;
  t618 = t162 * t162;
  r->d3fdxs3[3] = -0.44840847956945844834e-3 * t161 / t618 * t78 * r->xs[1] + 0.31154823399999999999e-1 * t329 * t319 * r->xs[1];

  if(r->order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  xc_gga_c_am05_func

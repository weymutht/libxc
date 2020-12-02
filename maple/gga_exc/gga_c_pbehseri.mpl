(*
 Copyright (C) 2020 Vera von Burg, Thomas Weymuth

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* prefix:
  gga_c_pbehseri_params *params;

  assert(p->params != NULL);
  params = (gga_c_pbehseri_params * )(p->params);
*)

$define lda_c_pw_params
$define lda_c_pw_modified_params
$include "lda_c_pw.mpl"

$ifdef gga_c_pbehseri_params
params_a_beta  := 0.06672455060314922:
params_a_gamma := (1 - log(2))/Pi^2:
params_a_BB    := 1:
$endif

mgamma := params_a_gamma:
mbeta  := (rs, t) -> params_a_beta:
BB     := params_a_BB:
mu     := params_a_mu:

tp   := (rs, z, xt) -> tt(rs, z, xt):

(* Equation (8) *)
A := (rs, z, t) ->
  mbeta(rs, t)/(mgamma*(exp(-f_pw(rs, z)/(mgamma*mphi(z)^3)) - 1)):

(* Equation (7) *)
f1 := (rs, z, t) -> t^2 + BB*A(rs, z, t)*t^4:
f2 := (rs, z, t) -> mbeta(rs, t)*f1(rs, z, t)/(mgamma*(1 + A(rs, z, t)*f1(rs, z, t))):

fH := (rs, z, t) -> mgamma*mphi(z)^3*log(1 + f2(rs, z, t)):

f_pbe  := (rs, z, xt, xs0, xs1) ->
  f_pw(rs, z) + fH(rs, z, tp(rs, z, xt)):

n := (rs) -> 3/(4*Pi*rs^3):
b_D := 32/(3*Pi):
b_gamma := 4.7125:
b_beta := 163.44:
b_A := 3.2581:
g0 := (rs) -> b_D*((b_gamma + rs)^(3/2) + b_beta)*exp(-b_A*sqrt(b_gamma + rs)):
d2erf := (rs, z, xt, xs0, xs1) -> 2*f_pbe(rs, z, xt, xs0, xs1)/(Pi*n(rs)*(g0(rs) - 1/2)):
d1erf := (rs, z, xt, xs0, xs1) -> -2*d2erf(rs, z, xt, xs0, xs1)^2*sqrt(Pi)*n(rs)*g0(rs)/(3*f_pbe(rs, z, xt, xs0, xs1)):

f  := (rs, z, xt, xs0, xs1) -> f_pbe(rs, z, xt, xs0, xs1)/(1 + d1erf(rs, z, xt, xs0, xs1)*mu + d2erf(rs, z, xt, xs0, xs1)*mu^2):


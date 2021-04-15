(*
 Copyright (C) 2021 V. von Burg

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* prefix:
  gga_x_gws_params *params;

  assert(p->params != NULL);
  params = (gga_x_gws_params * )(p->params);
*)

params_a_kappa := 0.8040:
params_a_b_pbe := 0.2195149727645171:
params_a_alpha := 19.0:
mu             := params_a_mu :

coeff_nu_c := 3.375 :
# kF is defined in utils.mpl
mu_red := (rs) -> mu / (2*kF(rs,0)):
nu_red := (rs) -> mu_red(rs) / coeff_nu_c:
nu_red2 := (rs) ->  nu_red(rs)^2 :

coeff_b_c1 := (rs) -> 1 + 22*nu_red2(rs) + 144*(nu_red2(rs))^2:
coeff_b_c2 := (rs) -> 2*nu_red2(rs)*(-7 + 72*nu_red2(rs)):
coeff_b_c3 := (rs) -> -864*nu_red2(rs)^2*(-1 + 2*nu_red2(rs)):

coeff_b_c4 := (rs) -> nu_red2(rs)*(-3 - 24*nu_red2(rs) + 32*nu_red2(rs)^2 + 8*nu_red(rs)*sqrt(Pi)*erf(1/(2*nu_red(rs)))) :

tcs_b := (rs) -> (-coeff_b_c1(rs) + coeff_b_c2(rs)*exp(1/(4*mu_red(rs)^2)))/( coeff_b_c3(rs) + 54*coeff_b_c4(rs)*exp(1/(4*mu_red(rs)^2))) :

(* gws_b := (mu_red, nu_red, nu_red2, rs) ->  ( params_a_b_pbe / tcs_b(0.0, 0.0, 0.0, 0.0,rs))*tcs_b(mu_red(rs), nu_red(rs), nu_red2(rs), rs)*exp(-params_a_alpha*mu_red(rs)^2) *)
(* tcs_b(0) = 1 *)
gws_b := (rs) ->  (params_a_b_pbe)*tcs_b(rs)*exp(-params_a_alpha*mu_red(rs)^2):

gws_f0 := (s, rs) -> 1 + params_a_kappa*(1 - params_a_kappa/(params_a_kappa + gws_b(rs)*s^2)):

fsr_x_lda := (rs) -> -(18/Pi^2)^(1/3)*(1/rs) * ( 3/8 - mu_red(rs)*(sqrt(Pi)*erf(0.5*mu_red(rs)) + (2*mu_red(rs) - 4*mu_red(rs)^3)*exp(-1/(4*mu_red(rs)^2)) - 3*mu_red(rs) + 4*mu_red(rs)^3 )) :

x2s := 1/(2*(3*Pi^2)^(1/3)):
gws_f := (x, rs) -> gws_f0(x2s*x, rs):

f := (rs, z, xt, xs0, xs1) -> fsr_x_lda(rs)*gws_f(xs0, rs) :

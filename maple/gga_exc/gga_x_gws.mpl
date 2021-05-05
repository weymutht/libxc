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

# kF is defined in utils.mpl
mu_red := (rs) -> mu / (2*kF(rs,0)):
mu_red2 := (rs) ->  mu_red(rs)^2 :

coeff_b_c1 := (rs) -> 1 + 22*mu_red2(rs) + 144*(mu_red2(rs))^2:
coeff_b_c2 := (rs) -> 2*mu_red2(rs)*(-7 + 72*mu_red2(rs)):
coeff_b_c3 := (rs) -> -864*mu_red2(rs)^2*(-1 + 2*mu_red2(rs)):
coeff_b_c4 := (rs) -> mu_red2(rs)*(-3 - 24*mu_red2(rs) + 32*mu_red2(rs)^2 + 8*mu_red(rs)*sqrt(Pi)*erf(1/(2*mu_red(rs)))) :

# my_piecewise is used to avert tcs_b being undefined; insert arbitrary non-zero value for the case that mu_red is very small
tcs_b := (rs) -> ((-coeff_b_c1(rs) + coeff_b_c2(rs)*exp(1/(4*my_piecewise3(evalb(mu_red(rs) > 10^(-9) ), mu_red2(rs),0.25))))/ ( coeff_b_c3(rs)  + 54*coeff_b_c4(rs)*exp(1/(4*my_piecewise3(evalb(mu_red(rs) > 10^(-9)),mu_red2(rs),0.25))))) :

f_x_lda := (rs) ->  -(18/Pi^2)^(1/3)*(1/rs)*(3/8):

fsr_x_lda := (rs) ->  -(18/Pi^2)^(1/3)*(1/rs)*(- mu_red(rs)*(sqrt(Pi)*erf(0.5/(my_piecewise3(evalb(mu_red(rs)> 10^(-9)),mu_red(rs),0.5))) + (2*mu_red(rs) - 4*mu_red(rs)^3)*exp(-1/(4*my_piecewise3(evalb(mu_red(rs)> 10^(-9)),mu_red2(rs),0.25) )) - 3*mu_red(rs) + 4*mu_red(rs)^3 ))*my_piecewise3(evalb(mu_red(rs) > 10^(-9)), 1.0, 0.0) + f_x_lda(rs) :

(* tcs_b(0) = 7/81 *)

gws_b_pre := (rs) ->  (params_a_b_pbe/(7.0/81.0))*exp(-params_a_alpha*mu_red2(rs)):

# Protect against divergence again and ensure that correct overall formula is obtained
gws_b := (rs) ->  gws_b_pre(rs)*my_piecewise3(evalb(mu_red(rs) > 10^(-9)),tcs_b(rs),(7.0/81.0)):

gws_f0 := (s, rs) -> 1 + params_a_kappa*(1 - params_a_kappa/(params_a_kappa + gws_b(rs)*s^2)):

x2s := 1/(2*(3*Pi^2)^(1/3)):

# Argument will be 1/(2*(3*Pi^2)^(1/3))*xs0
#gws_f := (x, rs) -> gws_f0(x2s*x, rs):
gws_f := (x, rs) -> gws_f0(x, rs):

f := (rs, z, xt, xs0, xs1) -> fsr_x_lda(rs)*gws_f(xs0, rs) :

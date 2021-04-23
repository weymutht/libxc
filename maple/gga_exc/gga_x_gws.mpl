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

#tcs_b := (rs) -> (-coeff_b_c1(rs) + coeff_b_c2(rs)*exp(1/(4*mu_red2(rs))))/( coeff_b_c3(rs) + 54*coeff_b_c4(rs)*exp(1/(4*mu_red2(rs)))) :

# This works, sets tcs_b to -1 if mu=0 and the normal value else
# but toulouse05a actually claims that tcs_b(0) = 7/81
#tcs_b := (rs) -> (-coeff_b_c1(rs) + coeff_b_c2(rs)*exp(1/(4*my_piecewise3(mu_red2(rs),mu_red2(rs),1.0)))*my_piecewise3(mu_red2(rs), 1.0, 0.0))/( coeff_b_c3(rs) + 54*coeff_b_c4(rs)*exp(1/(4*my_piecewise3(mu_red2(rs),mu_red2(rs),1.0)))*my_piecewise3(mu_red2(rs), 1.0, 0.0) ) :

#tcs_b := (rs) -> (-coeff_b_c1(rs) + coeff_b_c2(rs)*exp(1/(4*mu_red2(rs))))/( coeff_b_c3(rs) + 54*coeff_b_c4(rs)*exp(1/(4*mu_red2(rs))))*my_piecewise3(mu_red2(rs), 1.0, 7.0/81.0) :

tcs_b := (rs) -> (-coeff_b_c1(rs) + coeff_b_c2(rs)*exp(1/(4*my_piecewise3(mu_red2(rs), mu_red2(rs),0.25))))/( coeff_b_c3(rs) + 54*coeff_b_c4(rs)*exp(1/(4*my_piecewise3(mu_red2(rs),mu_red2(rs),0.25)  )))*my_piecewise3(mu_red2(rs), 1.0, 7.0/81.0) :

f_x_lda := (rs) ->  -(18/Pi^2)^(1/3)*(1/rs)*(3/8):

# The mu/mu factor is introduced to set the first term to zero in the case that mu = 0.0,
# since the workflow apparently does not allow an if statement on "mu"

fsr_x_lda := (rs) ->  -(18/Pi^2)^(1/3)*(1/rs)*(- mu_red(rs)*(sqrt(Pi)*erf(0.5/(mu_red(rs)*my_piecewise3(mu_red(rs),mu_red(rs),0.5))) + (2*mu_red(rs) - 4*mu_red(rs)^3)*exp(-1/(4*mu_red2(rs)*my_piecewise3(mu_red2(rs),mu_red2(rs),0.25) )) - 3*mu_red(rs) + 4*mu_red(rs)^3 ))*my_piecewise3(mu, 1.0, 0.0) + f_x_lda(rs) :

#fsr_x_lda := (rs) -> -(18/Pi^2)^(1/3)*(1/rs)*( 3/8 - mu_red(rs)*(sqrt(Pi)*erf(0.5/mu_red(rs)) + (2*mu_red(rs) - 4*mu_red(rs)^3)*exp(-1/(4*mu_red2(rs))) - 3*mu_red(rs) + 4*mu_red(rs)^3 )) :

# This resolves the nan but is wrong formula
#fsr_x_lda := (rs) ->  -(18/Pi^2)^(1/3)*(1/rs)*(- mu_red(rs)*(sqrt(Pi)) + (2*mu_red(rs) - 4*mu_red(rs)^3) - 3*mu_red(rs) + 4*mu_red(rs)^3 ) + f_x_lda(rs) :

(* - sign comes from tcs_b(0) = -1 *)
#gws_b := (rs) ->  -(params_a_b_pbe)*tcs_b(rs)*exp(-params_a_alpha*mu_red2(rs)):
(* tcs_b(0) = 7/81 *)
gws_b := (rs) ->  (params_a_b_pbe/(7.0/81.0))*tcs_b(rs)*exp(-params_a_alpha*mu_red2(rs)):

gws_f0 := (s, rs) -> 1 + params_a_kappa*(1 - params_a_kappa/(params_a_kappa + gws_b(rs)*s^2)):
 
x2s := 1/(2*(3*Pi^2)^(1/3)):

# Argument will be 1/(2*(3*Pi^2)^(1/3))*xs0
gws_f := (x, rs) -> gws_f0(x2s*x, rs):
 
#f := (rs, z, xt, xs0, xs1) -> fsr_x_lda(rs) :
f := (rs, z, xt, xs0, xs1) -> fsr_x_lda(rs)*gws_f(xs0, rs) :

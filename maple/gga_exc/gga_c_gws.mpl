(*
 Copyright (C) 2021 Vera von Burg

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* prefix:
  gga_c_gws_params *params;

  assert(p->params != NULL);
  params = (gga_c_gws_params * )(p->params);
*)

$define lda_c_pw_params
$define lda_c_pw_modified_params
$include "lda_c_pmgb06.mpl"

(* $ifdef gga_c_gws_params
params_a_pbe_gamma := (1 - log(2))/Pi^2:
params_a_BB    := 1:
$endif *)

#params_a_alpha := 2.83:
params_a_alpha := 2.78:
# original PBE beta value
params_a_pbe_beta  := 0.06672455060314922:
# beta value given in paper
#params_a_pbe_beta := 0.066725:
# Original PBE value?
params_a_pbe_gamma := (1 - log(2))/Pi^2:
# Value given in paper
#params_a_pbe_gamma := 0.031091:

mu := params_a_mu :

(* In lda_c_pgb06.mpl, p_a_cam_omega is used as the range-separation parameter. Set its value to the one of mu here. *)
p_a_cam_omega := mu:

# Replica from pmgb06.mpl so that no two functions are called 'f'
fsr_c_lda := (rs, z) -> f_pw(rs,z) - pmgb_ec_LR(rs,z):

gws_beta := (rs, z) -> params_a_pbe_beta*(fsr_c_lda(rs, z) /  f_pw(rs, z))^params_a_alpha:

tp   := (rs, z, xt) -> tt(rs, z, xt):

(* Equation (6) *)
A := (rs, z, t) ->
  gws_beta(rs, z)/(params_a_pbe_gamma*(exp(-fsr_c_lda(rs, z)/(params_a_pbe_gamma)) - 1)):

f1 := (rs, z, t) -> t^2 + A(rs, z, t)*t^4:

f2 := (rs, z, t) -> params_a_pbe_beta(rs, z)*f1(rs, z, t)/(params_a_pbe_gamma*(1 + A(rs, z, t)*f1(rs, z, t))):

fH := (rs, z, t) -> params_a_pbe_gamma*log(1 + f2(rs, z, t)):

f_gws := (rs, z, xt, xs0, xs1) -> fsr_c_lda(rs,z) + fH(rs, z, tp(rs,z,xt)):
#f_gws := (rs, z, xt, xs0, xs1) -> fsr_c_lda(rs,z) :

f  := (rs, z, xt, xs0, xs1) -> f_gws(rs, z, xt, xs0, xs1):

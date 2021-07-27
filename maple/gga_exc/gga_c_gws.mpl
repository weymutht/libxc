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

#params_a_alpha := 2.83:
params_a_alpha := 2.78:
# original PBE value
params_a_pbe_beta  := 0.06672455060314922:
# beta value given in paper
#params_a_pbe_beta := 0.066725:
# Original PBE value
params_a_pbe_gamma := (1 - log(2))/(Pi^2):
# Value given in paper
#params_a_pbe_gamma := 0.031091:

mu := params_a_mu :

(* In lda_c_pgb06.mpl, p_a_cam_omega is the range-separation parameter. Set its value to the one of mu here. *)
p_a_cam_omega := mu :

# Rename of 'f' from pmgb06.mpl so that no two functions are called 'f'
fsr_c_lda := (rs, z) -> f_pw(rs, z) - pmgb_ec_LR(rs, z):

gws_beta := (rs, z) -> (params_a_pbe_beta*( fsr_c_lda(rs, z)/f_pw(rs, z) )^params_a_alpha)*my_piecewise3(evalb((fsr_c_lda(rs,z)/f_pw(rs,z)) <= 0.0), 0.0, 1.0 ) :

tp   := (rs, z, xt) -> tt(rs, z, xt):

tolerance := 10^(-20) : 
undefined := evalb(fsr_c_lda(rs,z) <= tolerance) :

(* If sr lda correlation energy approaches zero, A will become undefined as we will have a division by zero. 
In this limit, however, H becomes zero anyways due to beta approaching zero. *)
A_den := (rs, z, t) -> exp(-fsr_c_lda(rs,z) + my_piecewise3(undefined, 1.0, ) / params_a_pbe_gamma)  - 1.0 :

(* Equation (6) *)
A := (rs, z, t) -> gws_beta(rs, z)/(params_a_pbe_gamma*A_den(rs,z,t)):

f1 := (rs, z, t) -> t^2 + A(rs, z, t)*t^4:

f2 := (rs, z, t) -> gws_beta(rs,z)*f1(rs, z, t)/(params_a_pbe_gamma*(1.0 + A(rs, z, t)*f1(rs, z, t))):

fH := (rs, z, t) -> params_a_pbe_gamma*log(1.0 + f2(rs, z, t)):

f_gws := (rs, z, xt, xs0, xs1) -> fsr_c_lda(rs, z) + fH(rs, z, tp(rs,z,xt))*my_piecewise3(undefined, 0.0, 1.0):

f  := (rs, z, xt, xs0, xs1) -> f_gws(rs, z, xt, xs0, xs1):

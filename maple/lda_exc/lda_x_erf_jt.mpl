(*
 Copyright (C) 2021 V. von Burg

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: lda_exc *)

$define lda_x_params
$include "lda_x.mpl"

mu := params_a_mu :
kF     := (rs) -> ((9*Pi/4)^(1/3))/rs:
mu_red := (rs) -> mu / (2*kF(rs)):

fsr_x_lda := (mu_red, rs) -> -(18/Pi^2)^(1/3)*(1/rs) * ( 3/8 - mu_red(rs)*(sqrt(Pi)*erf(0.5*mu_red(rs)) + (2*mu_red(rs) - 4*mu_red(rs)^3)*exp(-1/(4*mu_red(rs)^2)) - 3*mu_red(rs) + 4*mu_red(rs)^3 )) :

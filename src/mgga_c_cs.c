/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

#define XC_MGGA_C_CS          72 /* Colle and Salvetti */

/*
    [1] Eq. (15) in https://doi.org/10.1103/PhysRevB.37.785
    [2] CS2 in http://www.molpro.net/info/2012.1/doc/manual/node192.html

  there is a gamma(r) in [1] absent in [2]. This should be irrelevant
  for spin unpolarized. In any case, it seems that even in that case,
  libxc does not give the same as molpro, but I am unable to
  understand why...
*/

#include "maple2c/mgga_exc/mgga_c_cs.c"
#include "work_mgga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_mgga_c_cs = {
  XC_MGGA_C_CS,
  XC_CORRELATION,
  "Colle and Salvetti",
  XC_FAMILY_MGGA,
  {&xc_ref_Colle1975_329, &xc_ref_Lee1988_785, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_TAU | XC_FLAGS_NEEDS_LAPLACIAN | MAPLE2C_FLAGS,
  1e-15,
  {0, NULL, NULL, NULL, NULL},
  NULL, NULL,
  NULL, NULL, &work_mgga,
};

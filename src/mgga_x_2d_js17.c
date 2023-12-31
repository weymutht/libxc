/*
 Copyright (C) 2006-2008 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

/* Local tau approximation */

#define XC_MGGA_X_2D_JS17         609 /* JS17 meta-GGA for 2D */

#include "maple2c/mgga_exc/mgga_x_2d_js17.c"
#include "work_mgga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_mgga_x_2d_js17 = {
  XC_MGGA_X_2D_JS17,
  XC_EXCHANGE,
  "JS17 meta-GGA for 2D",
  XC_FAMILY_MGGA,
  {&xc_ref_Jana2017_4804, NULL, NULL, NULL, NULL},
  XC_FLAGS_2D | XC_FLAGS_NEEDS_TAU | MAPLE2C_FLAGS,
  1e-15,
  {0, NULL, NULL, NULL, NULL},
  NULL, NULL,
  NULL, NULL, &work_mgga,
};

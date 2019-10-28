/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_GGA_C_HCTH_A        97 /* HCTH-A                                   */

#include "maple2c/gga_exc/gga_c_hcth_a.c"
#include "work_gga.c"

const xc_func_info_type xc_func_info_gga_c_hcth_a = {
  XC_GGA_C_HCTH_A,
  XC_CORRELATION,
  "HCTH-A",
  XC_FAMILY_GGA,
  {&xc_ref_Hamprecht1998_6264, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-16,
  0, NULL, NULL,
  NULL, NULL,
  NULL, work_gga, NULL
};

/*
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

#define XC_MGGA_X_R2SCAN         497 /* Re-regularized SCAN exchange */
#define XC_MGGA_X_R2SCAN01       645 /* Re-regularized SCAN exchange with larger value for eta */

typedef struct{
  double c1, c2, d, k1;
  double eta, dp2;
} mgga_x_r2scan_params;

#define N_PAR 6
static const char *names[N_PAR] = {"_c1", "_c2", "_d", "_k1", "_eta", "_dp2"};
static const char *desc[N_PAR] = {"c1 parameter", "c2 parameter", "d parameter",
  "k1 parameter", "eta parameter", "dp2 parameter"};

static const double par_r2scan[N_PAR] = {0.667, 0.8, 1.24, 0.065, 0.001, 0.361};
static const double par_r2scan01[N_PAR] = {0.667, 0.8, 1.24, 0.065, 0.01, 0.361};

static void
mgga_x_r2scan_init(xc_func_type *p)
{
  assert(p!=NULL && p->params == NULL);
  p->params = libxc_malloc(sizeof(mgga_x_r2scan_params));
}


#include "maple2c/mgga_exc/mgga_x_r2scan.c"
#include "work_mgga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_mgga_x_r2scan = {
  XC_MGGA_X_R2SCAN,
  XC_EXCHANGE,
  "Re-regularized SCAN exchange by Furness et al",
  XC_FAMILY_MGGA,
  {&xc_ref_Furness2020_8208, &xc_ref_Furness2020_9248, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_TAU | MAPLE2C_FLAGS,
  1e-11,
  {N_PAR, names, desc, par_r2scan, set_ext_params_cpy},
  mgga_x_r2scan_init, NULL,
  NULL, NULL, &work_mgga
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_mgga_x_r2scan01 = {
  XC_MGGA_X_R2SCAN01,
  XC_EXCHANGE,
  "Re-regularized SCAN exchange by Furness et al with larger value for eta",
  XC_FAMILY_MGGA,
  {&xc_ref_Furness2020_8208, &xc_ref_Furness2020_9248, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_TAU | MAPLE2C_FLAGS,
  1e-11,
  {N_PAR, names, desc, par_r2scan01, set_ext_params_cpy},
  mgga_x_r2scan_init, NULL,
  NULL, NULL, &work_mgga
};

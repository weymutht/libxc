/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_HYB_GGA_X_LCGAU 708      /* Long-range Gaussian */
#define XC_HYB_GGA_X_LCGAU_CORE 709 /* Long-range Gaussian fitted to core excitations */
#define XC_HYB_GGA_X_LC2GAU 710     /* Long-range Gaussian 2 */

static void
hyb_gga_x_lgau_init(xc_func_type *p)
{
  int hyb_type[4] = {XC_HYB_ERF_SR, XC_HYB_FOCK, XC_HYB_GAUSSIAN_SR, XC_HYB_GAUSSIAN_SR};
  double hyb_coeff[4] = {-1.0, 1.0, 0.0, 0.0};
  double hyb_omega[4] = {0.0,  0.0, 0.0, 0.0};

  xc_hyb_init(p, 4, hyb_type, hyb_coeff, hyb_omega);
}

#define LCGAU_N_PAR 5
static const char  *lcgau_names[LCGAU_N_PAR]  = {"_a1", "_k1", "_a2", "_k2", "_omega"};
static const char  *lcgau_desc[LCGAU_N_PAR]   = {
  "1/a multiplies the exponent of the exponential",
  "prefactor",
  "1/a multiplies the exponent of the exponential",
  "prefactor",
  "Screening parameter",
};
static const double lcgau_values[LCGAU_N_PAR] = {
  0.011, 18.0, 0.011, 0.0, 0.42
};
static const double lcgau_core_values[LCGAU_N_PAR] = {
  0.0335, 5.9, 0.0335, 0.0, 0.42
};
static const double lc2gau_values[LCGAU_N_PAR] = {
  0.012, 100.0, 0.01046, -101.0, 0.42
};

static void
lcgau_set_ext_params(xc_func_type *p, const double *ext_params)
{
  double a1, a2, k1, k2, omega;

  a1    = get_ext_param(p, ext_params, 0);
  k1    = get_ext_param(p, ext_params, 1);
  a2    = get_ext_param(p, ext_params, 2);
  k2    = get_ext_param(p, ext_params, 3);
  omega = get_ext_param(p, ext_params, 4);

  p->hyb_omega[0] = omega;
  p->hyb_omega[2] = omega/sqrt(a1);
  p->hyb_omega[3] = omega/sqrt(a2);

  p->hyb_coeff[2] = k1*sqrt(a1);
  p->hyb_coeff[3] = k2*sqrt(a2);
}

#include "maple2c/gga_exc/gga_x_lcgau.c"
#include "work_gga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_x_lcgau = {
  XC_HYB_GGA_X_LCGAU,
  XC_EXCHANGE,
  "Long-range Gaussian",
  XC_FAMILY_GGA,
  {&xc_ref_Song2007_154109, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS | XC_FLAGS_DEVELOPMENT,
  1e-10,
  {LCGAU_N_PAR, lcgau_names, lcgau_desc, lcgau_values, lcgau_set_ext_params},
  hyb_gga_x_lgau_init, NULL,
  NULL, &work_gga, NULL
};


#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_x_lcgau_core = {
  XC_HYB_GGA_X_LCGAU_CORE,
  XC_EXCHANGE,
  "Long-range Gaussian fitted to core excitations",
  XC_FAMILY_GGA,
  {&xc_ref_Song2008_184113, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS | XC_FLAGS_DEVELOPMENT,
  1e-8,
  {LCGAU_N_PAR, lcgau_names, lcgau_desc, lcgau_core_values, lcgau_set_ext_params},
  hyb_gga_x_lgau_init, NULL,
  NULL, &work_gga, NULL
};


#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_x_lc2gau = {
  XC_HYB_GGA_X_LC2GAU,
  XC_EXCHANGE,
  "Long-range Gaussian 2",
  XC_FAMILY_GGA,
  {&xc_ref_Song2009_144108, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS | XC_FLAGS_DEVELOPMENT,
  1e-8,
  {LCGAU_N_PAR, lcgau_names, lcgau_desc, lc2gau_values, lcgau_set_ext_params},
  hyb_gga_x_lgau_init, NULL,
  NULL, &work_gga, NULL
};

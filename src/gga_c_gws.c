/*
 Copyright (C) 2021 V. von Burg

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

/************************************************************************
 Implements a short-range version of the Perdew, Burke & Ernzerhof
 Generalized Gradient Approximation correlation functional
************************************************************************/

#define XC_GGA_C_GWS        998 /* short-range PBE correlation functional by Goll, Werner, Stoll */

typedef struct{
  double alpha, pbe_beta, pbe_gamma, mu;
} gga_c_gws_params;

static void gga_c_gws_init(xc_func_type *p)
{
  gga_c_gws_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = libxc_malloc(sizeof(gga_c_gws_params));
}

#define GWS_N_PAR 4
static const char  *gws_names[GWS_N_PAR]  = {"_alpha", "_pbe_beta", "_pbe_gamma", "_mu"};
static const char  *gws_desc[GWS_N_PAR]   = {
  "Fit coefficient of beta function",
  "PBE beta constant",
  "PBE gamma constant",
  "Range-separation parameter"};

static const double gws_values[GWS_N_PAR] =
  {2.78, 0.06672455060314922, 0.031090690869654895034, 0.4};

static void
gws_lambda_set_ext_params(xc_func_type *p, const double *ext_params)
{
  gga_c_gws_params *params;

  assert(p != NULL && p->params != NULL);
  params = (gga_c_gws_params *) (p->params);

  params->alpha = get_ext_param(p, ext_params, 0);
  params->pbe_beta  = get_ext_param(p, ext_params, 1);
  params->pbe_gamma = get_ext_param(p, ext_params, 2);
  params->mu    = get_ext_param(p, ext_params, 3);
}

#include "decl_gga.h"
#include "maple2c/gga_exc/gga_c_gws.c"
#include "work_gga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_c_gws = {
  XC_GGA_C_GWS,
  XC_CORRELATION,
  "Short-range PBE version of Goll, Werner & Stoll ",
  XC_FAMILY_GGA,
  {&xc_ref_Perdew1996_3865, &xc_ref_Perdew1996_3865_err, &xc_ref_Goll2005_3917, &xc_ref_Goll2006_276, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-12,
  {GWS_N_PAR, gws_names, gws_desc, gws_values, gws_lambda_set_ext_params},
  gga_c_gws_init, NULL,
  NULL, work_gga, NULL
};


/*
 Copyright (C) 2020 Vera von Burg, Thomas Weymuth

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

/************************************************************************
 Implements a short-range version of the Perdew, Burke & Ernzerhof 
 Generalized Gradient Approximation correlation functional.
************************************************************************/

#define XC_GGA_C_PBEHSERI        999 /* short-range version of Perdew, Burke & Ernzerhof correlation */

typedef struct{
  double beta, gamma, BB, mu;
} gga_c_pbehseri_params;


static void gga_c_pbehseri_init(xc_func_type *p)
{
  assert(p!=NULL && p->params == NULL);
  p->params = libxc_malloc(sizeof(gga_c_pbehseri_params));
}

#define PBEHSERI_N_PAR 4
static const char  *pbehseri_names[PBEHSERI_N_PAR]  = {"_beta", "_gamma", "_B", "_mu"};
static const char  *pbehseri_desc[PBEHSERI_N_PAR]   = {
  "beta constant",
  "(1 - ln(2))/Pi^2 in the PBE",
  "Multiplies the A t^2 term. Used in the SPBE functional",
  "short-range parameter"};
static const double pbehseri_values[PBEHSERI_N_PAR] = 
  {0.06672455060314922, 0.031090690869654895034, 1.0, 0.0};

static void
pbehseri_lambda_set_ext_params(xc_func_type *p, const double *ext_params)
{
  gga_c_pbehseri_params *params;

  assert(p != NULL && p->params != NULL);
  params = (gga_c_pbehseri_params *) (p->params);

  params->beta  = get_ext_param(p, ext_params, 0);
  params->gamma = get_ext_param(p, ext_params, 1);
  params->BB    = get_ext_param(p, ext_params, 2);
  params->mu    = get_ext_param(p, ext_params, 3);
}

#include "decl_gga.h"
#include "maple2c/gga_exc/gga_c_pbehseri.c"
#include "work_gga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_c_pbehseri = {
  XC_GGA_C_PBEHSERI,
  XC_CORRELATION,
  "Short-range version of Perdew, Burke & Ernzerhof",
  XC_FAMILY_GGA,
  {&xc_ref_Perdew1996_3865, &xc_ref_Perdew1996_3865_err, &xc_ref_Toulouse2004_062505, &xc_ref_Fromager2007_074111, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-12,
  {PBEHSERI_N_PAR, pbehseri_names, pbehseri_desc, pbehseri_values, pbehseri_lambda_set_ext_params},
  gga_c_pbehseri_init, NULL, 
  NULL, work_gga, NULL
};


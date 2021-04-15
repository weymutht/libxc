/*
 Copyright (C) 2006-2007 M.A.L. Marques
               2019      Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

// TODO: 1) Add this number to the files 2) Add description of what this does 3) add Reference
#define XC_LDA_X_ERF_JT    996   /* Exchange                            */

/*
TODO: Add description
*/

typedef struct{
  double mu;
} lda_x_erf_jt_params;

static void
lda_x_erf_jt_init(xc_func_type *p)
{
  lda_x_erf_jt_params *params;

  assert(p != NULL && p->params == NULL);
  p->params = libxc_malloc(sizeof(lda_x_erf_jt_params));
}

#include "decl_lda.h"
#include "maple2c/lda_exc/lda_x_erf_jt.c"
#include "work_lda.c"

#define ERF_JT_N_PAR 1
static const char  *erf_jt_names[ERF_JT_N_PAR]  = {"mu"};
static const char  *erf_jt_desc[ERF_JT_N_PAR]   = {"Range-separation parameter"};
static const double erf_jt_values[ERF_JT_N_PAR] = {0.4};

static void
set_ext_params(xc_func_type *p, const double *ext_params)
{
  lda_x_erf_jt_params *params;

  assert(p != NULL && p->params != NULL);
  params = (lda_x_erf_jt_params *)(p->params);

  params->mu = get_ext_param(p, ext_params, 0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_lda_x_erf_jt = {
  XC_LDA_X_ERF_JT,
  XC_EXCHANGE,
  "Short-range LDA Exchange by J. Toulouse et al.",
  XC_FAMILY_LDA,
  {&xc_ref_Toulouse2004_1047, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-24,
  {ERF_JT_N_PAR, erf_jt_names, erf_jt_desc, erf_jt_values, set_ext_params},
  lda_x_erf_jt_init, NULL,
  work_lda, NULL, NULL
};


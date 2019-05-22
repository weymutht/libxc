/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_HYB_GGA_XC_B3PW91        401 /* The original (ACM) hybrid of Becke    */
#define XC_HYB_GGA_XC_B3LYP         402 /* The (in)famous B3LYP                  */
#define XC_HYB_GGA_XC_B3P86         403 /* Perdew 86 hybrid similar to B3PW91    */
#define XC_HYB_GGA_XC_MPW3PW        415 /* mixture with the mPW functional       */
#define XC_HYB_GGA_XC_MPW3LYP       419 /* mixture of mPW and LYP                */
#define XC_HYB_GGA_XC_MB3LYP_RC04   437 /* B3LYP with RC04 LDA                   */
#define XC_HYB_GGA_XC_REVB3LYP      454 /* Revised B3LYP                         */
#define XC_HYB_GGA_XC_B3LYPs        459 /* B3LYP* functional                     */
#define XC_HYB_GGA_XC_B3LYP5        475 /* B3LYP with VWN functional 5 instead of RPA */
#define XC_HYB_GGA_XC_B5050LYP      572 /* Like B3LYP but more exact exchange    */
#define XC_HYB_GGA_XC_KMLYP         485 /* Kang-Musgrave hybrid                  */
#define XC_HYB_GGA_XC_APF           409 /* APF hybrid density functional         */
#define XC_HYB_GGA_XC_WC04          611 /* hybrid fitted to carbon NMR shifts    */
#define XC_HYB_GGA_XC_WP04          612 /* hybrid fitted to proton NMR shifts    */

/*************************************************************/
void
xc_hyb_gga_xc_b3pw91_init(xc_func_type *p)
{
  static int   funcs_id  [4] = {XC_LDA_X, XC_GGA_X_B88, XC_LDA_C_PW, XC_GGA_C_PW91};
  static double funcs_coef[4] = {1.0 - 0.20 - 0.72, 0.72, 1.0 - 0.81, 0.81};

  xc_mix_init(p, 4, funcs_id, funcs_coef);
  p->cam_alpha = 0.20;
}

const xc_func_info_type xc_func_info_hyb_gga_xc_b3pw91 = {
  XC_HYB_GGA_XC_B3PW91,
  XC_EXCHANGE_CORRELATION,
  "The original (ACM, B3PW91) hybrid of Becke",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Becke1993_5648, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_b3pw91_init, NULL,
  NULL, NULL, NULL
};


/*************************************************************/
void
xc_hyb_gga_xc_b3lyp_init(xc_func_type *p)
{
  static int   funcs_id  [4] = {XC_LDA_X, XC_GGA_X_B88, XC_LDA_C_VWN_RPA, XC_GGA_C_LYP};
  static double funcs_coef[4] = {1.0 - 0.20 - 0.72, 0.72, 1.0 - 0.81, 0.81};

  xc_mix_init(p, 4, funcs_id, funcs_coef);
  p->cam_alpha = 0.20;
}

const xc_func_info_type xc_func_info_hyb_gga_xc_b3lyp = {
  XC_HYB_GGA_XC_B3LYP,
  XC_EXCHANGE_CORRELATION,
  "B3LYP",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Stephens1994_11623, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_b3lyp_init, NULL,
  NULL, NULL, NULL
};

/*************************************************************/
void
xc_hyb_gga_xc_b3lyp5_init(xc_func_type *p)
{
  static int   funcs_id  [4] = {XC_LDA_X, XC_GGA_X_B88, XC_LDA_C_VWN, XC_GGA_C_LYP};
  static double funcs_coef[4] = {1.0 - 0.20 - 0.72, 0.72, 1.0 - 0.81, 0.81};

  xc_mix_init(p, 4, funcs_id, funcs_coef);
  p->cam_alpha = 0.20;
}

const xc_func_info_type xc_func_info_hyb_gga_xc_b3lyp5 = {
  XC_HYB_GGA_XC_B3LYP5,
  XC_EXCHANGE_CORRELATION,
  "B3LYP with VWN functional 5 instead of RPA",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Stephens1994_11623, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_b3lyp5_init, NULL,
  NULL, NULL, NULL
};


/*************************************************************/
void
xc_hyb_gga_xc_b3p86_init(xc_func_type *p)
{
  static int   funcs_id  [4] = {XC_LDA_X, XC_GGA_X_B88, XC_LDA_C_VWN_RPA, XC_GGA_C_P86};
  static double funcs_coef[4] = {1.0 - 0.20 - 0.72, 0.72, 1.0 - 0.81, 0.81};

  xc_mix_init(p, 4, funcs_id, funcs_coef);
  p->cam_alpha = 0.20;
}

const xc_func_info_type xc_func_info_hyb_gga_xc_b3p86 = {
  XC_HYB_GGA_XC_B3P86,
  XC_EXCHANGE_CORRELATION,
  "B3P86",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_gaussianimplementation, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_b3p86_init, NULL,
  NULL, NULL, NULL
};


/*************************************************************/
void
xc_hyb_gga_xc_mpw3pw_init(xc_func_type *p)
{
  static int   funcs_id  [4] = {XC_LDA_X, XC_GGA_X_MPW91, XC_LDA_C_VWN_RPA, XC_GGA_C_PW91};
  static double funcs_coef[4] = {1.0 - 0.20 - 0.72, 0.72, 1.0 - 0.81, 0.81};

  xc_mix_init(p, 4, funcs_id, funcs_coef);
  p->cam_alpha = 0.20;
}

const xc_func_info_type xc_func_info_hyb_gga_xc_mpw3pw = {
  XC_HYB_GGA_XC_MPW3PW,
  XC_EXCHANGE_CORRELATION,
  "MPW3PW of Adamo & Barone",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Adamo1998_664, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_mpw3pw_init, NULL,
  NULL, NULL, NULL
};


/*************************************************************/
void
xc_hyb_gga_xc_mpw3lyp_init(xc_func_type *p)
{
  static int   funcs_id  [4] = {XC_LDA_X, XC_GGA_X_MPW91, XC_LDA_C_VWN_RPA, XC_GGA_C_LYP};
  static double funcs_coef[4] = {1.0 - 0.218 - 0.709, 0.709, 1.0 - 0.871, 0.871};

  xc_mix_init(p, 4, funcs_id, funcs_coef);
  p->cam_alpha = 0.218;
}

const xc_func_info_type xc_func_info_hyb_gga_xc_mpw3lyp = {
  XC_HYB_GGA_XC_MPW3LYP,
  XC_EXCHANGE_CORRELATION,
  "MPW3LYP",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Zhao2004_6908, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_mpw3lyp_init, NULL,
  NULL, NULL, NULL
};


/*************************************************************/
void
xc_hyb_gga_xc_mb3lyp_rc04_init(xc_func_type *p)
{
  static int   funcs_id  [4] = {XC_LDA_X, XC_GGA_X_B88, XC_LDA_C_RC04, XC_GGA_C_LYP};
  static double funcs_coef[4] = {1.0 - 0.20 - 0.72, 0.72, 1.0 - 0.57*0.81, 0.81};

  xc_mix_init(p, 4, funcs_id, funcs_coef);
  p->cam_alpha = 0.20;
}

const xc_func_info_type xc_func_info_hyb_gga_xc_mb3lyp_rc04 = {
  XC_HYB_GGA_XC_MB3LYP_RC04,
  XC_EXCHANGE_CORRELATION,
  "B3LYP with RC04 LDA",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Tognetti2007_381, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_mb3lyp_rc04_init, NULL,
  NULL, NULL, NULL
};

/*************************************************************/
void
xc_hyb_gga_xc_revb3lyp_init(xc_func_type *p)
{
  static int   funcs_id  [4] = {XC_LDA_X, XC_GGA_X_B88, XC_LDA_C_VWN_RPA, XC_GGA_C_LYP};
  static double funcs_coef[4] = {1.0 - 0.20 - 0.67, 0.67, 1.0 - 0.84, 0.84};

  xc_mix_init(p, 4, funcs_id, funcs_coef);
  p->cam_alpha = 0.20;
}

const xc_func_info_type xc_func_info_hyb_gga_xc_revb3lyp = {
  XC_HYB_GGA_XC_REVB3LYP,
  XC_EXCHANGE_CORRELATION,
  "Revised B3LYP",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Lu2013_64, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_revb3lyp_init, NULL,
  NULL, NULL, NULL
};


/*************************************************************/
void
xc_hyb_gga_xc_b3lyps_init(xc_func_type *p)
{
  static int   funcs_id  [4] = {XC_LDA_X, XC_GGA_X_B88, XC_LDA_C_VWN_RPA, XC_GGA_C_LYP};
  static double funcs_coef[4] = {1.0 - 0.15 - 0.72, 0.72, 1.0 - 0.81, 0.81};

  xc_mix_init(p, 4, funcs_id, funcs_coef);
  p->cam_alpha = 0.15;
}

const xc_func_info_type xc_func_info_hyb_gga_xc_b3lyps = {
  XC_HYB_GGA_XC_B3LYPs,
  XC_EXCHANGE_CORRELATION,
  "B3LYP*",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Reiher2001_48, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_b3lyps_init, NULL,
  NULL, NULL, NULL
};


/*************************************************************/
void
xc_hyb_gga_xc_b5050lyp_init(xc_func_type *p)
{
  static int   funcs_id  [4] = {XC_LDA_X, XC_GGA_X_B88, XC_LDA_C_VWN, XC_GGA_C_LYP};
  static double funcs_coef[4] = {0.08, 0.42, 0.19, 0.81};

  xc_mix_init(p, 4, funcs_id, funcs_coef);
  p->cam_alpha = 0.50;
}

const xc_func_info_type xc_func_info_hyb_gga_xc_b5050lyp = {
  XC_HYB_GGA_XC_B5050LYP,
  XC_EXCHANGE_CORRELATION,
  "B5050LYP",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Shao2003_4807, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_b5050lyp_init, NULL,
  NULL, NULL, NULL
};


/*************************************************************/
void
xc_hyb_gga_xc_kmlyp_init(xc_func_type *p)
{
  static int   funcs_id  [3] = {XC_LDA_X, XC_LDA_C_VWN_RPA, XC_GGA_C_LYP};
  static double funcs_coef[3] = {1.0 - 0.557, 1.0 - 0.448, 0.448};

  xc_mix_init(p, 3, funcs_id, funcs_coef);
  p->cam_alpha = 0.557;
}

const xc_func_info_type xc_func_info_hyb_gga_xc_kmlyp = {
  XC_HYB_GGA_XC_KMLYP,
  XC_EXCHANGE_CORRELATION,
  "Kang-Musgrave hybrid",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Kang2001_11040, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_kmlyp_init, NULL,
  NULL, NULL, NULL
};


/*************************************************************/
void
xc_hyb_gga_xc_apf_init(xc_func_type *p)
{
  /* Functional is 41.1% B3PW91 and 58.9% PBE0 */
  const double fb3pw91 = 0.411;
  const double fpbe0   = 1.0 - fb3pw91;

  /* Exact exchange in B3PW91 and PBE0 */
  const double xb3pw91 = 0.20;
  const double xpbe0   = 0.25;

  int funcs_id [6] = {XC_LDA_X, XC_GGA_X_B88, XC_LDA_C_PW, XC_GGA_C_PW91, XC_GGA_X_PBE, XC_GGA_C_PBE};

  /* Used C standard doesn't allow initializer list, even with const
     variables */
  double funcs_coef[6];
  funcs_coef[0]=(1.0 - xb3pw91 - 0.72)*fb3pw91;
  funcs_coef[1]=0.72*fb3pw91;
  funcs_coef[2]=(1.0 - 0.81)*fb3pw91;
  funcs_coef[3]=0.81*fb3pw91;
  funcs_coef[4]=(1.0 - xpbe0)*fpbe0;
  funcs_coef[5]=fpbe0;

  xc_mix_init(p, 6, funcs_id, funcs_coef);
  p->cam_alpha = fb3pw91*xb3pw91 + fpbe0*xpbe0;
}

const xc_func_info_type xc_func_info_hyb_gga_xc_apf = {
  XC_HYB_GGA_XC_APF,
  XC_EXCHANGE_CORRELATION,
  "APF hybrid functional",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Austin2012_4989, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_apf_init, NULL,
  NULL, NULL, NULL
};


/*************************************************************/
void
xc_hyb_gga_xc_wc04_init(xc_func_type *p)
{
  /* From the paper it is not clear if the LSDA is VWN or VWN_RPA.
     Due to the comparison to B3LYP I think the latter is more likely */
  const double PP[5] = {0.7400, 0.9999, 0.0001, 0.0001, 0.9999};
  static int funcs_id[4] = {XC_LDA_X, XC_GGA_X_B88, XC_LDA_C_VWN_RPA, XC_GGA_C_LYP};
  double funcs_coef[4];

  funcs_coef[0] = PP[2] - PP[1];
  funcs_coef[1] = PP[1];
  funcs_coef[2] = PP[4] - PP[3];
  funcs_coef[3] = PP[3];

  xc_mix_init(p, 4, funcs_id, funcs_coef);
  p->cam_alpha = PP[0];
}

const xc_func_info_type xc_func_info_hyb_gga_xc_wc04 = {
  XC_HYB_GGA_XC_WC04,
  XC_EXCHANGE_CORRELATION,
  "hybrid fitted to carbon NMR shifts",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Wiitala2006_1085, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_wc04_init, NULL,
  NULL, NULL, NULL
};


/*************************************************************/
void
xc_hyb_gga_xc_wp04_init(xc_func_type *p)
{
  /* From the paper it is not clear if the LSDA is VWN or VWN_RPA.
     Due to the comparison to B3LYP I think the latter is more likely */
  const double PP[5] = {0.1189, 0.9614, 0.9999, 0.0001, 0.9999};
  static int funcs_id[4] = {XC_LDA_X, XC_GGA_X_B88, XC_LDA_C_VWN_RPA, XC_GGA_C_LYP};
  double funcs_coef[4];

  funcs_coef[0] = PP[2] - PP[1];
  funcs_coef[1] = PP[1];
  funcs_coef[2] = PP[4] - PP[3];
  funcs_coef[3] = PP[3];

  xc_mix_init(p, 4, funcs_id, funcs_coef);
  p->cam_alpha = PP[0];
}

const xc_func_info_type xc_func_info_hyb_gga_xc_wp04 = {
  XC_HYB_GGA_XC_WP04,
  XC_EXCHANGE_CORRELATION,
  "hybrid fitted to proton NMR shifts",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Wiitala2006_1085, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  xc_hyb_gga_xc_wp04_init, NULL,
  NULL, NULL, NULL
};



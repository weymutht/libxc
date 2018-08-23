/* 
  This file was generated automatically with ./scripts/maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ./maple/lda_c_lp96.mpl
  Type of functional: lda_exc
*/

#define maple2c_order 3

static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t3, t4, t6, t9, t13, t19, t22;
  double t26, t32;

  lda_c_lp96_params *params;

  assert(p->params != NULL);
  params = (lda_c_lp96_params * )(p->params);

  t1 = POW_1_3(rho[0]);
  t3 = params->C2 / t1;
  t4 = t1 * t1;
  t6 = params->C3 / t4;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = params->C1 + t3 + t6;

  if(order < 1) return;


  t9 = params->C2 / t1 / rho[0];
  t13 = params->C3 / t4 / rho[0];
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = params->C1 + t3 + t6 + rho[0] * (-t9 / 0.3e1 - 0.2e1 / 0.3e1 * t13);

  if(order < 2) return;


  t19 = rho[0] * rho[0];
  t22 = params->C2 / t1 / t19;
  t26 = params->C3 / t4 / t19;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.2e1 / 0.3e1 * t9 - 0.4e1 / 0.3e1 * t13 + rho[0] * (0.4e1 / 0.9e1 * t22 + 0.10e2 / 0.9e1 * t26);

  if(order < 3) return;


  t32 = t19 * rho[0];
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = 0.4e1 / 0.3e1 * t22 + 0.10e2 / 0.3e1 * t26 + rho[0] * (-0.28e2 / 0.27e2 * params->C2 / t1 / t32 - 0.80e2 / 0.27e2 * params->C3 / t4 / t32);

  if(order < 4) return;



}


static inline void
func_ferr(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t3, t4, t6, t9, t13, t19, t22;
  double t26, t32;

  lda_c_lp96_params *params;

  assert(p->params != NULL);
  params = (lda_c_lp96_params * )(p->params);

  t1 = POW_1_3(rho[0]);
  t3 = params->C2 / t1;
  t4 = t1 * t1;
  t6 = params->C3 / t4;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = params->C1 + t3 + t6;

  if(order < 1) return;


  t9 = params->C2 / t1 / rho[0];
  t13 = params->C3 / t4 / rho[0];
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = params->C1 + t3 + t6 + rho[0] * (-t9 / 0.3e1 - 0.2e1 / 0.3e1 * t13);

  if(order < 2) return;


  t19 = rho[0] * rho[0];
  t22 = params->C2 / t1 / t19;
  t26 = params->C3 / t4 / t19;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.2e1 / 0.3e1 * t9 - 0.4e1 / 0.3e1 * t13 + rho[0] * (0.4e1 / 0.9e1 * t22 + 0.10e2 / 0.9e1 * t26);

  if(order < 3) return;


  t32 = t19 * rho[0];
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = 0.4e1 / 0.3e1 * t22 + 0.10e2 / 0.3e1 * t26 + rho[0] * (-0.28e2 / 0.27e2 * params->C2 / t1 / t32 - 0.80e2 / 0.27e2 * params->C3 / t4 / t32);

  if(order < 4) return;



}


static inline void
func_pol(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t2, t4, t5, t7, t10, t14, t20;
  double t23, t27, t33;

  lda_c_lp96_params *params;

  assert(p->params != NULL);
  params = (lda_c_lp96_params * )(p->params);

  t1 = rho[0] + rho[1];
  t2 = POW_1_3(t1);
  t4 = params->C2 / t2;
  t5 = t2 * t2;
  t7 = params->C3 / t5;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = params->C1 + t4 + t7;

  if(order < 1) return;


  t10 = params->C2 / t2 / t1;
  t14 = params->C3 / t5 / t1;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = params->C1 + t4 + t7 + t1 * (-t10 / 0.3e1 - 0.2e1 / 0.3e1 * t14);

  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = vrho[0];

  if(order < 2) return;


  t20 = t1 * t1;
  t23 = params->C2 / t2 / t20;
  t27 = params->C3 / t5 / t20;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.2e1 / 0.3e1 * t10 - 0.4e1 / 0.3e1 * t14 + t1 * (0.4e1 / 0.9e1 * t23 + 0.10e2 / 0.9e1 * t27);

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = v2rho2[0];

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = v2rho2[1];

  if(order < 3) return;


  t33 = t20 * t1;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = 0.4e1 / 0.3e1 * t23 + 0.10e2 / 0.3e1 * t27 + t1 * (-0.28e2 / 0.27e2 * params->C2 / t2 / t33 - 0.80e2 / 0.27e2 * params->C3 / t5 / t33);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = v3rho3[0];

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = v3rho3[1];

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = v3rho3[2];

  if(order < 4) return;



}


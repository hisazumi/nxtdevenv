/* Test the `vmov_np16' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vmov_np16 (void)
{
  poly16x4_t out_poly16x4_t;
  poly16_t arg0_poly16_t;

  out_poly16x4_t = vmov_n_p16 (arg0_poly16_t);
}

/* { dg-final { scan-assembler "vdup\.16\[ 	\]+\[dD\]\[0-9\]+, \[rR\]\[0-9\]+!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */

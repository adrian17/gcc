/* { dg-do compile } */
/* { dg-options "-O2 -mno-avx512f -mavx2 -mtune=generic" } */

extern char *dst;

void
foo (void)
{
  __builtin_memset (dst, -1, 64);
}

/* { dg-final { scan-assembler-times "vpcmpeqd\[ \\t\]+\[^\n\]*%ymm" 1 } } */
/* { dg-final { scan-assembler-times "vmovups\[ \\t\]+\[^\n\]*%ymm" 2 } } */

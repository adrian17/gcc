/* { dg-do compile } */
/* { dg-options "-O2 -mavx512f -mtune=generic" } */

extern char *dst;

void
foo (void)
{
  __builtin_memset (dst, 0, 33);
}

/* { dg-final { scan-assembler-times "vpxor\[ \\t\]+\[^\n\]*%xmm" 1 } } */
/* { dg-final { scan-assembler-times "vmovups\[ \\t\]+\[^\n\]*%ymm" 1 } } */

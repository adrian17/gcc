/* { dg-do compile } */
/* { dg-options "-O2 -mno-avx -msse2 -mtune=generic" } */

extern char *dst;

void
foo (int x)
{
  __builtin_memset (dst, x, 17);
}

/* { dg-final { scan-assembler-times "movups\[ \\t\]+\[^\n\]*%xmm" 1 } } */

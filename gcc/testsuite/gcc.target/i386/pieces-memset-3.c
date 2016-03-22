/* { dg-do compile } */
/* { dg-options "-O2 -mavx512f -mtune=generic" } */

extern char *dst;

void
foo (int x)
{
  __builtin_memset (dst, x, 66);
}

/* { dg-final { scan-assembler-times "vmovdqu32\[ \\t\]+\[^\n\]*%zmm" 1 } } */

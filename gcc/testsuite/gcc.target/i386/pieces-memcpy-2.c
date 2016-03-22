/* { dg-do compile } */
/* { dg-options "-O2 -mno-avx2 -mavx -mtune=generic" } */

extern char *dst, *src;

void
foo (void)
{
  __builtin_memcpy (dst, src, 64);
}

/* { dg-final { scan-assembler-times "vmovdqu\[ \\t\]+\[^\n\]*%ymm" 2 } } */
/* { dg-final { scan-assembler-times "vmovups\[ \\t\]+\[^\n\]*%ymm" 2 } } */

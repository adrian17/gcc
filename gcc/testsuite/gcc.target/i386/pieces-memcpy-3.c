/* { dg-do compile } */
/* { dg-options "-O2 -mavx512f -mtune=generic" } */

extern char *dst, *src;

void
foo (void)
{
  __builtin_memcpy (dst, src, 66);
}

/* { dg-final { scan-assembler-times "vmovdqu32\[ \\t\]+\[^\n\]*%zmm" 2 } } */

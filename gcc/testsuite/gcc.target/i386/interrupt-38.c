/* { dg-do compile } */
/* { dg-options "-O2 -mcld" } */

__attribute__ ((interrupt))
void
foo (void *frame)
{
}

/* { dg-final { scan-assembler-times "iret" 1 { target ia32 } } } */
/* { dg-final { scan-assembler-times "iretq" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-not "\tcld" } } */

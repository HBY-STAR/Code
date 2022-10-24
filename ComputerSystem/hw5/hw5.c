#include <stdio.h>

long data[5] = {2, 3, 5, 4, 1};

// Bubble sort: Pointer version
void bubble_p(long *data, long count)
{
    for (long *p2 = &data[count - 1]; p2 != &data[0]; p2--)
    {
        for (long *p1 = &data[0]; p1 != p2; p1++)
        {
            if (*(p1 + 1) < *p1)
            {
                long t = *(p1 + 1);
                *(p1 + 1) = *p1;
                *p1 = t;
            }
        }
    }
}

// Test code
int main()
{
    bubble_p(data, 5);
    return 0;
}

/* x86-64 version
Dump of assembler code for function _Z8bubble_pPll:
   0x0000000140001454 <+0>:     push   rbp
   0x0000000140001455 <+1>:     mov    rbp,rsp
   0x0000000140001458 <+4>:     sub    rsp,0x20
   0x000000014000145c <+8>:     mov    QWORD PTR [rbp+0x10],rcx
   0x0000000140001460 <+12>:    mov    DWORD PTR [rbp+0x18],edx
   0x0000000140001463 <+15>:    mov    eax,DWORD PTR [rbp+0x18]
   0x0000000140001466 <+18>:    cdqe
   0x0000000140001468 <+20>:    shl    rax,0x2
   0x000000014000146c <+24>:    lea    rdx,[rax-0x4]
   0x0000000140001470 <+28>:    mov    rax,QWORD PTR [rbp+0x10]
   0x0000000140001474 <+32>:    add    rax,rdx
   0x0000000140001477 <+35>:    mov    QWORD PTR [rbp-0x8],rax
   0x000000014000147b <+39>:    jmp    0x1400014d2 <_Z8bubble_pPll+126>
   0x000000014000147d <+41>:    mov    rax,QWORD PTR [rbp+0x10]
   0x0000000140001481 <+45>:    mov    QWORD PTR [rbp-0x10],rax
   0x0000000140001485 <+49>:    jmp    0x1400014c3 <_Z8bubble_pPll+111>
   0x0000000140001487 <+51>:    mov    rax,QWORD PTR [rbp-0x10]
   0x000000014000148b <+55>:    add    rax,0x4
   0x000000014000148f <+59>:    mov    edx,DWORD PTR [rax]
   0x0000000140001491 <+61>:    mov    rax,QWORD PTR [rbp-0x10]
   0x0000000140001495 <+65>:    mov    eax,DWORD PTR [rax]
   0x0000000140001497 <+67>:    cmp    edx,eax
   0x0000000140001499 <+69>:    jge    0x1400014be <_Z8bubble_pPll+106>
   0x000000014000149b <+71>:    mov    rax,QWORD PTR [rbp-0x10]
   0x000000014000149f <+75>:    mov    eax,DWORD PTR [rax+0x4]
   0x00000001400014a2 <+78>:    mov    DWORD PTR [rbp-0x14],eax
   0x00000001400014a5 <+81>:    mov    rax,QWORD PTR [rbp-0x10]
   0x00000001400014a9 <+85>:    lea    rdx,[rax+0x4]
   0x00000001400014ad <+89>:    mov    rax,QWORD PTR [rbp-0x10]
   0x00000001400014b1 <+93>:    mov    eax,DWORD PTR [rax]
   0x00000001400014b3 <+95>:    mov    DWORD PTR [rdx],eax
   0x00000001400014b5 <+97>:    mov    rax,QWORD PTR [rbp-0x10]
   0x00000001400014b9 <+101>:   mov    edx,DWORD PTR [rbp-0x14]
   0x00000001400014bc <+104>:   mov    DWORD PTR [rax],edx
   0x00000001400014be <+106>:   add    QWORD PTR [rbp-0x10],0x4
   0x00000001400014c3 <+111>:   mov    rax,QWORD PTR [rbp-0x10]
   0x00000001400014c7 <+115>:   cmp    rax,QWORD PTR [rbp-0x8]
   0x00000001400014cb <+119>:   jne    0x140001487 <_Z8bubble_pPll+51>
   0x00000001400014cd <+121>:   sub    QWORD PTR [rbp-0x8],0x4
   0x00000001400014d2 <+126>:   mov    rax,QWORD PTR [rbp-0x8]
   0x00000001400014d6 <+130>:   cmp    rax,QWORD PTR [rbp+0x10]
   0x00000001400014da <+134>:   jne    0x14000147d <_Z8bubble_pPll+41>
   0x00000001400014dc <+136>:   nop
   0x00000001400014dd <+137>:   nop
   0x00000001400014de <+138>:   add    rsp,0x20
   0x00000001400014e2 <+142>:   pop    rbp
   0x00000001400014e3 <+143>:   ret
End of assembler dump.
*/

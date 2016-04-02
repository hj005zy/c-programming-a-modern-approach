#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

int main(void)
{
    union {
        struct {
            DWORD eax, ebx, ecx, edx;
        } dword;
        struct {
            WORD _ax, ax, _bx, bx, _cx, cx, _dx, dx;
        } word;
        struct {
            BYTE _al, _ah, al, ah, _bl, _bh, bl, bh,
                 _cl, _ch, cl, ch, _dl, _dh, dl, dh;
        } byte;
    } regs;

    regs.dword.eax = 0x12345678;
    printf("AX: %hx\n", regs.word.ax);

    regs.word.ax = 0x5678;
    printf("EAX: %lx\n", regs.dword.eax);

    return 0;
}

#include <stdio.h>

unsigned int rotate_letf(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main(void)
{
    unsigned int i;
    int n;

    printf("Enter a hexadecimal number (up to eight digits): ");
    scanf("%x", &i);
    printf("Enter shifting: ");
    scanf("%d", &n);

    printf("Number rotate left: %x\n", rotate_letf(i, n));
    printf("Number rotate right: %x\n", rotate_right(i, n));

    return 0;
}

unsigned int rotate_letf(unsigned int i, int n)
{
    return i << n | (i >> (sizeof(unsigned int) * 8 - n));
}

unsigned int rotate_right(unsigned int i, int n)
{
    return i >> n | (i << (sizeof(unsigned int) * 8 - n));
}

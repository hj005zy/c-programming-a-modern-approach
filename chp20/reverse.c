#include <stdio.h>

unsigned int reverse_bits(unsigned int n);

int main(void)
{
    unsigned int n;

    printf("Enter a number: ");
    scanf("%u", &n);

    printf("Reversed number: %u\n", reverse_bits(n));

    return 0;
}

unsigned int reverse_bits(unsigned int n)
{
    unsigned int digit = sizeof(unsigned int) * 8 - 1;
    unsigned int reverse_num = 0;
    unsigned int i;

    for (i = 0; i < digit; i++) {
        reverse_num |= n & 1;
        reverse_num <<= 1;
        n >>= 1;
    }

    return reverse_num;
}

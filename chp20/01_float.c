#include <stdio.h>

union {
    float n;
    struct {
        unsigned int fraction: 23;
        unsigned int exponent: 8;
        unsigned int sign: 1;
    } IEEE_float;
} f;

int main(void)
{
    f.IEEE_float.sign = 1;
    f.IEEE_float.exponent = 128;
    f.IEEE_float.fraction = 0;
    
    printf("%f\n", f.n);

    return 0;
}

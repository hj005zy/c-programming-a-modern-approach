#include <stdio.h>
#include <tgmath.h>

int main(void)
{
    double a, b;

    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);

    printf("r = %g\n", sqrt(a * a + b * b));
    printf("θ = %g\n", atan2(b, a));

    return 0;
}

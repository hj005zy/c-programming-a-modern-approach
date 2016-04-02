#include <stdio.h>
#include <tgmath.h>

int main(void)
{
    double r, θ;

    printf("Enter r: ");
    scanf("%lf", &r);
    printf("Enter θ: ");
    scanf("%lf", &θ);

    printf("a = %g\n", r * cos(θ));
    printf("b = %g\n", r * sin(θ));

    return 0;
}

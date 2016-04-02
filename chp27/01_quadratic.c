#include <complex.h>
#include <stdio.h>
#include <tgmath.h>

int main(void)
{
    int discriminant;
    double a, b, c;
    double imag1, imag2;

    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Enter c: ");
    scanf("%lf", &c);

    printf("\n");
    discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double discriminant_sqrt = sqrt(discriminant);
        double root1 = (-b + discriminant_sqrt) / (2 * a);
        double root2 = (-b - discriminant_sqrt) / (2 * a);

        printf("root1 = %g\n", root1);
        printf("root2 = %g\n", root2);
    } else {
        double complex discriminant_sqrt = csqrt(discriminant);
        double complex root1 = (-b + discriminant_sqrt) / (2 * a);
        double complex root2 = (-b - discriminant_sqrt) / (2 * a);

        imag1 = cimag(root1);
        imag2 = cimag(root2);
        if (imag1 > 0) {
            printf("root1 = %g + %gi\n", creal(root1), imag1);
        } else {
            printf("root1 = %g - %gi\n", creal(root1), -imag1);
        }
        if (imag2 > 0) {
            printf("root2 = %g + %gi\n", creal(root2), imag2);
        } else {
            printf("root2 = %g - %gi\n", creal(root2), -imag2);
        }
    }

    return 0;
}

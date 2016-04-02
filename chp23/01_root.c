#include <math.h>
#include <stdio.h>

int main(void)
{
    int a, b, c, temp;
    double r1, r2;

    printf("Enter three coefficients: ");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    temp = b * b - 4 * a * c;
    if (temp < 0) {
        printf("The root is complex.\n");
        return 0;
    }

    r1 = (b * -1 + sqrt(temp)) / (2 * a);
    r2 = (b * -1 - sqrt(temp)) / (2 * a);
    printf("The root is %f and %f\n", r1, r2);

    return 0;
}

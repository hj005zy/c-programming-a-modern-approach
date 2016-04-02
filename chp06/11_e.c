#include <stdio.h>

int main(void)
{
    int n, factorial = 1;
    float e = 1.0;

    printf("Enter limit on maximum term series: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        e += 1.0f / factorial;
    }

    printf("Approximation of e is %f\n", e);

    return 0;
}

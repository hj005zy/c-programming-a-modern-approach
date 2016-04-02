#include <stdio.h>

int main(void)
{
    int n, factorial = 1;
    float e = 1.0, current_term, test_value;

    printf("Enter limit on maximum term series: ");
    scanf("%d", &n);
    printf("Enter test value: ");
    scanf("%f", &test_value);

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        current_term = 1.0f / factorial;
        if (current_term < test_value) {
            break;
        }
        e += current_term;
    }

    printf("Approximation of e is %f\n", e);

    return 0;
}

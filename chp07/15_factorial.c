#include <stdio.h>

int main(void)
{
    int n;
    long result = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    printf("Factorial of %d: %ld\n", n, result);

    return 0;
}

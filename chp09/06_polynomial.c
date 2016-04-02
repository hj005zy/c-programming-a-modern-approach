#include <stdio.h>

int power(int x, int n)
{
    return n == 0 ? 1 : x * power(x, n - 1);
}

int main(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("%d\n", 3 * power(n, 5) + 2 * power(n, 4) - 5 * power(n, 3)
        - power(n, 2) + 7 * n - 6);

    return 0;
}

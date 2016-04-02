#include <stdio.h>

int power(int x, int n)
{
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        int result = power(x , n / 2);
        return result * result;
    } else {
        return x * power(x, n - 1);
    }
}

int main(void)
{
    int x, n;

    printf("Enter a number: ");
    scanf("%d", &x);

    printf("Enter power: ");
    scanf("%d", &n);

    printf("%d\n", power(x, n));

    return 0;
}

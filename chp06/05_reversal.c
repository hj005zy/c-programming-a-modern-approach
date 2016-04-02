#include <stdio.h>

int main(void)
{
    int n, reversal = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    do {
        reversal = reversal * 10 + n % 10;
        n /= 10;
    } while (n != 0);

    printf("The reversal is %d\n", reversal);

    return 0;
}

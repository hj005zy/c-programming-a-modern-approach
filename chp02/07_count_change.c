#include <stdio.h>

int main(void)
{
    int amount, result;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    printf("\n");
    result = amount / 20;
    printf("$20 bills: %d\n", result);

    amount = amount - result * 20;
    result = amount / 10;
    printf("$10 bills: %d\n", result);

    amount = amount - result * 10;
    result = amount / 5;
    printf("$5 bills: %d\n", result);

    amount = amount - result * 5;
    result = amount;
    printf("$1 bills: %d\n", result);

    return 0;
}

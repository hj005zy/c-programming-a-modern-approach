#include <stdio.h>

int main(void)
{
    float amount, tax_added;

    printf("Enter an amount: ");
    scanf("%f", &amount);

    tax_added = amount + amount * 0.05f;
    printf("With tax added: $%.2f\n", tax_added);

    return 0;
}

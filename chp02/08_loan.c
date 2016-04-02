#include <stdio.h>

int main(void)
{
    float amount, interest_rate, monthly_payment, remaining;

    printf("Enter amount of loan: ");
    scanf("%f", &amount);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    interest_rate = interest_rate / 100.0f / 12.0f;
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    remaining = amount;
    remaining = remaining + remaining * interest_rate - monthly_payment;
    printf("Balance remaining after first payment: $%.2f\n", remaining);

    remaining = remaining + remaining * interest_rate - monthly_payment;
    printf("Balance remaining after second payment: $%.2f\n", remaining);

    remaining = remaining + remaining * interest_rate - monthly_payment;
    printf("Balance remaining after third payment: $%.2f\n", remaining);

    return 0;
}

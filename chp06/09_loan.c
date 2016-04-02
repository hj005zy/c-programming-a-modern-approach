#include <stdio.h>

int main(void)
{
    float amount, interest_rate, monthly_payment, remaining;
    int loan_times;

    printf("Enter amount of loan: ");
    scanf("%f", &amount);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    interest_rate = interest_rate / 100.0f / 12.0f;
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);
    printf("Enter loan times: ");
    scanf("%d", &loan_times);

    remaining = amount;
    for (int i = 0; i < loan_times; i++) {
        remaining = remaining + remaining * interest_rate - monthly_payment;
        printf("Balance remaining after payment: $%.2f\n", remaining);
    }

    return 0;
}

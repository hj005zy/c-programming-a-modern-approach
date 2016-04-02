#include <math.h>
#include <stdio.h>

int main(void)
{
    int initial_deposit, num_year;
    float rate;
    double result;

    printf("Enter initial deposit: ");
    scanf("%d", &initial_deposit);
    printf("Enter rate: ");
    scanf("%f", &rate);
    printf("Enter number of years: ");
    scanf("%d", &num_year);

    result = initial_deposit * pow(exp(1.0), rate / 100 * num_year);
    printf("Result is %.2f\n", result);

    return 0;
}

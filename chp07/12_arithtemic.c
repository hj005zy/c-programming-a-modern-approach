#include <stdio.h>

int main(void)
{
    char ch;
    double n, result = 0;

    printf("Enter an expression: ");

    scanf("%lf", &result);

    while ((ch = getchar()) != '\n') {

        scanf("%lf", &n);

        switch (ch) {
            case '+':
                result += n;
                break;
            case '-':
                result -= n;
                break;
            case '*':
                result *= n;
                break;
            case '/':
                result /= n;
                break;
        }
    }

    printf("Value of expression: %f\n", result);

    return 0;
}

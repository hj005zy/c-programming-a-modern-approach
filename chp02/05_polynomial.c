#include <stdio.h>

int main(void)
{
    int x, first, second, third, fourth, fifth;

    printf("Enter value of x: ");
    scanf("%d", &x);

    first = 3 * x * x * x * x * x;
    second = 2 * x * x * x * x;
    third = 5 * x * x * x;
    fourth = x * x;
    fifth = 7 * x;
    printf("Polynomial resut: %d\n", first + second - third - fourth + fifth - 6);

    return 0;
}

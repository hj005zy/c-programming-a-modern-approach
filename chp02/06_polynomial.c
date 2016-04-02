#include <stdio.h>

int main(void)
{
    int x, first, second, third, fourth, fifth;

    printf("Enter value of x: ");
    scanf("%d", &x);

    first = 3 * x + 2;
    second = first * x - 5;
    third = second * x - 1;
    fourth = third * x + 7;
    fifth = fourth * x - 6;
    printf("Polynomial resut: %d\n", fifth);

    return 0;
}

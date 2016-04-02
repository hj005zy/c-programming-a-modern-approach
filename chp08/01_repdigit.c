#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int digit_count[10] = {0}, digit_repeated[10];
    int digit, count = 0;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_count[digit] == 1) {
            digit_repeated[count++] = digit;
        }
        digit_count[digit]++;
        n /= 10;
    }

    printf("Repeated digit(s):");
    for (int i = 0; i < count; i++) {
        printf(" %d", digit_repeated[i]);
    }
    printf("\n");

    return 0;
}

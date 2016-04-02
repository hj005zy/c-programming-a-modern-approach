#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    bool digit_seen[10];
    int digit;
    long n;

    for (;;) {

        printf("Enter a number: ");
        scanf("%ld", &n);

        if (n <= 0) {
            return 0;
        }

        for (int i = 0; i < 10; i++) {
            digit_seen[i] = false;
        }

        while (n > 0) {
            digit = n % 10;
            if (digit_seen[digit]) {
                break;
            }
            digit_seen[digit] = true;
            n /= 10;
        }

        if (n > 0) {
            printf("Repeated digit\n");
        } else {
            printf("No repeated digit\n");
        }
    }
}

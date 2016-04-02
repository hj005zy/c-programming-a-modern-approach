#include <stdio.h>

int main(void)
{
    float n, max = 0.0f;

    for(;;) {
        printf("Enter a number: ");
        scanf("%f", &n);

        if (n <= 0) {
            printf("\nThe largest number entered was %.2f\n", max);
            return 0;
        } else if (n > max) {
            max = n;
        }
    }
}

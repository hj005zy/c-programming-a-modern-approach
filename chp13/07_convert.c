#include <stdio.h>

int main(void)
{
    int n, single, tens;
    char *tens_str[] = {"twenty", "thirty", "forty", "fifty", "sixty",
                        "seventy", "eighty", "ninety"};
    char *single_str[] = {"one", "two", "three", "four", "five", "six",
                          "seven", "eight", "nine"};
    char *ten_to_twenty_str[] = {"ten", "eleven", "twelve", "thirteen",
                                 "fourteen", "fifteen", "sixteen",
                                 "seventeen", "eighteen", "nineteen"};

    printf("Enter a two-digit number: ");
    scanf("%d", &n);

    if (n < 10 || n >=100) {
        printf("Illegal two-digit number\n");
        return 0;
    }

    tens = n / 10;
    single = n % 10;
    if (tens > 1) {
        printf("%s", tens_str[tens - 2]);
        if (single > 0) {
            printf("-%s\n", single_str[single - 1]);
        }
    } else {
        printf("%s\n", ten_to_twenty_str[single]);
    }

    return 0;
}

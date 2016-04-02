#include <stdio.h>
#include <stdlib.h>

#define LEN 25


int main(void)
{
    char const *months[] = {"January", "February", "March", "April", "May",
                            "June", "July", "August", "September", "October",
                            "November", "December"};
    char str[LEN + 1];
    int month, day, year;

    printf("Enter a date: ");
    fgets(str, sizeof(str), stdin);
    if (sscanf(str, "%d / %d/ %d", &month, &day, &year) == 3) {
        printf("%s %d, %d\n", months[month - 1], day, year);
    } else if (sscanf(str, "%d - %d -%d", &month, &day, &year) == 3) {
        printf("%s %d, %d\n", months[month - 1], day, year);
    } else {
        printf("Date not in the proper form\n");
    }

    return 0;
}

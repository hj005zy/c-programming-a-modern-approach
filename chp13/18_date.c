#include <stdio.h>

int main(void)
{
    char *months[] = {"January", "February", "March", "Appril",
                      "May", "June", "July", "August",
                      "September", "October", "November", "December"};
    int year, month, day;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("You entered the date %s %d, %d\n", months[month - 1], day, year);

    return 0;
}

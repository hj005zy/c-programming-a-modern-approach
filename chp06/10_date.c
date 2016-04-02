#include <stdio.h>

int main(void)
{
    int min_year, min_month, min_day, year, month, day;

    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &min_month, &min_day, &min_year);

    for (;;) {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &month, &day, &year);

        if (month == 0 && day == 0 && year == 0) {
            printf("%d/%d/%.2d is the earliest date\n", min_month,
                min_day, min_year);
            return 0;
        }

        if (year < min_year) {
            min_year = year;
            min_month = month;
            min_day = day;
        } else if (year == min_year && month < min_month) {
            min_year = year;
            min_month = month;
            min_day = day;
        } else if (year == min_year && month == min_month && day < min_day) {
            min_year = year;
            min_month = month;
            min_day = day;
        }
    }
}

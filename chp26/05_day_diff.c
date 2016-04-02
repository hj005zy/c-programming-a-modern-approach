#include <math.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm t1;
    struct tm t2;
    double diff_sec;
    int diff_days;

    t1.tm_sec = t1.tm_min = t1.tm_hour = 0;
    t1.tm_isdst = -1;
    t2 = t1;

    printf("Enter month (1-12): ");
    scanf("%d", &t1.tm_mon);
    t1.tm_mon--;

    printf("Enter day (1-31): ");
    scanf("%d", &t1.tm_mday);

    printf("Enter year: ");
    scanf("%d", &t1.tm_year);
    t1.tm_year -= 1900;

    printf("\nEnter month (1-12): ");
    scanf("%d", &t2.tm_mon);
    t2.tm_mon--;

    printf("Enter day (1-31): ");
    scanf("%d", &t2.tm_mday);

    printf("Enter year: ");
    scanf("%d", &t2.tm_year);
    t2.tm_year -= 1900;

    diff_sec = difftime(mktime(&t1), mktime(&t2));
    diff_days = fabs(diff_sec / (24 * 60 * 60));

    printf("\nDifference: %d\n", diff_days);

    return 0;
}

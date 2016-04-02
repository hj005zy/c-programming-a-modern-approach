#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t current = time(NULL);
    struct tm *ptr;
    char date_time[37];

    ptr = localtime(&current);
    strftime(date_time, sizeof(date_time), "%A, %B %d, %Y  %I:%M", ptr);
    printf("%s%c\n", date_time, ptr->tm_hour <= 11 ? 'a' : 'p');

    return 0;
}

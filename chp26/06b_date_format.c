#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t current = time(NULL);
    struct tm *ptr;
    char date_time[22];

    ptr = localtime(&current);
    strftime(date_time, sizeof(date_time), "%a, %d %b %y  %H:%M", ptr);
    puts(date_time);

    return 0;
}

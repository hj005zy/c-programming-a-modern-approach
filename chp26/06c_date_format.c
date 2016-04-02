#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t current = time(NULL);
    struct tm *ptr;
    char date[9], time[12];

    ptr = localtime(&current);
    strftime(date, sizeof(date), "%D", ptr);
    strftime(time, sizeof(time), "%r", ptr);
    printf("%s  %s\n", date, time);

    return 0;
}

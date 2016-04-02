#include <stdio.h>

int main(void)
{
    int hour, minute, elapsed_minutes;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    if (hour < 0 || hour > 23) {
        printf("Illegal hour\n");
        return 0;
    } else if (minute < 0 || minute >= 60) {
        printf("Illegal minute\n");
        return 0;
    }

    elapsed_minutes = hour * 60 + minute;

    if (elapsed_minutes <= ((8 * 60 + 9 * 60 + 43) / 2)) {
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    } else if (elapsed_minutes <= ((9 * 60 + 43 + 11 * 60 + 19) / 2)) {
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    } else if (elapsed_minutes <= ((11 * 60 + 19 + 12 * 60 + 47) / 2)) {
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    } else if (elapsed_minutes <= ((12 * 60 + 47 + 14 * 60) / 2)) {
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    } else if (elapsed_minutes <= ((14 * 60 + 15 * 60 + 45) / 2)) {
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    } else if (elapsed_minutes <= ((15 * 60 + 45 + 19 * 60) / 2)) {
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    } else if (elapsed_minutes <= ((19 * 60 + 21 * 60 + 45) / 2)) {
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    } else {
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    }

    return 0;
}

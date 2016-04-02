#include <stdio.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void)
{
    int hour, minute, desired_time, departure_time, arrival_time,
        departure_hour, departure_minute, arrival_hour, arrival_minute;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    if (hour < 0 || hour > 23) {
        printf("Illegal hour\n");
        return 0;
    } else if (minute < 0 || minute >= 60) {
        printf("Illegal minute\n");
        return 0;
    }

    desired_time = hour * 60 + minute;
    find_closest_flight(desired_time, &departure_time, &arrival_time);

    departure_hour = departure_time / 60;
    departure_minute = departure_time % 60;
    arrival_hour = arrival_time / 60;
    arrival_minute = arrival_time % 60;
     
    printf("Closest departure time is ");
    if (departure_hour < 12) {
        printf("%d:%.2d a.m.", departure_hour, departure_minute);
    } else if (departure_hour == 12) {
        printf("%d:%.2d p.m.", departure_hour, departure_minute);
    } else {
        printf("%d:%.2d p.m.", departure_hour - 12, departure_minute);
    }
    printf(", arriving at ");
    if (arrival_hour < 12) {
        printf("%d:%.2d a.m.", arrival_hour, arrival_minute);
    } else if (arrival_hour == 12) {
        printf("%d:%.2d p.m.", arrival_hour, arrival_minute);
    } else {
        printf("%d:%.2d p.m.", arrival_hour - 12, arrival_minute);
    }
    printf("\n");

    return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    int i, result_index = -1;
    int departure_times[] = {8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47,
        14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45};
    int arrival_times[] = {10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60,
        16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58};

    for (i = 0; i < 7; i++) {
        if (desired_time <= ((departure_times[i] + departure_times[i + 1]) / 2)) {
            result_index = i;
            break;
        }
    }

    if (result_index == -1) {
        result_index = 7;
    }

    *departure_time = departure_times[result_index];
    *arrival_time = arrival_times[result_index];
}

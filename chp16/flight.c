#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    struct flight {
        int departure_time;
        int arrival_time;
    };
    struct flight best_fit_flight;
    int hour, minute, elapsed_minutes, departure_hour, arrival_hour;
    bool best_fit_flight_found = false;
    const struct flight flights[] = {
        {8 * 60, 10 * 60 + 16}, {9 * 60 + 43, 11 * 60 + 52},
        {11 * 60 + 19, 13 * 60 + 47}, {12 * 60 + 47, 15 * 60},
        {14 * 60, 16 * 60 + 8}, {15 * 60 + 45, 17 * 60 + 55},
        {19 * 60, 21 * 60 + 20}, {21 * 60 + 45, 23 * 60 + 58}
    };
    int num_flights = (int) (sizeof(flights) / sizeof(flights[0]));

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
    for (int i = 0; i < num_flights - 1; i++) {
        if (elapsed_minutes < ((flights[i].departure_time + flights[i + 1].departure_time) / 2)) {
            best_fit_flight = flights[i];
            best_fit_flight_found = true;
            break;
        }
    }
    if (!best_fit_flight_found) {
        best_fit_flight = flights[num_flights - 1];
    }
    
    departure_hour = best_fit_flight.departure_time / 60;
    printf("Closest departure time is ");
    if (departure_hour <= 12) {
        printf("%d", departure_hour);
    } else {
        printf("%d", departure_hour - 12);
    }
    printf(":%.2d ", best_fit_flight.departure_time - departure_hour * 60);
    if (departure_hour >= 12) {
        printf("p.m.");
    } else {
        printf("a.m.");
    }
    arrival_hour = best_fit_flight.arrival_time / 60;
    printf(", arriving at ");
    if (arrival_hour <= 12) {
        printf("%d", arrival_hour);
    } else {
        printf("%d", arrival_hour - 12);
    }
    printf(":%.2d ", best_fit_flight.arrival_time - arrival_hour * 60);
    if (departure_hour >= 12) {
        printf("p.m.");
    } else {
        printf("a.m.");
    }
    printf("\n");

    return 0;
}

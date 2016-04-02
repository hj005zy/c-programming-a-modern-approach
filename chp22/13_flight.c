#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE_LEN 25

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[LINE_LEN + 1];
    struct flight {
        int departure_time;
        int arrival_time;
    } *flights;
    struct flight best_fit_flight;
    int hour, minute, elapsed_minutes, departure_hour, 
        departure_minute, arrival_hour, arrival_minute,
        num_flights = 0;
    bool best_fit_flight_found = false;

    if (argc != 2) {
        fprintf(stderr, "usage: flight file\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%d:%d %d:%d", &departure_hour, &departure_minute,
                                    &arrival_hour, &arrival_minute);
        if (num_flights == 0) {
            flights = malloc(sizeof(struct flight));
        } else {
            flights = realloc(flights, (num_flights + 1) * sizeof(struct flight));
        }
        if (flights == NULL) {
            fprintf(stderr, "Insufficient memory: can't add more flights.\n");
            exit(EXIT_FAILURE);
        }

        flights[num_flights].departure_time = departure_hour * 60 + departure_minute;
        flights[num_flights].arrival_time = arrival_hour * 60 + arrival_minute;
        num_flights++;
    }

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

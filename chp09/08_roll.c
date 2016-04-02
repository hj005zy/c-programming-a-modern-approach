#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    int wins = 0, losses = 0;
    bool win;
    char command;

    srand((unsigned) time(NULL));

    do {
        win = play_game();

        if (win) {
            wins++;
            printf("You win!\n");
        } else {
            losses++;
            printf("You lose!\n");
        }

        printf("\nPlay again? ");
        scanf(" %c", &command);
        printf("\n");

    } while (command == 'y' || command == 'Y');

    printf("Wins: %d  Losses: %d\n", wins, losses);

    return 0;
}

int roll_dice(void)
{
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

bool play_game(void)
{
    int sum, target_point;
    bool first = true;

    for (;;) {
        sum = roll_dice();
        printf("You rolled: %d\n", sum);
        if (first) {
            if (sum == 7 || sum == 11) {
                return true;
            } else if (sum == 2 || sum == 3 || sum == 12) {
                return false;
            } else {
                target_point = sum;
                printf("Your point is %d\n", target_point);
            }
            first = false;
        } else {
            if (sum == 7) {
                return false;
            } else if (sum == target_point) {
                return true;
            }
        }
    }
}

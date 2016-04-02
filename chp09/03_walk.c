#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 10
#define NUM_COLS 10

void generate_random_walk(char walk[NUM_ROWS][NUM_COLS]);
void print_array(char walk[NUM_ROWS][NUM_COLS]);

int main(void)
{
    char walk[NUM_ROWS][NUM_COLS];

    srand((unsigned) time(NULL));

    generate_random_walk(walk);
    print_array(walk);


    return 0;
}

void generate_random_walk(char walk[NUM_ROWS][NUM_COLS])
{
    char ch = 'B';
    int i, j, direction, current_row = 0, current_col = 0,
        next_row = 0, next_col = 0;
    bool invalid_walk[4], no_available_walk;

    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            walk[i][j] = '.';
        }
    }
    walk[0][0] = 'A';

    for (i = 0; i < 25; i++) {
        for (j = 0; j < 4; j++) {
            invalid_walk[j] = false;
        }
        no_available_walk = false;
        while (!no_available_walk) {
            direction = rand() % 4;
            if (invalid_walk[direction]) {
                continue;
            }
            if (direction == 0) {
                next_row = current_row - 1;
                next_col = current_col;
            } else if (direction == 1) {
                next_row = current_row;
                next_col = current_col + 1;
            } else if (direction == 2) {
                next_row = current_row + 1;
                next_col = current_col;
            } else {
                next_row = current_row;
                next_col = current_col - 1;
            }
            if (next_row < 0 || next_row >= NUM_ROWS || next_col < 0
                    || next_col >= NUM_COLS) {
                invalid_walk[direction] = true;
            } else if (walk[next_row][next_col] != '.') {
                invalid_walk[direction] = true;
            }
            if (invalid_walk[direction]) {
                no_available_walk = invalid_walk[0] && invalid_walk[1]
                                        && invalid_walk[2] && invalid_walk[3];
            } else {
                current_row = next_row;
                current_col = next_col;
                break;
            }
        }
        if (no_available_walk) {
            break;
        }
        walk[current_row][current_col] = ch++;
    } 
}

void print_array(char walk[NUM_ROWS][NUM_COLS])
{
    int i, j;

    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            printf("%c ", walk[i][j]);
        }
        printf("\n");
    }
}

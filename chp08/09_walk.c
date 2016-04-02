#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 10
#define NUM_COLS 10

int main(void)
{
    char m[NUM_ROWS][NUM_COLS];
    char ch = 'B';
    int i, j, direction, current_row = 0, current_col = 0,
        next_row = 0, next_col = 0;
    bool invalid_step[4];
    bool no_available_step;

    srand((unsigned) time(NULL));

    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            m[i][j] = '.';
        }
    }
    m[0][0] = 'A';

    for (i = 0; i < 25; i++) {
        for (j = 0; j < 4; j++) {
            invalid_step[j] = false;
        }
        no_available_step = false;
        while (!no_available_step) {
            direction = rand() % 4;
            if (invalid_step[direction]) {
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
                invalid_step[direction] = true;
            } else if (m[next_row][next_col] != '.') {
                invalid_step[direction] = true;
            }
            if (invalid_step[direction]) {
                no_available_step = invalid_step[0] && invalid_step[1]
                                        && invalid_step[2] && invalid_step[3];
            } else {
                current_row = next_row;
                current_col = next_col;
                break;
            }
        }
        if (no_available_step) {
            break;
        }
        m[current_row][current_col] = ch++;
    } 

    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}

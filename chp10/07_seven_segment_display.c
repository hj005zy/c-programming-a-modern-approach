#include <stdbool.h>
#include <stdio.h>

#define MAX_DIGITS 10

const bool segments[10][7] = {
    {true, true, false, true, true, true, true},
    {false, false, false, true, false, false, true},
    {true, false, true, true, true, true, false},
    {true, false, true, true, false, true, true},
    {false, true, true, true, false, false, true},
    {true, true, true, false, false, true, true},
    {true, true, true, false, true, true, true},
    {true, false, false, true, false, false, true},
    {true, true, true, true, true, true, true},
    {true, true, true, true, false, true, true}};
char digits[3][MAX_DIGITS * 4];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
    int i = 0;
    char ch;

    clear_digits_array();
    printf("Enter a number: ");
    
    while ((ch = getchar()) != '\n') {
        if (ch >= '0' && ch <= '9') {
            process_digit(ch - '0', i++);
        }
    }

    print_digits_array();

    return 0;
}

void clear_digits_array(void)
{
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < MAX_DIGITS * 4; j++) {
            digits[i][j] = ' ';
        }
    }
}

void process_digit(int digit, int position)
{
    int i, j, segements_index = 0;
    for (i = 0; i < 3; i++) {
        for (j = position * 4; j < position * 4 + 3; j++) {
            if (i == 0) {
                if (j == position * 4 || j == position * 4 + 2) {
                    continue;
                }
            }
            if (segments[digit][segements_index++]) {
                if (j % 2 == 0) {
                    digits[i][j] = '|';
                } else {
                    digits[i][j] = '_';
                }
            }
        }
    }
}

void print_digits_array(void)
{
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < MAX_DIGITS * 4; j++) {
            printf("%c", digits[i][j]);
        }
        printf("\n");
    }
}

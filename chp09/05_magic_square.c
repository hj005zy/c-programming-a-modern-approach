#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main(void)
{
    int n;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");

    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("Illegal size\n");
        return 0;
    }

    int magic_square[n][n];
    create_magic_square(n, magic_square);
    print_magic_square(n, magic_square);

    return 0;
}

void create_magic_square(int n, int magic_square[n][n])
{
    int i, j, next_row, next_col, current_row = 0, current_col;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            magic_square[i][j] = 0;
        }
    }

    current_col = (n - 1) / 2;
    magic_square[current_row][current_col] = 1;
    for (i = 2; i <= n * n; i++) {
        next_row = current_row - 1;
        next_col = current_col + 1;
        if (next_row == -1) {
            next_row = n - 1;
        }
        if (next_col == n) {
            next_col = 0;
        }
        if (magic_square[next_row][next_col] != 0) {
            next_row = current_row + 1;
            next_col = current_col;
        }
        magic_square[next_row][next_col] = i;
        current_row = next_row;
        current_col = next_col;
    }
}

void print_magic_square(int n, int magic_square[n][n])
{
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%5d", magic_square[i][j]);
        }
        printf("\n");
    }
}

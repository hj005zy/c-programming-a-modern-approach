#include <stdio.h>

#define ROW 5
#define COL 5

int main(void)
{
    int a[ROW][COL];
    int i, j, sum;

    for (i = 0; i < ROW; i++) {
        printf("Enter row %d: ", i + 1);
        for (j = 0; j < COL; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nRow totals:");
    for (i = 0; i < ROW; i++) {
        sum = 0;
        for (j = 0; j < COL; j++) {
            sum += a[i][j];
        }
        printf(" %d", sum);
    }

    printf("\nColumn totals:");
    for (j = 0; j < COL; j++) {
        sum = 0;
        for (i = 0; i < ROW; i++) {
            sum += a[i][j];
        }
        printf(" %d", sum);
    }
    printf("\n");

    return 0;
}

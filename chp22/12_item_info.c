#include <stdio.h>
#include <stdlib.h>

#define LINE_LEN 100

int main(int argc, char *argv[])
{
    FILE *fp;
    int item_num;
    float unit_price;
    int day, month, year;
    char line[LINE_LEN + 1];

    if (argc != 2) {
        fprintf(stderr, "usage: item_info file\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%d ,%f ,%d /%d /%d", &item_num, &unit_price,
                                           &month, &day, &year);
        printf("%-d\t\t$%7.2f\t%d/%d/%d\n", item_num, unit_price,
                                            month, day, year);
    }

    return 0;
}

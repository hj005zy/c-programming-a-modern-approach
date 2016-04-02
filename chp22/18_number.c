#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b);

int main(int argc, char *argv[])
{
    FILE *fp;
    int buffer = 10, count = 0;
    int *numbers;
    int n, median;

    if (argc != 2) {
        fprintf(stderr, "usage: number file\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    numbers = malloc(sizeof(int) * buffer);
    while (fscanf(fp, "%d", &n) == 1) {
        if (count == buffer) {
            buffer *= 2;
            numbers = realloc(numbers, sizeof(int) * buffer);
        }
        numbers[count++] = n;
    }
    if (count == 0) {
        printf("No number found\n");
        return 0;
    }
    qsort(numbers, count, sizeof(int), compare_int);
    printf("Maximum number: %d\n", numbers[count - 1]);
    printf("Minimum number: %d\n", numbers[0]);
    if (count % 2 == 0) {
        median = (numbers[count / 2 - 1] + numbers[count / 2]) / 2;
    } else {
        median = numbers[count / 2];
    }
    printf("Median number: %d\n", median);

    fclose(fp);
    return 0;
}

int compare_int(const void *a, const void *b)
{
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;

    if (*ia > *ib) {
        return 1;
    } else if (*ia < *ib) {
        return -1;
    } else {
        return 0;
    }
}

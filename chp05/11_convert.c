#include <stdio.h>

int main(void)
{
    int n, single, tens;

    printf("Enter a two-digit number: ");
    scanf("%d", &n);

    if (n < 10 || n >=100) {
        printf("Illegal two-digit number\n");
        return 0;
    }

    switch (n / 10) {
        case 9:
            printf("ninety");
            break;
        case 8:
            printf("eighty");
            break;
        case 7:
            printf("seventy");
            break;
        case 6:
            printf("sixty");
            break;
        case 5:
            printf("fifty");
            break;
        case 4:
            printf("forty");
            break;
        case 3:
            printf("thirty");
            break;
        case 2:
            printf("twenty");
            break;
        default:
            break;
    }

    switch (n / 10) {
        case 9:
        case 8:
        case 7:
        case 6:
        case 5:
        case 4:
        case 3:
        case 2:
            switch (n % 10) {
                case 1:
                    printf("-one\n");
                    break;
                case 2:
                    printf("-two\n");
                    break;
                case 3:
                    printf("-three\n");
                    break;
                case 4:
                    printf("-four\n");
                    break;
                case 5:
                    printf("-five\n");
                    break;
                case 6:
                    printf("-six\n");
                    break;
                case 7:
                    printf("-seven\n");
                    break;
                case 8:
                    printf("-eight\n");
                    break;
                case 9:
                    printf("-night\n");
                    break;
                default:
                    break;
            }
            break;
        case 1:
            switch (n % 10) {
                case 0:
                    printf("ten\n");
                    break;
                case 1:
                    printf("eleven\n");
                    break;
                case 2:
                    printf("twelve\n");
                    break;
                case 3:
                    printf("thirteen\n");
                    break;
                case 4:
                    printf("fourteen\n");
                    break;
                case 5:
                    printf("fifteen\n");
                    break;
                case 6:
                    printf("sixteen\n");
                    break;
                case 7:
                    printf("seventeen\n");
                    break;
                case 8:
                    printf("eighteen\n");
                    break;
                case 9:
                    printf("nineteen\n");
                    break;
            }
    }

    return 0;
}

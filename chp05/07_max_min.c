#include <stdio.h>

int main(void)
{
    int n1, n2, n3, n4, max, min;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    if (n1 > n2) {
        max = n1;
        min = n2;
    } else {
        max = n2;
        min = n1;
    }

    if (n3 > n4) {
        if (n3 > max) {
            max = n3;
        }
        if (n4 < min) {
            min = n4;
        }
    } else {
        if (n4 > max) {
            max = n4;
        }
        if (n3 < min) {
            min = n3;
        }
    }

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);

    return 0;
}

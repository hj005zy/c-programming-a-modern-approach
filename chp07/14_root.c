#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    double old_root = 0.0;
    double root = 1.0;

    printf("Entera positive number: ");
    scanf("%d", &n);

    while (fabs(root - old_root) > 0.00001) {
        old_root = root;
        root = (root + n / root) / 2;
    }

    printf("Square root: %f\n", root);

    return 0;
}

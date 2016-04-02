#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

int compare_ints(const void *p, const void *q);

int main(void)
{
    int a[N], i;
    clock_t start_clock;

    for (i = 0; i < N; i++) {
        a[i] = N - i;
    }

    start_clock = clock();
    qsort(a, N, sizeof(a[0]), compare_ints);

    printf("Time used to sort %d integers: %g sec.\n", N,
           (clock() - start_clock) / (double) CLOCKS_PER_SEC);

    return 0;
}

int compare_ints(const void *p, const void *q)
{
    return *(int *)p - *(int *)q;
}

#include <stdio.h>

#define N 10

void selection_sort(int a[], int n);
int find_max(int a[], int n);

int main(void)
{
    int a[N], i;

    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    selection_sort(a, N - 1);

    printf("In sorted order: ");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void selection_sort(int a[], int n)
{
    int max, max_index, temp;

    if (n == 0) {
        return;
    }

    max_index = find_max(a, n);
    if (max_index != n) {
        max = a[max_index];
        a[max_index] = a[n];
        a[n] = max;
    }

    selection_sort(a, n - 1);
}

int find_max(int a[], int n)
{
    int i, max = 0, max_index;

    for (i = 0; i <= n; i++) {
        if(a[i] > max) {
            max = a[i];
            max_index = i;
        }
    }

    return max_index;
}

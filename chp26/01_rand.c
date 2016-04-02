#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int count = 1000;

    while (count-- > 0) {
        printf("%d", rand() & 1);
    }
    printf("\n");
    return 0;
}

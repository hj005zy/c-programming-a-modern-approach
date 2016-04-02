#include <stdio.h>

#define MSG_LEN 80

int main(void)
{
    int i;
    char msg[MSG_LEN], *p;

    printf("Enter a message: ");

    for (p = msg; p < msg + MSG_LEN; p++) {
        *p = getchar();
        if (*p == '\n') {
            break;
        }
    }

    printf("Reversal is: ");
    for (p = p - 1; p >= msg; p--) {
        putchar(*p);
    }
    putchar('\n');

    return 0;
}

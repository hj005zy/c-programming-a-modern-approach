#include <stdio.h>

#define MSG_LEN 80

int main(void)
{
    int i;
    char msg[MSG_LEN + 1], *p;

    printf("Enter a message: ");

    for (p = &msg[0]; p < &msg[MSG_LEN]; p++) {
        *p = getchar();
        if (*p == '\n') {
            break;
        }
    }
    *p = 0;

    printf("Reversal is: ");
    for (p = p - 1; p >= &msg[0]; p--) {
        putchar(*p);
    }
    putchar('\n');

    return 0;
}

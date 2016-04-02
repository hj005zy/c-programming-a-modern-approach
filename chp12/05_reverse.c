#include <stdio.h>

#define MSG_LEN 80

int main(void)
{
    char msg[MSG_LEN], *p, *q;
    char ch, termination_char = ' ';

    printf("Enter a sentence: ");

    for (p = msg; p < msg + MSG_LEN; p++) {
        ch = getchar();
        if (ch == '\n') {
            break;
        } else if (ch == '.' || ch == '?' || ch == '!') {
            *p = ch;
            termination_char = ch;
            break;
        } else {
            *p = ch;
        }
    }

    printf("Reversal of sentence: ");
    for (p = p - 1; p > msg; p--) {
        if (*p == ' ') {
            for (q = p + 1; *q != termination_char && *q != ' '; q++) {
                putchar(*q);
            }
            putchar(' ');
        }
    }
    for (; *p != ' '; p++) {
        putchar(*p);
    }
    if (termination_char != ' ') {
        putchar(termination_char);
    }
    putchar('\n');

    return 0;
}

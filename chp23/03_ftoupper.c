#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    bool in_word = false;
    int ch;

    while ((ch = getchar()) != EOF) {
        if (isspace(ch)) {
            in_word = false;
            putchar(ch);
        } else if (!in_word) {
            in_word = true;
            putchar(toupper(ch));
        } else {
            putchar(ch);
        }
    }

    return 0;
}

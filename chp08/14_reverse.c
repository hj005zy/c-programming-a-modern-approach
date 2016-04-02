#include <stdio.h>

int main(void)
{
    char chars[100];
    char ch, termination_char = ' ';
    int i, j, num_chars = 0;

    printf("Enter a sentence: ");

    for (i = 0; ((ch = getchar()) != '\n') && i < 100; i++) {
        if (ch == '.' || ch == '?' || ch == '!') {
            termination_char = ch;
            break;
        }
        chars[i] = ch;
        num_chars++;
    }

    printf("Reversal of sentence: ");
    for (i = num_chars - 1; i >= 0; i--) {
        if (chars[i] == ' ') {
            for (j = i + 1; chars[j] != termination_char && chars[j] != ' '
                    && j < num_chars; j++) {
                putchar(chars[j]);
            }
            putchar(' ');
        } else if (i == 0) {
            for (j = 0; chars[j] != ' '; j++) {
                putchar(chars[j]);
            }
        }
    }
    if (termination_char != ' ') {
        putchar(termination_char);
    }
    putchar('\n');

    return 0;
}

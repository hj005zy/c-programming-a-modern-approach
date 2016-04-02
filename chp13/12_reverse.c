#include <stdio.h>

#define WORD_NUM 30
#define WORD_LEN 20

int read_words(char words[][WORD_LEN + 1], int n, char *termination_char);

int main(void)
{
    char words[WORD_NUM][WORD_LEN + 1], termination_char = ' ';
    int i, words_num = 0;

    printf("Enter a sentence: ");
    words_num = read_words(words, WORD_NUM, &termination_char);

    printf("Reversal of sentence: ");
    for (i = words_num - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i != 0) {
            putchar(' ');
        }
    }
    if (termination_char != ' ') {
        putchar(termination_char);
    }
    putchar('\n');

    return 0;
}

int read_words(char words[][WORD_LEN + 1], int n, char *termination_char)
{
    int ch, i = 0, j = 0;

    while ((ch = getchar()) != '\n') {
        if (ch == '.' || ch == '?' || ch == '!') {
            *termination_char = ch;
            words[i++][j] = 0;
            break;
        } else if (i > n) {
            continue;
        } else if (ch == ' ') {
            words[i++][j] = 0;
            j = 0;
        } else {
            words[i][j++] = ch;
        }
    }

    return i;
}

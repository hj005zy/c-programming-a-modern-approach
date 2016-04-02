#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20   /* max length of word */

int read_line(char str[], int n);
int compare_strings(const void *p, const void *q);

int main(void)
{
    char **words = NULL, **p;
    char word[WORD_LEN];
    int num_word = 0, word_len;

    for (;;) {
        if (words == NULL) {
            words = malloc(sizeof(char *));
        } else {
            words = realloc(words, (num_word + 1) * sizeof(char *));
        }
        if (words == NULL) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter word: ");
        read_line(word, WORD_LEN);
        word_len = strlen(word);
        if (word_len == 0) {
            break;
        }

        words[num_word] = malloc(word_len + 1);
        if (words[num_word] == NULL) {
            printf("-- No space left --\n");
            break;
        }

        strcpy(words[num_word], word);

        num_word++;
    }

    qsort(words, num_word, sizeof(char *), compare_strings);

    printf("\n");
    printf("\n");
    for (p = words; p < words + num_word; p++) {
        printf("%s ", *p);
    }
    printf("\n");

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}

int compare_strings(const void *p, const void *q)
{
    return strcmp(*(char **)p, *(char **)q);
}

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define WORD_LEN 20

void read_word(char word[], int n);
bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char word1[WORD_LEN + 1], word2[WORD_LEN + 1];

    printf("Enter first word: ");
    read_word(word1, WORD_LEN);

    printf("Enter second word: ");
    read_word(word2, WORD_LEN);

    printf("The words are ");
    if (!are_anagrams(word1, word2)) {
        printf("not ");
    }
    printf("anagrams.\n");

    return 0;
}

void read_word(char word[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
            word[i++] = ch;
        }
    }
    word[i] = '\0';
}

bool are_anagrams(const char *word1, const char *word2)
{
    int i, letter_count[26] = {0};

    while (*word1) {
        if (isalpha(*word1)) {
            letter_count[tolower(*word1) - 'a']++;
        }
        word1++;
    }

    while (*word2) {
        if (isalpha(*word2)) {
            letter_count[tolower(*word2) - 'a']--;
        }
        word2++;
    }

    for (i = 0; i < 26; i++) {
        if (letter_count[i] != 0) {
            return false;
        }
    }

    return true;
}

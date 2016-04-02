#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int letter_count[26] = {0};
    bool anagrams = true;
    char ch;
    int i;

    printf("Enter first word: ");
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            letter_count[tolower(ch) - 97]++;
        }
    }

    printf("Enter second word: ");
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            letter_count[tolower(ch) - 97]--;
        }
    }

    for (i = 0; i < 26; i++) {
        if (letter_count[i] != 0) {
            anagrams = false;
            break;
        }
    }

    printf("The words are ");
    if (!anagrams) {
        printf("not ");
    }
    printf("anagrams.\n");

    return 0;
}

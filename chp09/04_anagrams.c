#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void)
{
    int counts1[26] = {0}, counts2[26] = {0};

    printf("Enter first word: ");
    read_word(counts1);

    printf("Enter second word: ");
    read_word(counts2);

    printf("The words are ");
    if (!equal_array(counts1, counts2)) {
        printf("not ");
    }
    printf("anagrams.\n");

    return 0;
}

void read_word(int counts[26])
{
    char ch;

    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            counts[tolower(ch) - 97]++;
        }
    }
}

bool equal_array(int counts1[26], int counts2[26])
{
    for (int i = 0; i < 26; i++) {
        if (counts1[i] != counts2[i]) {
            return false;
        }
    }
    return true;
}

#include <ctype.h>
#include <stdio.h>

#define SENTENCE_LEN 80

void read_line(char str[], int n);
int compute_vowel_count(const char *sentence);

int main(void)
{
    int count;
    char sentence[SENTENCE_LEN + 1];

    printf("Enter a sentence: ");
    read_line(sentence, SENTENCE_LEN);
    count = compute_vowel_count(sentence);

    printf("Your sentence contains %d vowels.\n", count);

    return 0;
}

void read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
}

int compute_vowel_count(const char *sentence)
{
    int count = 0;

    while (*sentence) {
        switch (toupper(*sentence)) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                count++;
                break;
            default:
                break;
        }
        sentence++;
    }

    return count;
}

#include <ctype.h>
#include <stdio.h>

#define WORD_LEN 20

void read_line(char str[], int n);
int compute_scrabble_value(const char *word);

int main(void)
{
    int sum;
    char word[WORD_LEN + 1];

    printf("Enter a word: ");
    read_line(word, WORD_LEN);
    sum = compute_scrabble_value(word);

    printf("Scrabble value: %d\n", sum);

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

int compute_scrabble_value(const char *word)
{
    int sum = 0;

    while (*word) {
        switch (toupper(*word)) {
            case 'D':
            case 'G':
                sum += 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                sum += 3;
                break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                sum += 4;
                break;
            case 'K':
                sum += 5;
                break;
            case 'J':
            case 'X':
                sum += 8;
                break;
            case 'Q':
            case 'Z':
                sum += 10;
                break;
            default:
                sum += 1;
                break;
        }
        word++;
    }

    return sum;
}

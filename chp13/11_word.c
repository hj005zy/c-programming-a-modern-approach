#include <ctype.h>
#include <stdio.h>

#define SENTENCE_LEN 100

void read_line(char str[], int n);
double compute_average_word_length(const char *sentence);

int main(void)
{
    char sentence[SENTENCE_LEN + 1];
    double average_word_length;

    printf("Enter a sentence: ");
    read_line(sentence, SENTENCE_LEN);
    average_word_length = compute_average_word_length(sentence);

    printf("Average word length: %.1f\n", average_word_length);

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

double compute_average_word_length(const char *sentence)
{
    int length = 0, count = 0;

    for(;;) {
        if (isalpha(*sentence)) {
            length++;
        } else if (*sentence == ' ') {
            count++;
        } else if (*sentence == 0) {
            count++;
            break;
        }
        sentence++;
    }

    return (double) length / count;
}

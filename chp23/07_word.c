#include <stdio.h>
#include <string.h>

int main(void)
{
    int ch, pre_ch, num_sentence = 0;

    while ((ch = getchar()) != EOF) {
        if (strchr(".?!", pre_ch) != NULL
            && strchr(" \t\n", ch) != NULL) {
            num_sentence++;
        }
        pre_ch = ch;
    }
    printf("Number of sentence: %d\n", num_sentence);

    return 0;
}

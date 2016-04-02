#include <stdio.h>

int main(void)
{
    int length = 0;
    int count = 0;
    char ch;

    printf("Enter a sentence: ");

    for (;;) {
        ch = getchar();
         if (ch == ' ') {
            count++;
        } else if (ch == '\n') {
            count++;
            break;
        } else {
            length++;
        }
    }

    printf("Average word length: %.1f\n", (double) length / count);

    return 0;
}

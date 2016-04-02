#include <stdio.h>

#define MAX_NUM 15

int main(void)
{
    char ch;
    int i, num_chars = 0;
    char chars[MAX_NUM];

    printf("Enter phone number: ");

    for (i = 0; ((ch = getchar()) != '\n') && i < MAX_NUM; i++) {
        chars[i] = ch;
        num_chars++;
    }
    
    for (i = 0; i < num_chars; i++) {
        ch = chars[i];
        if (ch >= 'A' && ch <= 'C') {
            printf("2");
        } else if (ch >= 'D' && ch <= 'F') {
            printf("3");
        } else if (ch >= 'G' && ch <= 'I') {
            printf("4");
        } else if (ch >= 'J' && ch <= 'L') {
            printf("5");
        } else if (ch >= 'M' && ch <= 'O') {
            printf("6");
        } else if (ch >= 'P' && ch <= 'S') {
            printf("7");
        } else if (ch >= 'T' && ch <= 'V') {
            printf("8");
        } else if (ch >= 'W' && ch <= 'Z') {
            printf("9");
        } else {
            putchar(ch);
        }
    }
    printf("\n");

    return 0;
}

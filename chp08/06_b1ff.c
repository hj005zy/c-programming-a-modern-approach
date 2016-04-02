#include <stdio.h>
#include <ctype.h>

#define N 100

int main(void)
{
    char chars[N];
    char ch;
    int i, count = 0;

    printf("Enter message: ");

    ch = getchar();
    for (i = 0; i < N && ch != '\n'; i++) {
        chars[i] = toupper(ch);
        ch = getchar();
        count++;
    }

    printf("In B1FF-speak: ");
    for (i = 0; i < count; i++) {
        ch = chars[i];
        switch (ch) {
            case 'A':
                putchar('4');
                break;
            case 'B':
                putchar('8');
                break;
            case 'E':
                putchar('3');
                break;
            case 'I':
                putchar('1');
                break;
            case 'O':
                putchar('0');
                break;
            case 'S':
                putchar('5');
                break;
            default:
                putchar(ch);
                break;
        }
    }
    printf("!!!!!!!!!!\n");

    return 0;
}

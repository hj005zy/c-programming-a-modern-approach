#include <stdio.h>

int main(void)
{

    char chars[80];
    char ch;
    int shift_amount, i, num_chars = 0;

    printf("Enter message to be encrypted: ");

    for (i = 0; (ch = getchar()) != '\n' && i < 80; i++) {
        chars[i] = ch;
        num_chars++;
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift_amount);

    printf("Encrypted message: ");

    for (i = 0; i < num_chars; i++) {
        ch = chars[i];
        if (ch >= 'A' && ch <= 'Z') {
            putchar(((ch - 'A') + shift_amount) % 26 + 'A');
        } else if (ch >= 'a' && ch <= 'z') {
            putchar(((ch - 'a') + shift_amount) % 26 + 'a');
        } else {
            putchar(ch);
        }
    }
    putchar('\n');

    return 0;
}

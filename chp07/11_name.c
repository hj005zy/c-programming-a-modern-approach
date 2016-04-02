#include <stdio.h>

int main(void)
{
    char ch, first_name_letter;

    printf("Enter a first and last name: ");

    first_name_letter = getchar();

    while (getchar() != ' ');

    while ((ch = getchar()) != '\n') {
        putchar(ch);
    }
    printf(" %c.\n", first_name_letter);

    return 0;
}

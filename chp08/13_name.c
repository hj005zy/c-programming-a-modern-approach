#include <stdio.h>

int main(void)
{
    char ch, first_name_letter;
    char last_names[20];
    int i, last_name_length = 0;

    printf("Enter a first and last name: ");

    first_name_letter = getchar();

    while (getchar() != ' ');

    for (i = 0; ((ch = getchar()) != '\n') && i < 20; i++) {
        last_names[i] = ch;
        last_name_length++;
    }
    for (i = 0; i < last_name_length; i++) {
        putchar(last_names[i]);
    }
    printf(", %c.\n", first_name_letter);

    return 0;
}

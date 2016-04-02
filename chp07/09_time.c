#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hour, minute;
    char ch;

    printf("Enter a 12-hour time: ");
    scanf("%d:%d", &hour, &minute);

    while ((ch = getchar()) == ' ');
    if (toupper(ch) == 'P') {
        hour += 12;
    }

    printf("Equivalent 24-hour time: %d:%d\n", hour, minute);

    return 0;
}

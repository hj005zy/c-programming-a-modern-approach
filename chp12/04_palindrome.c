#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#define MSG_LEN 80

int main(void) 
{
    int i = 0;
    char ch, msg[MSG_LEN], *p, *q;
    bool palindrome = true;

    q = msg;
    printf("Enter a message: ");
    while ((ch = getchar()) != '\n' && q < msg + MSG_LEN) {
        if (isalpha(ch)) {
            *q++ = tolower(ch);
        }
    }

    p = msg;
    q--;
    while (p < q) {
        if (*p++ != *q--) {
            palindrome = false;
        }
    }

    if(palindrome) {
        printf("Palindrome");
    } else {
        printf("Not a palindrome");
    }
    printf("\n");

    return 0;
}

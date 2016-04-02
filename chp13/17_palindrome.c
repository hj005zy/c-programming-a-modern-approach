#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MSG_LEN 80

void read_message(char message[], int n);
bool is_palindrome(const char *message);

int main(void) 
{
    char message[MSG_LEN + 1];

    printf("Enter a message: ");
    read_message(message, MSG_LEN);

    if(is_palindrome(message)) {
        printf("Palindrome");
    } else {
        printf("Not a palindrome");
    }
    printf("\n");

    return 0;
}

void read_message(char message[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
            if (isalpha(ch)) {
                message[i++] = tolower(ch);
            }
        }
    }
    message[i] = '\0';
}

bool is_palindrome(const char *message)
{
    const char *message_end = message + strlen(message) - 1;

    while (message < message_end) {
        if(*message++ != *message_end--) {
            return false;
        }
    }
    return true;
}

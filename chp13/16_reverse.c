#include <stdio.h>
#include <string.h>

#define MSG_LEN 80

void read_message(char message[], int n);
void reverse(char *message);

int main(void)
{
    int i;
    char message[MSG_LEN + 1], *p;

    printf("Enter a message: ");
    read_message(message, MSG_LEN);

    reverse(message);
    printf("Reversal is: %s\n", message);

    return 0;
}

void read_message(char message[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
            message[i++] = ch;
        }
    }
    message[i] = '\0';
}

void reverse(char *message)
{
    char temp, *message_end = message + strlen(message) - 1;

    while (message < message_end) {
        temp = *message;
        *message++ = *message_end;
        *message_end-- = temp;
    }
}

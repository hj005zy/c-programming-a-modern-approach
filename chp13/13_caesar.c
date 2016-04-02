#include <stdio.h>

#define MSG_LEN 100

void read_message(char message[], int n);
void encrypt(char *message, int shift);

int main(void)
{

    char message[MSG_LEN + 1];
    char ch;
    int shift_amount, i, num_chars = 0;

    printf("Enter message to be encrypted: ");
    read_message(message, MSG_LEN);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift_amount);
    
    encrypt(message, shift_amount);

    printf("Encrypted message: ");
    puts(message);

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

void encrypt(char *message, int shift)
{
    while (*message) {
        if (*message >= 'A' && *message <= 'Z') {
            *message = ((*message - 'A') + shift) % 26 + 'A';
        } else if (*message >= 'a' && *message <= 'z') {
            *message = ((*message - 'a') + shift) % 26 + 'a';
        }
        message++;
    }
}

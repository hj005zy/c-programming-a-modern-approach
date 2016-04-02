/* Prints a one-month reminder list (dynamic string version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50   /* maxium number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int read_line(char str[], int n);

struct vstring {
    int len;
    char chars[];
};

int main(void)
{
    struct vstring *reminders[MAX_REMIND];
    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0, reminder_len;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0) {
            break;
        }
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++) {
            if (strcmp(day_str, reminders[i]->chars) < 0) {
                break;
            }
        }
        for (j = num_remind; j > i; j--) {
            reminders[j] = reminders[j - 1];
        }

        reminder_len = 2 + strlen(msg_str);
        reminders[i] = malloc(sizeof(struct vstring) + reminder_len);
        if (reminders[i] == NULL) {
            printf("-- No space left --\n");
            break;
        }

        reminders[i]->len = reminder_len;
        strcpy(reminders[i]->chars, day_str);
        strncat(reminders[i]->chars, msg_str, reminder_len - 2);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++) {
        for (j = 0; j < reminders[i]->len; j++) {
            putchar((reminders[i]->chars)[j]);
        }
        printf("\n");
    }

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}

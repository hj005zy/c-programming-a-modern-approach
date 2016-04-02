#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NAME_LEN 100

void read_line(char str[], int n);
void reverse_name(char *name);

int main(void)
{
    char name[NAME_LEN + 1];

    printf("Enter a first and last name: ");
    read_line(name, NAME_LEN);
    reverse_name(name);
    puts(name);

    return 0;
}

void read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
}

void reverse_name(char *name)
{
    char first_name_str[] = {' ', ' ', '.', '\0'},
         *first_name = name, *last_name = name + strlen(name) - 1;

    while (isspace(*first_name)) {
        first_name++;
    }
    if (*first_name == 0) {
        return;
    }

    first_name_str[1] = *first_name;

    while (last_name > name && isspace(*last_name)) {
        last_name--;
    }
    *(last_name + 1) = 0;
    while(!isspace(*last_name)) {
        last_name--;
    }
    strcpy(name, last_name + 1);
    strcat(name, first_name_str);
}   

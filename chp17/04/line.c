#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct node {
    const char *word;
    struct node *next;
} *head = NULL, *tail = NULL;

int line_len = 0;
int num_words = 0;

char *duplicate(const char *s);

void clear_line(void)
{
    struct node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    struct node *new_word;

    new_word = malloc(sizeof(*new_word));
    if (new_word == NULL) {
        printf("Error malloc in add_word\n");
        exit(EXIT_FAILURE);
    }
    new_word->word = duplicate(word);
    new_word->next = NULL;
    if (head != NULL) {
        tail->next = new_word;
        tail = new_word;
        line_len++;
    } else {
        head = new_word;
        tail = new_word;
    }
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    struct node *p;
    int extra_spaces, spaces_to_insert, i;
    bool first = true;

    extra_spaces = MAX_LINE_LEN - line_len;
    for (p = head; p != NULL; p = p->next) {
        if (first) {
            first = false;
        } else {
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (i = 1; i <= spaces_to_insert + 1; i++) {
                putchar(' ');
            }
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
        printf("%s", p->word);
    }
    putchar('\n');
}

void flush_line(void)
{
    struct node *p;
    bool first = true;

    if (line_len > 0) {
        for (p = head; p != NULL; p = p->next) {
            if (first) {
                first = false;
            } else {
                putchar(' ');
            }
            printf("%s", p->word);
        }
        putchar('\n');
    }
}

char *duplicate(const char *s)
{
    char *temp = malloc(strlen(s) + 1);
    if (temp == NULL) {
        return NULL;
    }

    strcpy(temp, s);
    return temp;
}

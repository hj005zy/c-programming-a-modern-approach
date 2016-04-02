#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    if (num_words > 0) {
        line[line_len] = ' ';
        line[line_len + 1] = '\0';
        line_len++;
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces, spaces_to_insert, min_spaces_to_insert,
        left_side_remainning_spaces, right_side_remainning_spaces,
        remaining_spaces, i, j;

    extra_spaces = MAX_LINE_LEN - line_len;
    min_spaces_to_insert = extra_spaces / (num_words - 1) + 1;
    remaining_spaces = extra_spaces % (num_words - 1);
    left_side_remainning_spaces = right_side_remainning_spaces =
        remaining_spaces / 2;
    if (remaining_spaces % 2 != 0) {
        right_side_remainning_spaces++;
    }
    for (i = 0; i < line_len; i++) {
        if (line[i] != ' ') {
            putchar(line[i]);
        } else {
            if (left_side_remainning_spaces > 0) {
                spaces_to_insert = min_spaces_to_insert + 1;
                left_side_remainning_spaces--;
            } else if (right_side_remainning_spaces > 0
                           && right_side_remainning_spaces == num_words - 1) {
                spaces_to_insert = min_spaces_to_insert + 1;
                right_side_remainning_spaces--;
            } else {
                spaces_to_insert = min_spaces_to_insert;
            }
            for (j = 1; j <= spaces_to_insert; j++) {
                putchar(' ');
            }
            num_words--;
        }
    }
    putchar('\n');
}

void flush_line(void)
{
    if (line_len > 0) {
        puts(line);
    }
}

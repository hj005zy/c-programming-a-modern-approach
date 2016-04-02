#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "15_line.h"
#include "15_word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;
    char word[MAX_WORD_LEN + 2];
    int word_len;

    if (argc != 3) {
        fprintf(stderr, "usage justify file1 file2\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    dest_fp = fopen(argv[2], "w");

    clear_line();
    for (;;) {
        word_len = read_word(source_fp, word, MAX_WORD_LEN + 1);
        if (word_len == 0) {
            flush_line(dest_fp);
            return 0;
        }
        if (word_len > MAX_WORD_LEN) {
            word[MAX_WORD_LEN] = '*';
        }
        if (word_len + 1 > space_remaining()) {
            write_line(dest_fp);
            clear_line();
        }
        add_word(word);
    }
}

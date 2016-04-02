#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;
    int ch, i = 1, j, count, len;
    char file_extension[4], *file_name;
    bool count_mode = true;

    if (argc != 2) {
        fprintf(stderr, "usage: uncompress_file file\n");
        exit(EXIT_FAILURE);
    }

    len = strlen(argv[1]);
    strncpy(file_extension, argv[1] + len - 3, 3);
    file_extension[3] = '\0';
    if (strcmp(file_extension, "rle") != 0) {
        fprintf(stderr, "File extension %s is invalid\n", file_extension);
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    file_name = malloc(sizeof(char) * (len - 4 + 1));
    strncpy(file_name, argv[1], len - 4);
    file_name[len - 4] = '\0';

    dest_fp = fopen(file_name, "wb");

    while ((ch = getc(source_fp)) != EOF) {
        if (count_mode) {
            count = ch;
            count_mode = false;
        } else {
            for (j = 0; j < count; j++) {
                putc(ch, dest_fp);
            }
            count_mode = true;
        }
    }

    return 0;
}

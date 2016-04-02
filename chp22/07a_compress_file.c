#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;
    int ch, pre_ch, count = 0;

    if (argc != 2) {
        fprintf(stderr, "usage: compress_file file\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    dest_fp = fopen(strcat(argv[1], ".rle"), "wb");

    pre_ch = EOF;
    while ((ch = getc(source_fp)) != EOF) {
        if (ch == pre_ch) {
            count++;
        } else {
            if (count > 0) {
                putc(count, dest_fp);
                putc(pre_ch, dest_fp);
            }
            count = 1;
            pre_ch = ch;
        }
    }
    putc(count, dest_fp);
    putc(pre_ch, dest_fp);

    fclose(source_fp);
    fclose(dest_fp);
    return 0;
}

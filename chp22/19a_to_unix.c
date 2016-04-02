#include <stdio.h>
#include <stdlib.h>

#define CR 13
#define LF 10
#define WIN_EOF 26

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;
    int ch, pre_ch = ' ';

    if (argc != 3) {
        fprintf(stderr, "usage: to_unix file1 file2\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    dest_fp = fopen(argv[2], "wb");

    while ((ch = getc(source_fp)) != EOF) {
        if (ch != CR && ch != LF && ch != WIN_EOF) {
            putc(ch, dest_fp);
        } else if (pre_ch == CR && ch == LF) {
            putc(ch, dest_fp);
        } else if (pre_ch == WIN_EOF) {
            putc(pre_ch, dest_fp);
            putc(ch, dest_fp);
        }
        pre_ch = ch;
    }
    
    fclose(source_fp);
    fclose(dest_fp);
    return 0;
}

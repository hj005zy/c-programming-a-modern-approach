#include <stdio.h>
#include <stdlib.h>

#define CR 13
#define LF 10
#define WIN_EOF 26

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;
    int ch;

    if (argc != 3) {
        fprintf(stderr, "usage: to_win file1 file2\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    dest_fp = fopen(argv[2], "wb");

    while ((ch = getc(source_fp)) != EOF) {
        if (ch == LF) {
            putc(CR, dest_fp);
        }
        putc(ch, dest_fp);
    }
    putc(WIN_EOF, dest_fp);
    
    fclose(source_fp);
    fclose(dest_fp);
    return 0;
}

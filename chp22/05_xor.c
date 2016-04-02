#include <stdio.h>
#include <Stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;
    int orig_char, new_char;

    if (argc != 3) {
        fprintf(stderr, "usage: xor source dest\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    dest_fp = fopen(argv[2], "wb");

    while ((orig_char = fgetc(source_fp)) != EOF) {
        new_char = orig_char ^ KEY;
        if (fputc(new_char, dest_fp) == EOF) {
            fprintf(stderr, "Error during writing: xor terminated\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(source_fp);
    fclose(dest_fp);
    return 0;
}

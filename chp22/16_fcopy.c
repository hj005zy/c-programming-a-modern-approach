/* Copies a file */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_BYTES 512

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;
    int num_read;
    unsigned char buffer[BUFFER_BYTES];

    if (argc != 3) {
        fprintf(stderr, "usage: fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    dest_fp = fopen(argv[2], "wb");

    while ((num_read = fread(buffer, 1, BUFFER_BYTES, source_fp)) > 0) {
        fwrite(buffer, 1, num_read, dest_fp);
        if (num_read < BUFFER_BYTES) {
            break;
        }
    }

    fclose(source_fp);
    fclose(dest_fp);
    return 0;
}

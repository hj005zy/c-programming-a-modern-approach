#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_LEN 25

int main(void)
{
    FILE *source_fp, *dest_fp;
    int size = 100, buffer = size, old_size;
    char *line, *offset;
    char filename[FILENAME_LEN + 1];
    char ch;
    int line_len, shift_amount, i, num_chars = 0;

    line = malloc(sizeof(char) * size + 1);
    if (line == NULL) {
        fprintf(stderr, "Can not initialize line.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter name of file to be encrypted: ");
    scanf("%s", filename);

    if ((source_fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    dest_fp = fopen(strcat(filename, ".enc"), "w");

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift_amount);

    offset = line;
    while (fgets(offset, buffer + 1, source_fp) != NULL) {
        line_len = strlen(line);
        if (line[line_len - 1] == '\n') {
            for (i = 0; i < line_len - 1; i++) {
                ch = line[i];
                if (ch >= 'A' && ch <= 'Z') {
                    line[i] = ((ch - 'A') + shift_amount) % 26 + 'A';
                } else if (ch >= 'a' && ch <= 'z') {
                    line[i] = ((ch - 'a') + shift_amount) % 26 + 'a';
                }
            }
            fputs(line, dest_fp);
            free(line);
            line = malloc(sizeof(char) * size + 1);
            if (line == NULL) {
                fprintf(stderr, "Can not initialize line.\n");
                exit(EXIT_FAILURE);
            }
            offset = line;
            size = 10;
        } else {
            old_size = size;
            size += sizeof(char) * buffer;
            line = realloc(line, size + 1);
            if (line == NULL) {
                fprintf(stderr, "Insufficient memory: can't read more characters.\n");
                exit(EXIT_FAILURE);
            }
            offset = line + old_size;
        }
    }

    fclose(source_fp);
    fclose(dest_fp);
    return 0;
}

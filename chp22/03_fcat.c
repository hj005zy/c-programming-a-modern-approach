#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char **p;
    int ch;
    bool all_files_open_failed = true;

    if (argc < 2) {
        fprintf(stderr, "usage: fcat filename\n");
        exit(EXIT_FAILURE);
    }

    for (p = &argv[1]; *p != NULL; p++) {
        if ((fp = fopen(*p, "r")) != NULL) {
            all_files_open_failed = false;
            while ((ch = getc(fp)) != EOF) {
                putchar(ch);
            } 
            fclose(fp);
        }
    }

    if (all_files_open_failed) {
        fprintf(stderr, "Can't open any files\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char **p;

    if (argc < 2) {
        fprintf(stderr, "usage: canopen filename\n");
        exit(EXIT_FAILURE);
    }

    for (p = &argv[1]; *p != NULL; p++) {
        if ((fp = fopen(*p, "r")) == NULL) {
            fprintf(stderr, "%s can't be opened\n", *p);
            exit(EXIT_FAILURE);
        } else {
            printf("%s can be opened\n", *p);
            fclose(fp);
        }
    }

    return 0;
}

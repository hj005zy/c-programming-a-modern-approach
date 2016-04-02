#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 25

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[LINE_LEN + 1];
    int num[10];
    int n1, n2, n3, line_len, i, j;

    if (argc != 2) {
        fprintf(stderr, "usage: phone_num file\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        line_len = strlen(line);
        for (i = 0, j = 0; i < line_len && i < 10; i++) {
            if (isnumber(line[i])) {
                num[j++] = line[i] - '0';
            }
        }
        n1 = n2 = n3 = 0;
        for (i = 0; i < 3; i++) {
            n1 = n1 * 10 + num[i];
        }
        for (; i < 6; i++) {
            n2 = n2 * 10 + num[i];
        }
        for (; i < 10; i++) {
            n3 = n3 * 10 + num[i];
        }
        printf("(%.3d) %.3d-%.4d\n", n1, n2, n3);
    }

    fclose(fp);
    return 0;
}

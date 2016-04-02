#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 100

struct str_list {
    char *str;
    struct str_list *next;
};

int main(void)
{
    struct str_list *list, *new_node, *list_p;
    char *p, str[STR_LEN + 1];
    int len;

    printf("Enter some words: ");
    fgets(str, sizeof(str), stdin);
    len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    p = strtok(str, " \t");
    if (p == NULL) {
        return 0;
    }

    list = malloc(sizeof(*list));
    list->str = p;
    list->next = NULL;

    while ((p = strtok(NULL, " \t")) != NULL) {
        new_node = malloc(sizeof(*new_node));
        new_node->str = p;
        new_node->next = list;
        list = new_node;
    }

    for (list_p = list; list_p != NULL; list_p = list_p->next) {
        printf("%s ", list_p->str);
    }
    printf("\n");

    return 0;
}

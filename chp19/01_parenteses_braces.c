#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void)
{
    char ch, pop_char;
    Stack s = create();
    bool properly = true;

    printf("Enter parenteses and/or braces: ");

    while ((ch = getchar()) != '\n') {
        if (ch == '{' || ch == '(') {
            push(s, ch);
        } else if (is_empty(s)) {
            properly = false;
            break;
        } else {
            pop_char = pop(s);
            if (ch == '}' && pop_char != '{') {
                properly = false;
                break;
            } else if (ch == ')' && pop_char != '(') {
                properly = false;
                break;
            }
        }
    }

    properly = properly && is_empty(s);

    printf("Parenteses/braces are ");
    if (!properly) {
        printf("not ");
    }
    printf("nested properly\n");

    return 0;
}

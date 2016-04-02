#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
char pop(void);
void stack_overflow(void);
char stack_underflow(void);

int main(void)
{
    char ch;
    bool properly = true;

    printf("Enter parenteses and/or braces: ");

    while ((ch = getchar()) != '\n') {
        if (ch == '{' || ch == '(') {
            push(ch);
        } else if (is_empty()) {
            properly = false;
            break;
        } else {
            char pop_char = pop();
            if (ch == '}' && pop_char != '{') {
                properly = false;
                break;
            } else if (ch == ')' && pop_char != '(') {
                properly = false;
                break;
            }
        }
    }

    properly = properly && is_empty();
    
    printf("Parenteses/braces are ");
    if (!properly) {
        printf("not ");
    }
    printf("nested properly\n");

    return 0;
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char ch)
{
    if (is_full()) {
        stack_overflow();
    } else {
        contents[top++] = ch;
    }
}

char pop(void)
{
    if (is_empty()) {
        return stack_underflow();
    } else {
        return contents[--top];
    }
}

void stack_overflow(void)
{
    printf("Stack overflow\n");
    exit(EXIT_SUCCESS);
}

char stack_underflow(void)
{
    return ' ';
}

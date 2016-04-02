#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

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

void push(int n)
{
    if (is_full()) {
        stack_overflow();
    } else {
        contents[top++] = n;
    }
}

int pop(void)
{
    if (is_empty()) {
        stack_underflow();
        // The program will exit in stack_underflow
        // so code belowing won't be excuted
        return 0;
    } else {
        return contents[--top];
    }
}

void stack_overflow(void)
{
    printf("Expression is too complex\n");
    exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
    printf("Not enough operands in expression\n");
    exit(EXIT_SUCCESS);
}

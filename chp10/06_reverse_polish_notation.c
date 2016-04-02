#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int n);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    char ch;
    int n = 0, operand1, operand2;
    bool previous_operand = false;

    while (ch != 'q') {
        printf("Enter an RPN expression: ");
        while ((ch = getchar()) != '\n') {
            if (ch == 'q') {
                break;
            } else if (ch == ' ') {
                if (previous_operand) {
                    previous_operand = false;
                    push(n);
                    n = 0;
                }
            } else if (ch >= '0' && ch <= '9') {
                n = n * 10 + (ch - '0');
                previous_operand = true;
            } else if (ch == '+') {
                operand1 = pop();
                operand2 = pop();
                push(operand2 + operand1);
            } else if (ch == '-') {
                operand1 = pop();
                operand2 = pop();
                push(operand2 - operand1);
            } else if (ch == '*') {
                operand1 = pop();
                operand2 = pop();
                push(operand2 * operand1);
            } else if (ch == '/') {
                operand1 = pop();
                operand2 = pop();
                push(operand2 / operand1);
            } else if (ch == '=') {
                printf("Value of expression: %d\n", pop());
            } else {
                printf("Invalid expression\n");
                return 0;
            }
        }
    }

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

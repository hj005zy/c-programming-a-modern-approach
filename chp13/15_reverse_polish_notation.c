#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define EXPRESSION_LEN 20
#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void read_expression(char expression[], int n);
int evaluate_RPN_expression(const char *expression);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int n);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    char expression[EXPRESSION_LEN + 1];

    for (;;) {
        printf("Enter an RPN expression: ");
        read_expression(expression, EXPRESSION_LEN);
        if (!*expression) {
            continue;
        } else if (*expression == 'q') {
            return 0;
        }
        printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
    }
}

void read_expression(char expression[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
            expression[i++] = ch;
        }
    }
    expression[i] = '\0';
}

int evaluate_RPN_expression(const char *expression)
{
    int n = 0, operand1, operand2, result;
    bool previous_operand = false;

    while(*expression) {
        if (*expression == ' ') {
            if (previous_operand) {
                previous_operand = false;
                push(n);
                n = 0;
            }
        } else if (*expression >= '0' && *expression <= '9') {
            n = n * 10 + (*expression - '0');
            previous_operand = true;
        } else if (*expression == '+') {
            operand1 = pop();
            operand2 = pop();
            push(operand2 + operand1);
         } else if (*expression == '-') {
            operand1 = pop();
            operand2 = pop();
            push(operand2 - operand1);
        } else if (*expression == '*') {
            operand1 = pop();
            operand2 = pop();
            push(operand2 * operand1);
        } else if (*expression == '/') {
            operand1 = pop();
            operand2 = pop();
            push(operand2 / operand1);
        } else if (*expression == '=') {
            result = pop();
            return result;
        } else {
            printf("Invalid expression\n");
            exit(EXIT_SUCCESS);
        }
        expression++;
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

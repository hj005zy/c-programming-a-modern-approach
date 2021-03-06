#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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

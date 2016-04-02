#include <stdio.h>
#include "05_queueADT.h"

int main(void)
{
    Queue q1, q2;
    int n;

    q1 = create();
    q2 = create();

    add_last(q1, 1);
    add_last(q1, 2);
    add_last(q1, 3);

    n = remove_first(q1);
    printf("Removed %d from q1\n", n);
    add_last(q2, n);
    n = remove_first(q1);
    printf("Removed %d from q1\n", n);
    add_last(q2, n);
    n = remove_first(q1);
    printf("Removed %d from q1\n", n);
    add_last(q2, n);

    printf("Get first %d from q2\n", get_first(q2));
    printf("Get last %d from q2\n", get_last(q2));
    while (!is_empty(q2)) {
        printf("Removed %d from q2\n", remove_first(q2));
    }

    add_last(q2, 4);
    make_empty(q2);
    if (is_empty(q2)) {
        printf("q2 is empty\n");
    } else {
        printf("q2 is not empty\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "07_queueADT.h"

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *head;
    struct node *tail;
};

static void terminate (const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) {
        terminate("Error in create: queue could not be created.");
    }
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void destroy(Queue q)
{
    make_empty(q);
    free(q);
}

void make_empty(Queue q)
{
    while(!is_empty(q)) {
        remove_first(q);
    }
}

bool is_empty(Queue q)
{
    return q->head == NULL;
}

bool is_full(Queue q)
{
    return false;
}

void add_last(Queue q, Item i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        terminate("Error in add_last: queue is full.");
    }

    new_node->data = i;
    new_node->next = NULL;
    if (is_empty(q)) {
        q->head = new_node;
    } else {
        q->tail->next = new_node;
    }
    q->tail = new_node;
}

Item remove_first(Queue q)
{
    struct node *old_head;
    Item i;

    if (is_empty(q)) {
        terminate("Error in remove_first; queue is empty.");
    }

    old_head = q->head;
    i = old_head->data;
    q->head = old_head->next;
    free(old_head);
    return i;
}

Item get_first(Queue q)
{
    if (is_empty(q)) {
        terminate("Error in get_first; queue is empty.");
    }
    return q->head->data;
}

Item get_last(Queue q)
{
    if (is_empty(q)) {
        terminate("Error in get_last; queue is empty.");
    }
    return q->tail->data;
}

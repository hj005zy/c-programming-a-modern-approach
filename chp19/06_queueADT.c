#include <stdio.h>
#include <stdlib.h>
#include "06_queueADT.h"

struct queue_type {
    Item *contents;
    int head;
    int tail;
    int num_item;
    int size;
};

static void terminate (const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(int size)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) {
        terminate("Error in create: queue could not be created.");
    }
    q->contents = malloc(size * sizeof(Item));
    if (q->contents == NULL) {
        terminate("Error in create: queue could not be created.");
    }
    q->head = 0;
    q->tail = 0;
    q->num_item = 0;
    q->size = size;
    return q;
}

void destroy(Queue q)
{
    free(q->contents);
    free(q);
}

void make_empty(Queue q)
{
    q->head = 0;
    q->tail = 0;
    q->num_item = 0;
}

bool is_empty(Queue q)
{
    return q->num_item == 0;
}

bool is_full(Queue q)
{
    return q->num_item == q->size;
}

void add_last(Queue q, Item i)
{
    if (is_full(q)) {
        terminate("Error in add_last: queue is full.");
    }
    if (q->tail == q->size) {
        q->tail = 0;
    }
    q->contents[q->tail++] = i;
    q->num_item++;
}

Item remove_first(Queue q)
{
    Item i;

    if (is_empty(q)) {
        terminate("Error in remove_first; queue is empty.");
    }
    if (q->head == q->size) {
        q->head = 0;
    }
    i = q->contents[q->head++];
    q->num_item--;
    return i;
}

Item get_first(Queue q)
{
    if (is_empty(q)) {
        terminate("Error in get_first; queue is empty.");
    }
    if (q->head == q->size) {
        q->head = 0;
    }
    return q->contents[q->head];
}

Item get_last(Queue q)
{
    if (is_empty(q)) {
        terminate("Error in get_last; queue is empty.");
    }
    return q->contents[q->tail - 1];
}

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;

typedef struct queue_type *Queue;

Queue create(int size);
void destroy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
bool is_full(Queue q);
void add_last(Queue q, Item i);
Item remove_first(Queue q);
Item get_first(Queue q);
Item get_last(Queue q);

#endif

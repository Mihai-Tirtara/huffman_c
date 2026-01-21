#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdlib.h>

typedef struct PriorityQueue {
    void** array;
    int capacity;
    size_t size;
    int (*compare)(void* a, void* b);
} PriorityQueue;

PriorityQueue* create_pq(int capacity, int (*compare)(void*a, void*b));

void swap(PriorityQueue* priority_queue, int index1, int index2);

void heapify_up(PriorityQueue* priority_queue, int index);

void heapify_down(PriorityQueue* priority_queue, int index);

void insert(PriorityQueue* priority_queue, void* element);

void* extract(PriorityQueue* priority_queue, void** out_element);

void free_pq(PriorityQueue* priority_queue);

#endif // PRIORITY_QUEUE_H

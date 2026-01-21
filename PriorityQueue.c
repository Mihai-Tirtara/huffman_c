#include "PriorityQueue.h"

#include <stdio.h>
#include <stdlib.h>

PriorityQueue* create_pq(int capacity, int (*compare)(void* a, void* b)) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->array = (void**)malloc(sizeof(void*) * capacity);
    pq->capacity = capacity;
    pq->size = 0;
    pq->compare = compare;
    return pq;
}

void swap(PriorityQueue* priority_queue, int index1, int index2) {
    void* temp = priority_queue->array[index1];
    priority_queue->array[index1] = priority_queue->array[index2];
    priority_queue->array[index2] = temp;
}

void heapify_up(PriorityQueue* priority_queue, int index) {ex) {

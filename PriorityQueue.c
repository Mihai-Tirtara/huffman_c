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

void heapify_up(PriorityQueue* priority_queue, int index) {
    if (index == 0) return;
    int parent_index = (index - 1) / 2;
    if (priority_queue->compare(priority_queue->array[index], priority_queue->array[parent_index]) > 0) {
        swap(priority_queue, index, parent_index);
        heapify_up(priority_queue, parent_index);
    }
}

void heapify_down(PriorityQueue* priority_queue, int index) {
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;
    int smallest_index = index;

    if (left_child_index < priority_queue->size &&
        priority_queue->compare(priority_queue->array[left_child_index], priority_queue->array[smallest_index]) > 0) {
        smallest_index = left_child_index;
    }

    if (right_child_index < priority_queue->size &&
        priority_queue->compare(priority_queue->array[right_child_index], priority_queue->array[smallest_index]) > 0) {
        smallest_index = right_child_index;
    }

    if (smallest_index != index) {
        swap(priority_queue, index, smallest_index);
        heapify_down(priority_queue, smallest_index);
    }
}

void insert(PriorityQueue* priority_queue, void* element) {
    if (priority_queue->size >= priority_queue->capacity) {
        // Resize the array if needed
        priority_queue->capacity *= 2;
        priority_queue->array = (void**)realloc(priority_queue->array, sizeof(void*) * priority_queue->capacity);
    }
    priority_queue->array[priority_queue->size] = element;
    priority_queue->size++;
    heapify_up(priority_queue, priority_queue->size - 1);
}

void* extract(PriorityQueue* priority_queue, void** out_element) {
    if (priority_queue->size == 0) {
        *out_element = NULL;
        return NULL; // Queue is empty
    }
    void* top_element = priority_queue->array[0];
    priority_queue->array[0] = priority_queue->array[priority_queue->size - 1];
    priority_queue->size--;
    heapify_down(priority_queue, 0);
    *out_element = top_element;
    return top_element;
}
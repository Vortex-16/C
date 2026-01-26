#include "dsa_queue.h"
#include <stdio.h>
#include <stdlib.h>

#define RESIZE_FACTOR 2
#define MIN_CAPACITY 10

// Helper function to resize queue
static int queue_resize(Queue *queue, size_t new_capacity) {
    int *new_data = (int *)malloc(new_capacity * sizeof(int));
    if (new_data == NULL) {
        return -1;
    }
    
    // Copy elements to new array
    size_t j = 0;
    for (size_t i = queue->front; j < queue->size; i = (i + 1) % queue->capacity) {
        new_data[j++] = queue->data[i];
    }
    
    free(queue->data);
    queue->data = new_data;
    queue->front = 0;
    queue->rear = queue->size;
    queue->capacity = new_capacity;
    return 0;
}

// Create a new queue
Queue* queue_create(size_t initial_capacity) {
    if (initial_capacity < MIN_CAPACITY) {
        initial_capacity = MIN_CAPACITY;
    }
    
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }
    
    queue->data = (int *)malloc(initial_capacity * sizeof(int));
    if (queue->data == NULL) {
        free(queue);
        return NULL;
    }
    
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = initial_capacity;
    return queue;
}

// Free queue
void queue_free(Queue *queue) {
    if (queue != NULL) {
        free(queue->data);
        free(queue);
    }
}

// Enqueue element
int queue_enqueue(Queue *queue, int value) {
    if (queue == NULL) {
        return -1;
    }
    
    // Resize if needed
    if (queue->size >= queue->capacity) {
        if (queue_resize(queue, queue->capacity * RESIZE_FACTOR) != 0) {
            return -1;
        }
    }
    
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
    return 0;
}

// Dequeue element
int queue_dequeue(Queue *queue, int *value) {
    if (queue == NULL || value == NULL || queue->size == 0) {
        return -1;
    }
    
    *value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    
    // Shrink if needed
    if (queue->size > MIN_CAPACITY && queue->size < queue->capacity / 4) {
        queue_resize(queue, queue->capacity / 2);
    }
    
    return 0;
}

// Peek at front element
int queue_peek(const Queue *queue, int *value) {
    if (queue == NULL || value == NULL || queue->size == 0) {
        return -1;
    }
    
    *value = queue->data[queue->front];
    return 0;
}

// Get size
size_t queue_size(const Queue *queue) {
    return (queue != NULL) ? queue->size : 0;
}

// Check if empty
int queue_is_empty(const Queue *queue) {
    return (queue == NULL || queue->size == 0) ? 1 : 0;
}

// Check if full
int queue_is_full(const Queue *queue) {
    return (queue != NULL && queue->size >= queue->capacity) ? 1 : 0;
}

// Clear queue
void queue_clear(Queue *queue) {
    if (queue != NULL) {
        queue->front = 0;
        queue->rear = 0;
        queue->size = 0;
    }
}

// Print queue
void queue_print(const Queue *queue) {
    if (queue == NULL || queue->size == 0) {
        printf("Queue: []\n");
        return;
    }
    
    printf("Queue (front -> rear): [");
    size_t i = queue->front;
    for (size_t count = 0; count < queue->size; count++) {
        printf("%d", queue->data[i]);
        if (count < queue->size - 1) {
            printf(", ");
        }
        i = (i + 1) % queue->capacity;
    }
    printf("]\n");
}

#ifndef DSA_QUEUE_H
#define DSA_QUEUE_H

#include <stddef.h>

/**
 * @file dsa_queue.h
 * @brief Queue Data Structure (FIFO - First In First Out)
 * @author Vikash Gupta (@Vortex-16)
 * @date January 2026
 * 
 * This header provides a circular queue implementation using dynamic arrays
 * with enqueue, dequeue, and various utility operations.
 */

// Queue structure
typedef struct {
    int *data;
    size_t front;
    size_t rear;
    size_t size;
    size_t capacity;
} Queue;

// Queue Creation and Destruction
/**
 * Create a new queue with initial capacity
 * @param initial_capacity Initial capacity of the queue
 * @return Pointer to newly created Queue, or NULL on failure
 */
Queue* queue_create(size_t initial_capacity);

/**
 * Free memory allocated for the queue
 * @param queue Pointer to the Queue to be freed
 */
void queue_free(Queue *queue);

// Queue Operations
/**
 * Enqueue (add) an element to the rear of the queue
 * @param queue Pointer to the Queue
 * @param value Value to enqueue
 * @return 0 on success, -1 on failure
 */
int queue_enqueue(Queue *queue, int value);

/**
 * Dequeue (remove) an element from the front of the queue
 * @param queue Pointer to the Queue
 * @param value Pointer to store the dequeued value
 * @return 0 on success, -1 if queue is empty
 */
int queue_dequeue(Queue *queue, int *value);

/**
 * Peek at the front element without removing it
 * @param queue Pointer to the Queue
 * @param value Pointer to store the front value
 * @return 0 on success, -1 if queue is empty
 */
int queue_peek(const Queue *queue, int *value);

// Utility Functions
/**
 * Get the current size of the queue
 * @param queue Pointer to the Queue
 * @return Current size of the queue
 */
size_t queue_size(const Queue *queue);

/**
 * Check if queue is empty
 * @param queue Pointer to the Queue
 * @return 1 if empty, 0 otherwise
 */
int queue_is_empty(const Queue *queue);

/**
 * Check if queue is full
 * @param queue Pointer to the Queue
 * @return 1 if full, 0 otherwise
 */
int queue_is_full(const Queue *queue);

/**
 * Clear all elements from the queue
 * @param queue Pointer to the Queue
 */
void queue_clear(Queue *queue);

/**
 * Print all elements in the queue (front to rear)
 * @param queue Pointer to the Queue
 */
void queue_print(const Queue *queue);

#endif // DSA_QUEUE_H

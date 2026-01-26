#include <stdio.h>
#include "../include/dsa_queue.h"

int main() {
    printf("=== Queue Example ===\n\n");
    
    // Create queue
    Queue *queue = queue_create(5);
    if (queue == NULL) {
        printf("Failed to create queue\n");
        return 1;
    }
    
    // Enqueue elements
    printf("1. Enqueuing elements: 10, 20, 30, 40, 50\n");
    queue_enqueue(queue, 10);
    queue_enqueue(queue, 20);
    queue_enqueue(queue, 30);
    queue_enqueue(queue, 40);
    queue_enqueue(queue, 50);
    queue_print(queue);
    
    // Peek at front
    printf("\n2. Peeking at front element\n");
    int value;
    if (queue_peek(queue, &value) == 0) {
        printf("   Front element: %d\n", value);
    }
    
    // Dequeue elements
    printf("\n3. Dequeuing 2 elements\n");
    queue_dequeue(queue, &value);
    printf("   Dequeued: %d\n", value);
    queue_dequeue(queue, &value);
    printf("   Dequeued: %d\n", value);
    queue_print(queue);
    
    // Size and empty check
    printf("\n4. Queue size: %zu\n", queue_size(queue));
    printf("   Is empty: %s\n", queue_is_empty(queue) ? "Yes" : "No");
    
    // Enqueue more elements
    printf("\n5. Enqueuing 60, 70\n");
    queue_enqueue(queue, 60);
    queue_enqueue(queue, 70);
    queue_print(queue);
    
    // Dequeue all
    printf("\n6. Dequeuing all elements\n");
    while (!queue_is_empty(queue)) {
        queue_dequeue(queue, &value);
        printf("   Dequeued: %d\n", value);
    }
    queue_print(queue);
    printf("   Is empty: %s\n", queue_is_empty(queue) ? "Yes" : "No");
    
    // Practical example: Task scheduling
    printf("\n7. Practical Example: Task Scheduling\n");
    printf("   Scheduling tasks...\n");
    queue_enqueue(queue, 101); // Task ID 101
    queue_enqueue(queue, 102);
    queue_enqueue(queue, 103);
    queue_enqueue(queue, 104);
    printf("   Tasks in queue: ");
    queue_print(queue);
    
    printf("\n   Processing tasks (FIFO):\n");
    while (!queue_is_empty(queue)) {
        queue_dequeue(queue, &value);
        printf("   -> Processed Task ID: %d\n", value);
    }
    
    // Free memory
    queue_free(queue);
    printf("\n=== Queue freed successfully ===\n");
    
    return 0;
}

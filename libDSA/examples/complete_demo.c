#include <stdio.h>
#include "../include/libdsa.h"

void demonstrate_array();
void demonstrate_list();
void demonstrate_stack();
void demonstrate_queue();

int main() {
    printf("╔════════════════════════════════════════════════╗\n");
    printf("║          libDSA - Complete Demo                ║\n");
    printf("║   Data Structures & Algorithms Library         ║\n");
    printf("║                                                ║\n");
    printf("║   Author: %s\n", libdsa_author());
    printf("║   Version: %s                                  ║\n", libdsa_version());
    printf("╚════════════════════════════════════════════════╝\n\n");
    
    printf("This demo showcases all data structures in libDSA\n\n");
    
    demonstrate_array();
    printf("\n" "════════════════════════════════════════════════\n\n");
    
    demonstrate_list();
    printf("\n" "════════════════════════════════════════════════\n\n");
    
    demonstrate_stack();
    printf("\n" "════════════════════════════════════════════════\n\n");
    
    demonstrate_queue();
    
    printf("\n" "╔════════════════════════════════════════════════╗\n");
    printf("║         Demo completed successfully!           ║\n");
    printf("╚════════════════════════════════════════════════╝\n");
    
    return 0;
}

void demonstrate_array() {
    printf("📊 DYNAMIC ARRAY\n");
    printf("━━━━━━━━━━━━━━━━\n");
    
    DArray *arr = darray_create(5);
    
    printf("Creating array and adding: 5, 2, 8, 1, 9\n");
    darray_append(arr, 5);
    darray_append(arr, 2);
    darray_append(arr, 8);
    darray_append(arr, 1);
    darray_append(arr, 9);
    darray_print(arr);
    
    printf("\nQuick Sort:\n");
    darray_quick_sort(arr);
    darray_print(arr);
    
    printf("\nSearching for 8: Index %d\n", darray_search(arr, 8));
    
    darray_free(arr);
}

void demonstrate_list() {
    printf("🔗 LINKED LIST\n");
    printf("━━━━━━━━━━━━━━\n");
    
    LinkedList *list = list_create();
    
    printf("Creating list: 10 -> 20 -> 30 -> 40\n");
    list_insert_end(list, 10);
    list_insert_end(list, 20);
    list_insert_end(list, 30);
    list_insert_end(list, 40);
    list_print(list);
    
    printf("\nReversed:\n");
    list_reverse(list);
    list_print(list);
    
    list_free(list);
}

void demonstrate_stack() {
    printf("📚 STACK (LIFO)\n");
    printf("━━━━━━━━━━━━━━━\n");
    
    Stack *stack = stack_create(5);
    
    printf("Pushing: 1, 2, 3, 4, 5\n");
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);
    stack_push(stack, 4);
    stack_push(stack, 5);
    stack_print(stack);
    
    int value;
    printf("\nPopping 2 elements:\n");
    stack_pop(stack, &value);
    printf("Popped: %d\n", value);
    stack_pop(stack, &value);
    printf("Popped: %d\n", value);
    stack_print(stack);
    
    stack_free(stack);
}

void demonstrate_queue() {
    printf("🎫 QUEUE (FIFO)\n");
    printf("━━━━━━━━━━━━━━━\n");
    
    Queue *queue = queue_create(5);
    
    printf("Enqueuing: A=1, B=2, C=3\n");
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 3);
    queue_print(queue);
    
    int value;
    printf("\nDequeuing (FIFO order):\n");
    queue_dequeue(queue, &value);
    printf("Dequeued: %d\n", value);
    queue_print(queue);
    
    queue_free(queue);
}

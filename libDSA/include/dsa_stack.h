#ifndef DSA_STACK_H
#define DSA_STACK_H

#include <stddef.h>

/**
 * @file dsa_stack.h
 * @brief Stack Data Structure (LIFO - Last In First Out)
 * @author Vikash Gupta (@Vortex-16)
 * @date January 2026
 * 
 * This header provides a stack implementation using dynamic arrays
 * with push, pop, peek, and various utility operations.
 */

// Stack structure
typedef struct {
    int *data;
    size_t top;
    size_t capacity;
} Stack;

// Stack Creation and Destruction
/**
 * Create a new stack with initial capacity
 * @param initial_capacity Initial capacity of the stack
 * @return Pointer to newly created Stack, or NULL on failure
 */
Stack* stack_create(size_t initial_capacity);

/**
 * Free memory allocated for the stack
 * @param stack Pointer to the Stack to be freed
 */
void stack_free(Stack *stack);

// Stack Operations
/**
 * Push an element onto the stack
 * @param stack Pointer to the Stack
 * @param value Value to push
 * @return 0 on success, -1 on failure
 */
int stack_push(Stack *stack, int value);

/**
 * Pop an element from the stack
 * @param stack Pointer to the Stack
 * @param value Pointer to store the popped value
 * @return 0 on success, -1 if stack is empty
 */
int stack_pop(Stack *stack, int *value);

/**
 * Peek at the top element without removing it
 * @param stack Pointer to the Stack
 * @param value Pointer to store the top value
 * @return 0 on success, -1 if stack is empty
 */
int stack_peek(const Stack *stack, int *value);

// Utility Functions
/**
 * Get the current size of the stack
 * @param stack Pointer to the Stack
 * @return Current size of the stack
 */
size_t stack_size(const Stack *stack);

/**
 * Check if stack is empty
 * @param stack Pointer to the Stack
 * @return 1 if empty, 0 otherwise
 */
int stack_is_empty(const Stack *stack);

/**
 * Check if stack is full
 * @param stack Pointer to the Stack
 * @return 1 if full, 0 otherwise
 */
int stack_is_full(const Stack *stack);

/**
 * Clear all elements from the stack
 * @param stack Pointer to the Stack
 */
void stack_clear(Stack *stack);

/**
 * Print all elements in the stack (top to bottom)
 * @param stack Pointer to the Stack
 */
void stack_print(const Stack *stack);

#endif // DSA_STACK_H

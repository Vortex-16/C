#include "dsa_stack.h"
#include <stdio.h>
#include <stdlib.h>

#define RESIZE_FACTOR 2
#define MIN_CAPACITY 10

// Helper function to resize stack
static int stack_resize(Stack *stack, size_t new_capacity) {
    int *new_data = (int *)realloc(stack->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
        return -1;
    }
    stack->data = new_data;
    stack->capacity = new_capacity;
    return 0;
}

// Create a new stack
Stack* stack_create(size_t initial_capacity) {
    if (initial_capacity < MIN_CAPACITY) {
        initial_capacity = MIN_CAPACITY;
    }
    
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }
    
    stack->data = (int *)malloc(initial_capacity * sizeof(int));
    if (stack->data == NULL) {
        free(stack);
        return NULL;
    }
    
    stack->top = 0;
    stack->capacity = initial_capacity;
    return stack;
}

// Free stack
void stack_free(Stack *stack) {
    if (stack != NULL) {
        free(stack->data);
        free(stack);
    }
}

// Push element
int stack_push(Stack *stack, int value) {
    if (stack == NULL) {
        return -1;
    }
    
    // Resize if needed
    if (stack->top >= stack->capacity) {
        if (stack_resize(stack, stack->capacity * RESIZE_FACTOR) != 0) {
            return -1;
        }
    }
    
    stack->data[stack->top++] = value;
    return 0;
}

// Pop element
int stack_pop(Stack *stack, int *value) {
    if (stack == NULL || value == NULL || stack->top == 0) {
        return -1;
    }
    
    *value = stack->data[--stack->top];
    
    // Shrink if needed
    if (stack->top > MIN_CAPACITY && stack->top < stack->capacity / 4) {
        stack_resize(stack, stack->capacity / 2);
    }
    
    return 0;
}

// Peek at top element
int stack_peek(const Stack *stack, int *value) {
    if (stack == NULL || value == NULL || stack->top == 0) {
        return -1;
    }
    
    *value = stack->data[stack->top - 1];
    return 0;
}

// Get size
size_t stack_size(const Stack *stack) {
    return (stack != NULL) ? stack->top : 0;
}

// Check if empty
int stack_is_empty(const Stack *stack) {
    return (stack == NULL || stack->top == 0) ? 1 : 0;
}

// Check if full
int stack_is_full(const Stack *stack) {
    return (stack != NULL && stack->top >= stack->capacity) ? 1 : 0;
}

// Clear stack
void stack_clear(Stack *stack) {
    if (stack != NULL) {
        stack->top = 0;
    }
}

// Print stack
void stack_print(const Stack *stack) {
    if (stack == NULL || stack->top == 0) {
        printf("Stack: []\n");
        return;
    }
    
    printf("Stack (top -> bottom): [");
    for (size_t i = stack->top; i > 0; i--) {
        printf("%d", stack->data[i - 1]);
        if (i > 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

#include <stdio.h>
#include "../include/dsa_stack.h"

int main() {
    printf("=== Stack Example ===\n\n");
    
    // Create stack
    Stack *stack = stack_create(5);
    if (stack == NULL) {
        printf("Failed to create stack\n");
        return 1;
    }
    
    // Push elements
    printf("1. Pushing elements: 10, 20, 30, 40, 50\n");
    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);
    stack_push(stack, 40);
    stack_push(stack, 50);
    stack_print(stack);
    
    // Peek at top
    printf("\n2. Peeking at top element\n");
    int value;
    if (stack_peek(stack, &value) == 0) {
        printf("   Top element: %d\n", value);
    }
    
    // Pop elements
    printf("\n3. Popping 2 elements\n");
    stack_pop(stack, &value);
    printf("   Popped: %d\n", value);
    stack_pop(stack, &value);
    printf("   Popped: %d\n", value);
    stack_print(stack);
    
    // Size and empty check
    printf("\n4. Stack size: %zu\n", stack_size(stack));
    printf("   Is empty: %s\n", stack_is_empty(stack) ? "Yes" : "No");
    
    // Push more elements
    printf("\n5. Pushing 60, 70, 80\n");
    stack_push(stack, 60);
    stack_push(stack, 70);
    stack_push(stack, 80);
    stack_print(stack);
    
    // Clear stack
    printf("\n6. Clearing stack\n");
    stack_clear(stack);
    stack_print(stack);
    printf("   Is empty: %s\n", stack_is_empty(stack) ? "Yes" : "No");
    
    // Practical example: Reverse a string using stack
    printf("\n7. Practical Example: Reversing a string\n");
    char str[] = "HELLO";
    printf("   Original: %s\n", str);
    
    for (int i = 0; str[i] != '\0'; i++) {
        stack_push(stack, str[i]);
    }
    
    printf("   Reversed: ");
    int i = 0;
    while (!stack_is_empty(stack)) {
        stack_pop(stack, &value);
        str[i++] = (char)value;
    }
    str[i] = '\0';
    printf("%s\n", str);
    
    // Free memory
    stack_free(stack);
    printf("\n=== Stack freed successfully ===\n");
    
    return 0;
}

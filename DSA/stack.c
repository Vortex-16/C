#include <stdio.h>
#include <stdlib.h>

void push(int stack[], int *top, int value) {
    stack[++(*top)] = value;
}

void pop(int stack[], int *top) {
    if (*top >= 0) {
        (*top)--;
    } else {
        printf("Stack underflow\n");
    }
}

void display(int stack[], int top) {
    if (top >= 0) {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("Stack is empty\n");
    }
}

int main() {
    int stack[100];
    int top = -1;
    while (1) {
        int choice, value;
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, &top, value);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
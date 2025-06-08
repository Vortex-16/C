#include <stdio.h>

int change_to(int *a) {
    *a = *a * 10;
    return *a;
}

void main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int* ptr = &n;

    printf("Value of n is: %d\n", n);
    printf("Address of n is: %p\n", (void*)&n);
    change_to(ptr);
    printf("Value of n after change_to is: %d\n", n);
}
#include <stdio.h>

void main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int* ptr= &n;

    printf("Value of n is: %d\n", n);
    printf("Adress of n is: %p\n", &n);
    printf("Value of ptr is: %d\n", *ptr);
    printf("Adress of n is: %p\n", *&ptr);
}
#include <stdio.h>

void main() {
    int i=2;
    int *ptr1 = &i;
    int **ptr2 = &ptr1;
    printf("The value of i is: %d\n", i);
    printf("The address of i is: %p\n", &i);
    printf("The value of ptr1 is: %p\n", *ptr1);
    printf("The value of ptr2 is: %p\n", **ptr2);
}
#include <stdio.h>

void main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int *ptr = a; // Pointer to the first element of the array

    printf("The value at ptr + 3 is: %d \n", *(ptr+3));
    
}
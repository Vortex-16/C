#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Value of a and b is: %d  %d\n", a,b);

    swap(&a, &b);
    printf("After swapping:\n");
    printf("Value of a and b is: %d  %d\n", a, b);
    return 0;
}
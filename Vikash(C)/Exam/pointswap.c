#include <stdio.h>

int main(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Value of a and b is: %d  %d\n", a,b);

    int *p1, *p2;
    printf("After swapping:\n");
    p1 = &a;
    p2 = &b;
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    printf("Value of a and b is: %d  %d\n", *p1, *p2);
}
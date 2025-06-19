#include <stdio.h>

int main(){

    int a;
    int *p;
    printf("Enter a number: ");
    scanf("%d", &a);
    p=&a;
    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", p);
    return 0;
}
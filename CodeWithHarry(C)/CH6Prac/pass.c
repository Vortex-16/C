#include <stdio.h>

int fun(int* c){
    printf("The address of c is: %p\n", c);
    return *c;
}

void main() {
    int i;
    printf("Enter a number: ");
    scanf("%d", &i);

    printf("Address of i is: %p\n", &i);
    fun(&i);
    printf("Value of i is: %d\n", i);

}
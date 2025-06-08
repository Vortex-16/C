#include <stdio.h>

int change_to(int a){
    a = a * 10;
    return a;
}
void main() {
     int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    change_to(a);
    printf("The value of a is: %d\n", a);
}
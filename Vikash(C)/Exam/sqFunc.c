#include <stdio.h>

void sq(int n){
    printf("Square of %d is: %d\n", n, n * n);
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    sq(n);;
    return 0;
}
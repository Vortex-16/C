#include <stdio.h>

void main() {
    int n,i, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    i=0;
    do{
        sum = sum + i;
        i++;
    }
    while (i <= n);
    printf("Sum of first %d natural numbers is: %d\n", n, sum);
}
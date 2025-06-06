#include <stdio.h>

void main() {
    int n,sum=0,i;
    printf("Enter a number: ");
    scanf("%d", &n);
    i =0;
    while (i<=n) {
        sum = sum + i;
        i++;
    }
    printf("Sum of first %d natural numbers is: %d\n", n, sum);
}
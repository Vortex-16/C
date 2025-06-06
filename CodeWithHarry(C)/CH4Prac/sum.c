#include <stdio.h>

void main() {
    int sum=0,n,i;
    printf("Enter a number: ");
    scanf("%d", &n);
    for ( i = 0; i <= n; i++)
    {   
        sum=sum+i;
        
    }
    printf("Sum of first %d natural numbers is: %d\n", n, sum);
}
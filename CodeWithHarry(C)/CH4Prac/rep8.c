#include <stdio.h>

void main() {
    int product = 1, n, i;
    printf("Enter a number: ");
    scanf("%d", &n);
    i=1;
    while (i <= n)  // Corrected loop condition
    {
         product *= i; // Calculate factorial
         i++;
    }
    printf("Factorial of %d is: %d\n", n, product);
}
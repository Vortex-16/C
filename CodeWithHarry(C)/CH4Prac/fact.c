#include <stdio.h>

void main() {
    int product = 1, n, i;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        product *= i; // Calculate factorial
    }
    printf("Factorial of %d is: %d\n", n, product);
}
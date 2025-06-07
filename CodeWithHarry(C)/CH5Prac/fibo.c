#include <stdio.h>

void main() {
    int n;
    printf("Enter the position: ");
    scanf("%d", &n);

    int a = 0, b = 1, fib;
    if (n == 0) fib = a;
    else if (n == 1) fib = b;
    else {
        for (int i = 2; i <= n; i++) {
            fib = a + b;
            a = b;
            b = fib;
        }
    }

    printf("Fibonacci number at position %d is: %d\n", n, fib);
}

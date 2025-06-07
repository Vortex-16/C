#include <stdio.h>

void main() {
    int n, prime = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 2) {
        prime = 0; // 0 and 1 are not prime numbers
    } else {
        for (int i = 2; i * i <= n; i++) { // Using sqrt(n) optimization
            if (n % i == 0) {
                prime = 0;
                break; // Once we find a divisor, no need to continue
            }
        }
    }
    if (prime) {
        printf("%d is a prime number\n", n);
    } else {
        printf("%d is not a prime number\n", n);
    }
}

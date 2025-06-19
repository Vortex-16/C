#include <stdio.h>

int fact(int n) {
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return -1; 
    }
    if (n == 0 || n == 1) {
        return 1; 
    }
    return n * fact(n - 1); 
}
int main() {
    int number;
    printf("Enter a non-negative integer to calculate its factorial: ");
    scanf("%d", &number);

    int result = fact(number);
    printf("Factorial of %d is %d\n", number, result);
    
    return 0;
}
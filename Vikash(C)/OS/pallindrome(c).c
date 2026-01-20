#include <stdio.h>
#include <string.h>

int is_palindrome(int n){
    int original, reverse = 0;
    original = n;
    while (n > 0) {
         reverse = (reverse * 10) + (n % 10);
         n = n / 10;
    }
    return original == reverse;
}
int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    if (is_palindrome(number))
        printf("%d is a palindrome.\n", number);
    else
        printf("%d is not a palindrome.\n", number);
    return 0;
}
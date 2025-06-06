#include <stdio.h>

void main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Multipication of table in reverse order of %d:\n", n);
    for(int i = 10; i >= 1; i--) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}
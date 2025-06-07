#include <stdio.h>

float avg(int, int, int);
float avg(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

void main() {
    int a,b,c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    avg(a, b, c);
    printf("Average of %d, %d, and %d is: %.2f\n", a, b, c, avg(a, b, c));
}
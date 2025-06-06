#include <stdio.h>

void main() {
    int sum=0;
    for (int i = 0; i <= 10; i++)
    {
        sum= sum + (8*i);
    }
    printf("Sum of first 10 multiples of 8 is: %d\n", sum);
}
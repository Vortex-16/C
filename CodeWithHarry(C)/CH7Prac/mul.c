#include <stdio.h>

void main() {
    int a[10];

    for (int i = 0; i < 10; i++)
    {
        a[i] = 5 * (i+1);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("The value of a[%d] is: %d\n", i+1, a[i]);
    }
    
}
#include <stdio.h>

void main() {
    int a[10];
    int n;
    printf("Enter the number of which you want to make a table: ");
    scanf("%d", &n);
    for (int i = 0; i < 10; i++)
    {
        a[i] = n * (i+1);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("The value of a[%d] is: %d\n", i+1, a[i]);
    }
    
}
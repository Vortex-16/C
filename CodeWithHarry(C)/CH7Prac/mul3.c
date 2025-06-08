#include <stdio.h>

void main() {
    int a[] ={3,7,9};
    int mul[3][10]; // 2D array to store multiplication results
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mul[i][j] = a[i] * (j + 1);
            printf("The value of %d * %d is: %d\n", a[i], j + 1, mul[i][j]);
        }
        
    }

    
}
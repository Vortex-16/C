#include <stdio.h>

void main() {
    int arr[3][2];

    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            printf("Enter element at [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    
    }
    printf("The 2D array is:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
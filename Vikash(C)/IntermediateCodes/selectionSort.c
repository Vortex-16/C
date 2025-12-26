#include <stdio.h>

int main(){
    int arr[7] = {3, 23, 1, 34, 342, 938, 11};
    printf("Original array: ");
    for(int i=0;i<7;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    for(int i=0;i<6;i++){
        for(int j=i+1;j<7;j++){
            if(arr[i] > arr[j]){
                // Swap
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for(int i=0;i<7;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main(){
    int n;
    scanf("%d",&n);
    int *ptr = (int *)malloc(n * sizeof(int)); // Dynamic memory allocation
    
    //int arr[n]; // Not allowed in C
    ptr[0]=3;
    ptr[1]=4;
    printf("%d\n", ptr[0]);
    return 0;
}
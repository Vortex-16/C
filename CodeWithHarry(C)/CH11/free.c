#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main(){
    int n;
    int *ptr;
    scanf("%d",&n);
    ptr= (int*) calloc(n, sizeof(int)); 
    ptr[0]=3;
    printf("%d\n", ptr[0]);
    free(ptr); // Free the allocated memory
    return 0;
}
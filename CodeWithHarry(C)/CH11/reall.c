#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main(){
    int n;
    int *ptr;
    scanf("%d",&n);
    ptr= (int*) malloc(n * sizeof(int)); // Dynamic memory allocation 
    ptr[0]=3;
    printf("%d\n", ptr[0]);
    ptr=(int*) realloc(ptr, 2 * sizeof(int)); // Resize the allocated memory
    return 0;
}
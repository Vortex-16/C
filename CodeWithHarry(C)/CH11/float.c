#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main(){
    float n=5;
    float *ptr = (float *)malloc(n * sizeof(float)); // Dynamic memory allocation
    
    ptr[0]=3;
    ptr[1]=4;
    ptr[2]=5;
    ptr[3]=6;
    ptr[4]=7;
    printf("%f\n", ptr[0]);
    printf("%f\n", ptr[1]);
    printf("%f\n", ptr[2]);
    printf("%f\n", ptr[3]);
    printf("%f\n", ptr[4]);
    return 0;
}
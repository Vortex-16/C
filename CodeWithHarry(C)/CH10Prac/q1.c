#include <stdio.h>

int main(){
    FILE *ptr = fopen("../file.txt", "w");
    int num1, num2, num3;
    fscanf(ptr, "%d %d %d", &num1, &num2, &num3);
    printf("The values are: %d %d %d", num1, num2, num3);
    fclose(ptr);
    return 0;
}
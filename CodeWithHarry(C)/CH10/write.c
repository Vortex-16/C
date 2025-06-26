#include <stdio.h>

void main() {
    FILE *ptr;
    ptr = fopen("CodeWithHarry(C)/CH10/vikash.txt", "w");
    int num = 49;
    fprintf(ptr, "%d", num);
    
    fclose(ptr);
}
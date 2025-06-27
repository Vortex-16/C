#include <stdio.h>

int main(){
    FILE *ptr = fopen("../table.txt", "w");
    int num=4;
    for (int i = 0; i <10; i++)
    {
        
        fprintf(ptr, "%d x %d = %d\n", num, i+1, num*(i+1));
    }
    
return 0;
}
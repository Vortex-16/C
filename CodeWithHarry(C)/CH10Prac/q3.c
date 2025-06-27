#include <stdio.h>

int main() {
    FILE *ptr = fopen("../vikash.txt", "r");FILE *ptr2= fopen("../vikash2.txt", "a");
    char ch;

    while (1)
    {
        if(ch==EOF) {
            break; 
        }
        else {
        fprintf(ptr,"%c", ch);
        fprintf(ptr2,"%c", ch);
        printf("%c", ch);

    }
    }
    
    
    fclose(ptr);

    return 0;
}
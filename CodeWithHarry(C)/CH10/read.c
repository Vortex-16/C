#include <stdio.h>

int main() {
    FILE *ptr = fopen("../vikash.txt", "r");

    char ch;
    while (1)
    {
        ch=fgetc(ptr);
        printf("%c", ch);
        if(ch==EOF) {
            break; // Exit the loop if end of file is reached
        }
    }
    
    fclose(ptr);

    return 0;
}
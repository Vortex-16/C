#include <stdio.h>
#include <string.h>
void main() {
    char c='a';
    int contains =0;
    char str[] = "vikash";
    for (int i = 0; i <strlen(str); i++)
    {
        if(str[i]==c){
            contains =1;
        }
    }
    // printf("Count of '%c' in string: %d\n", c, contains );
    if (contains) {
        printf("Character '%c' is present in the string.\n", c);
    } else {
        printf("Character '%c' is not present in the string.\n", c);
    }
    {
        /* code */
    }
    
    
}
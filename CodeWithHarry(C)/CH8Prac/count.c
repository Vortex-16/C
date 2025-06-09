#include <stdio.h>
#include <string.h>
void main() {
    char c='a';
    int count=0;
    char str[] = "vikash";
    for (int i = 0; i <strlen(str); i++)
    {
        if(str[i]==c){
            count++;
        }
    }
    printf("Count of '%c' in string: %d\n", c, count);
    
}
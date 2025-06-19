#include <stdio.h>

char concat(char *dest, const char *src) {
    char *originalDest = dest; 
    while (*dest != '\0') { 
        dest++;
    }
    while (*src != '\0') { 
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; 
    return *originalDest; 
}

int main(){
    char str1[50], str2[50];
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin); 
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin); 

    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    concat(str1, str2); 

    printf("Concatenated string: %s\n", str1); 
    return 0;
}


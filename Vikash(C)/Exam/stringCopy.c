#include <stdio.h>

char copy(char *dest, const char *src) {
    char *originalDest = dest; 
    while (*src != '\0') { 
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; 
    return originalDest; 
}
int main() {
    char source[] = "Hello, World!";
    char destination[50]; 

    copy(destination, source);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}
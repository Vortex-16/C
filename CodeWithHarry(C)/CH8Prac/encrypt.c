#include <stdio.h>
#include <string.h>

void main() {
    char str[] = "vikash";
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = str[i] + 1; // Simple encryption by shifting characters
    }
    printf("Encrypted string: %s\n", str);
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = str[i] - 1; // Decrypting by shifting back
    }
    printf("Decrypted string: %s\n", str);
}
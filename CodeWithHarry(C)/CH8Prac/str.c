#include <stdio.h>

void main() {
    char str[100];
    printf("Enter a string: ");
    for (int i = 0; i < 10; i++)
    {
            scanf("%c", &str[i]);
            fflush(stdin); // Clear the input buffer
    }
    str[9] = '\0'; // Ensure null termination
    printf("You entered: %s\n", str);
}
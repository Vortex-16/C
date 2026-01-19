#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char input[1024];
    while (1) {
        printf("simple_shell> ");
        fgets(input, 1024, stdin);
        // Parse input and execute command
        // ...
    }
    return 0;
}

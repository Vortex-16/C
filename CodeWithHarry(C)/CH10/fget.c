#include <stdio.h>

int main() {
    FILE *ptr = fopen("../vikash.txt", "r");

    char c= fgetc(ptr);
    printf("%c",c);
    fclose(ptr);

    return 0;
}
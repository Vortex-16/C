#include <stdio.h>

int main() {
    FILE *ptr = fopen("../vikash.txt", "a");

    if (ptr == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int num = 49;
    fprintf(ptr, "%d", num);
    fclose(ptr);

    printf("Number written successfully!\n");
    return 0;
}

#include <stdio.h>
int my_strlen(char str[]){
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
void strcpy(char target[], char source[]) {
    for (int i = 0; i < my_strlen(source); i++) {
        target[i] = source[i];
    }
    target[my_strlen(source)] = '\0';  // Add this line
}

int main() {
    char target[30];
    char source[]="Vikash";

    strcpy(target, source); // Copying string from source to target
    printf("%s %s", source, target); // Printing both strings

    return 0;

}
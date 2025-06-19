#include <stdio.h>

int main(){
    char c[0];
    printf("Enter a character: ");
    scanf("%s", c);
    switch(c[0]) {
        case 'a':
        case 'A':
            printf("Vowel\n");
            break;
        case 'e':
        case 'E':
            printf("Vowel\n");
            break;
        case 'i':
        case 'I':
            printf("Vowel\n");
            break;
        case 'o':
        case 'O':
            printf("Vowel\n");
            break;
        case 'u':
        case 'U':
            printf("Vowel\n");
            break;
        default:
            printf("Consonant\n");
    }
}
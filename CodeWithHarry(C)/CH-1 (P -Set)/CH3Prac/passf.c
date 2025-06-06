#include <stdio.h>

void main() {
    int marks1, marks2, marks3;
    printf("Enter marks 1: ");
    scanf("%d", &marks1);
    printf("Enter marks 2: ");
    scanf("%d", &marks2);
    printf("Enter marks 3: ");
    scanf("%d", &marks3);
    printf("The marks are: %d, %d, %d\n", marks1, marks2, marks3);

    if(marks1 || marks2 || marks3){
        printf("You are failed in at least one subject.\n");
    }
    else if((marks1 + marks2 + marks3)/3 < 40) {
        printf("You are failed.\n");
    } else {
        printf("You are passed in all subjects.\n");

    }
}
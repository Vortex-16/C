#include <stdio.h>
 void main() 
 {
    int mark;
    printf("Enter the mark of student: ");
    scanf("%d", &mark);
    if (mark >= 90 && mark <= 100) {
        printf("Grade: A\n");
    } else if (mark >= 80) {
        printf("Grade: B\n");
    } else if (mark >= 70) {
        printf("Grade: C\n");
    } else if (mark >= 60) {
        printf("Grade: D\n");
    } else if (mark >= 50) {
        printf("Grade: E\n");
    } else {
        printf("Grade: F\n");
    }
 }
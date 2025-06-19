#include <stdio.h>

int main(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Enter 1: for addition\n");
    printf("Enter 2: for subtraction\n");
    printf("Enter 3: for multiplication\n");
    printf("Enter 4: for division\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Sum of %d and %d is: %d\n", a, b, a + b);
            break;
        case 2:
            printf("Difference of %d and %d is: %d\n", a, b, a - b);
            break;
        case 3:
            printf("Product of %d and %d is: %d\n", a, b, a * b);
            break;
        case 4:
            if(b != 0) {
                printf("Division of %d by %d is: %.2f\n", a, b, (float)a / b);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
}
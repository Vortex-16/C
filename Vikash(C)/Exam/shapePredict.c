//Write a program to detremine the shape by the number of sides.

#include <stdio.h>

int main(){
    int sides;
    printf("Enter the number of sides of the shape: ");
    scanf("%d", &sides);

    switch(sides) {
        case 2:
            printf("The shape is a Linear.\n");
            break;
        case 3:
            printf("The shape is a Triangle.\n");
            break;
        case 4:
            printf("The shape is a Quadrilateral.\n");
            break;
        case 5:
            printf("The shape is a Pentagon.\n");
            break;
        case 6:
            printf("The shape is a Hexagon.\n");
            break;
        default:
            printf("Shape with %d sides is not recognized.\n", sides);
    }

    return 0;
}
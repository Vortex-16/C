#include <stdio.h>

int sum(int*, int*);
float avg(int*, int*);
int sum(int *a, int *b){
    int s = *a + *b;
    // printf("The sum of %d and %d is: %d\n", *a, *b, s);
    return s;
}
float avg(int *a, int *b){
    float av = (float)(*a + *b) / 2.0;
    // printf("The average of %d and %d is: %.2f\n", *a, *b, av);
    return av;
}

void main() {
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    sum(&a,&b);
    printf("The average of %d and %d is: %d\n", a, b, sum(&a, &b));
    avg(&a,&b);
    printf("The sum of %d and %d is: %.2f\n", a, b, avg(&a, &b));
}
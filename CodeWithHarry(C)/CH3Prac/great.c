#include <stdio.h>

void main() {
    int a,b,c,d;
    printf("Enter four numbers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(a > b && a > c && a > d) {
        printf("The largest number is: %d\n", a);
    } else if(b > a && b > c && b > d) {
        printf("The largest number is: %d\n", b);
    } else if(c > a && c > b && c > d) {
        printf("The largest number is: %d\n", c);
    } else {
        printf("The largest number is: %d\n", d);
    }
}
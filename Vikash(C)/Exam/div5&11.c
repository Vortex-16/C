#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if(n%5==0){
        if(n%11==0){
            printf("Divisible by both 5 and 11\n");
        } else {
            printf("Divisible by 5 but not by 11\n");
        }
    }
    else if(n%11==0){
        if(n%5==0){
            printf("Divisible by both 11 and 5\n");
        } else {
            printf("Divisible by 11 but not by 5\n");
        }
    }
    else {
        printf("Not divisible by either 5 or 11\n");
    }
    return 0;
}
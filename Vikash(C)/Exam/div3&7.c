#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if(n%3==0){
        if(n%7==0){
            printf("Divisible by both 3 and 7\n");
        } else {
            printf("Divisible by 3 but not by 7\n");
        }
    }
    else if(n%7==0){
        if(n%3==0){
            printf("Divisible by both 7 and 3\n");
        } else {
            printf("Divisible by 7 but not by 3\n");
        }
    }
    else {
        printf("Not divisible by either 3 or 7\n");
    }
    return 0;
}
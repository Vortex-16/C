#include <stdio.h>

int main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("The number %d is divided by n%97", n, n % 97);
    return 0; //If return 0 then its divisble by 97, else not(I am  not using if statement as its basic practice)
}
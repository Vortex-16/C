#include <stdio.h>
void main()
{
    int a,b;
    printf("Enter the first coordinates a:");
    scanf("%d", &a);
    printf("Enter the first coordinates b:");
    scanf("%d", &b);
    int diff;
    if(a>b)
    {
        diff=a-b;
        printf("%d",diff);
    }
    else
    diff=b-a;
    printf("%d",diff);
}
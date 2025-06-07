#include <stdio.h>

int sum(int a)
{
    if(a<=1)
        return a;
    return a+ sum(a-1);
}
void main() {
    int n;
    printf("Enter range of n: ");
    scanf("%d", &n);
    printf("Sum of first %d natural numbers is: %d\n", n, sum(n));
}
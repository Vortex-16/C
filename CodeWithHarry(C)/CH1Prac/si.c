#include <stdio.h>

void main()
{
 int princ,time;
 float rate,interest;
 printf("Enter the principal amt. and time(yrs) respectively: ");
 scanf("%d %d", &princ,&time);
 printf("Enter the rate of interest: ");
 scanf("%f", &rate);
interest = (princ * rate * time) / 100;
printf("The simple interest is: %.3f\n", interest);
}

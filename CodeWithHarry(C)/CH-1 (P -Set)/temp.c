#include <stdio.h>

void main()
{
 float celc,fahr;
 printf("Ënter the celsius: ");
 scanf("%f", &celc);
 fahr= (9.0/5.0) * celc +32;
 printf("Celcius in Fahrenheit is: %.2f\n", fahr);
}
#include <stdio.h>

void main()
{
 int radius,height;
 float volume;
 printf("Ënter the radius and height of the cylinder: ");
 scanf("%d %d", &radius,&height);
 volume = 3.14 * radius * radius * height;
 printf("volume of the cylinder is: %.2f\n", volume);
}
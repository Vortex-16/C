#include <stdio.h>

void main()
{
 int radius;
 float area;
 printf("Ënter the radius of the circle: ");
 scanf("%d", &radius);
 area = 3.14 * radius * radius;
 printf("Area of the circle is: %.2f\n", area);
}
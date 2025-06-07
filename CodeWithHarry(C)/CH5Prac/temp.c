#include <stdio.h>
float c2f(float c); // Function prototype for conversion
float c2f(float c) {
    return (c * 9 / 5) + 32; // Convert Celsius to Fahrenheit
}
void main() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = c2f(celsius); // Call the conversion function
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
}
#include <stdio.h>

float calculate_force(float mass) {
    const float gravity = 9.81; // Acceleration due to gravity in m/s^2
    return mass * gravity; // F = m * g
}
void main() {
    float mass,force;
    printf("Enter mass (in kg): ");
    scanf("%f", &mass);
    force = calculate_force(mass); // Call the function to calculate force
    printf("Force (in Newtons): %.2f N\n", force);
}
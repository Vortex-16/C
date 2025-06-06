#include <stdio.h>

void main() {
    int income;
    float tax=0;
    printf("Enter your income: ");
    scanf("%d", &income);
    if(income < 250000) {
        printf("You are not required to pay tax.\n");
    } else if(income >= 250000 && income < 500000) {
        printf("You are required to pay 5% % tax.\n");
        tax= 0.05 * (income - 250000);
    } else if(income >= 500000 && income < 1000000) {
        printf("You are required to pay 10% % tax.\n");
        tax = 0.05 * (50000 - 25000) +  0.2*(income - 500000);
    } else if(income >= 1000000) {
        printf("You are required to pay 30% % tax.\n");
        tax = 0.05 * (50000 - 25000) +  0.2*(1000000 - 500000) + 0.3 * (income - 1000000);
    } 
    printf("You need to pay: %.2f\n", tax);
}
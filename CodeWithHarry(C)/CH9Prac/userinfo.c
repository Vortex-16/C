#include <stdio.h>
#include <string.h>
struct members{
    char name[50];
    int age;
    float salary;
};

int main(){
    struct members m1, m2, m3;

    // Input for member 1 
    printf("Enter name of member 1: ");
    fgets(m1.name, sizeof(m1.name), stdin);
    m1.name[strcspn(m1.name, "\n")] = '\0'; // Remove newline character
    printf("Enter age of member 1: ");
    scanf("%d", &m1.age);
    printf("Enter salary of member 1: ");
    scanf("%f", &m1.salary);
    getchar(); // Clear the newline character from the input buffer

    // Input for member 2
    printf("Enter name of member 2: ");
    fgets(m2.name, sizeof(m2.name), stdin);
    m2.name[strcspn(m2.name, "\n")] = '\0';
    printf("Enter age of member 2: ");
    scanf("%d", &m2.age);
    printf("Enter salary of member 2: ");
    scanf("%f", &m2.salary);
    getchar();

    // Input for member 3
    printf("Enter name of member 3: ");
    fgets(m3.name, sizeof(m3.name), stdin);
    m3.name[strcspn(m3.name, "\n")] = '\0';
    printf("Enter age of member 3: ");
    scanf("%d", &m3.age);
    printf("Enter salary of member 3: ");
    scanf("%f", &m3.salary);

    // Displaying the information
    printf("\nMember 1:\nName: %s\nAge: %d\nSalary: %.2f\n", m1.name, m1.age, m1.salary);
    printf("\nMember 2:\nName: %s\nAge: %d\nSalary: %.2f\n", m2.name, m2.age, m2.salary);
    printf("\nMember 3:\nName: %s\nAge: %d\nSalary: %.2f\n", m3.name, m3.age, m3.salary);
    return 0;
}
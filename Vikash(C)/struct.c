#include <stdio.h>

struct Student{
int roll;
char name[20];
char address[50];
};


int main(){
    struct Student s1;
printf("Enter roll number: ");
scanf("%d", &s1.roll);
printf("Enter name: ");
scanf("%s", s1.name);
printf("Enter address: ");
scanf("%s", s1.address);

// Displaying the details
printf("\nStudent Details:\n");
printf("Roll Number: %d\n", s1.roll);
printf("Name: %s\n", s1.name);
printf("Address: %s\n", s1.address);
return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    char dept[50];
    float cgpa;
};

// Function to read existing students from file
int readExistingData(struct Student **students) {
    FILE *fp = fopen("datafile.txt", "r");
    int count = 0;
    char line[200];
    
    if (fp == NULL) {
        return 0; // No existing file
    }
    
    // Allocate initial memory
    *students = (struct Student *)malloc(100 * sizeof(struct Student));
    
    // Skip header lines
    fgets(line, sizeof(line), fp);
    fgets(line, sizeof(line), fp);
    
    // Read student data
    while (fscanf(fp, "%d | %[^|] | %[^|] | %f\n", 
                  &(*students)[count].roll,
                  (*students)[count].name,
                  (*students)[count].dept,
                  &(*students)[count].cgpa) == 4) {
        // Trim spaces from name and dept
        int len = strlen((*students)[count].name);
        while (len > 0 && (*students)[count].name[len-1] == ' ') {
            (*students)[count].name[--len] = '\0';
        }
        len = strlen((*students)[count].dept);
        while (len > 0 && (*students)[count].dept[len-1] == ' ') {
            (*students)[count].dept[--len] = '\0';
        }
        count++;
    }
    
    fclose(fp);
    return count;
}

// Function to find student by roll number
int findStudent(struct Student *students, int count, int roll) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, i, j, total;
    struct Student temp;
    struct Student *allStudents = NULL;
    
    // Read existing data
    int existingCount = readExistingData(&allStudents);
    
    if (existingCount > 0) {
        printf("Found %d existing student(s) in file.\n\n", existingCount);
    }
    
    printf("Enter number of students to add: ");
    scanf("%d", &n);
    
    // Reallocate memory for new + existing students
    allStudents = (struct Student *)realloc(allStudents, (existingCount + n) * sizeof(struct Student));
    total = existingCount;

    // Input new students
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        
        int roll;
        printf("Roll: ");
        scanf("%d", &roll);
        
        // Check if student already exists
        int index = findStudent(allStudents, total, roll);
        
        if (index != -1) {
            printf("\nStudent with Roll %d already exists!\n", roll);
            printf("Current Details:\n");
            printf("Name: %s\n", allStudents[index].name);
            printf("Department: %s\n", allStudents[index].dept);
            printf("CGPA: %.2f\n", allStudents[index].cgpa);
            
            printf("\nDo you want to:\n");
            printf("1. Modify marks (CGPA) only\n");
            printf("2. Modify entire record\n");
            printf("3. Skip this entry\n");
            printf("Enter choice: ");
            int choice;
            scanf("%d", &choice);
            
            if (choice == 1) {
                printf("Enter new CGPA: ");
                scanf("%f", &allStudents[index].cgpa);
                printf("CGPA updated!\n");
            } else if (choice == 2) {
                allStudents[index].roll = roll;
                printf("Name: ");
                scanf(" %[^\n]", allStudents[index].name);
                printf("Department: ");
                scanf(" %[^\n]", allStudents[index].dept);
                printf("CGPA: ");
                scanf("%f", &allStudents[index].cgpa);
                printf("Record updated!\n");
            } else {
                printf("Skipped.\n");
            }
        } else {
            // Add new student
            allStudents[total].roll = roll;
            
            printf("Name: ");
            scanf(" %[^\n]", allStudents[total].name);
            
            printf("Department: ");
            scanf(" %[^\n]", allStudents[total].dept);
            
            printf("CGPA: ");
            scanf("%f", &allStudents[total].cgpa);
            
            total++;
        }
    }

    // Sort by Roll (Ascending)
    for (i = 0; i < total - 1; i++) {
        for (j = i + 1; j < total; j++) {
            if (allStudents[i].roll > allStudents[j].roll) {
                temp = allStudents[i];
                allStudents[i] = allStudents[j];
                allStudents[j] = temp;
            }
        }
    }

    // Open file in write mode (to rewrite sorted data)
    FILE *fp = fopen("datafile.txt", "w");

    if (fp == NULL) {
        printf("File Error!\n");
        free(allStudents);
        return 1;
    }

    // Header
    fprintf(fp, "Roll | Name                | Department          | CGPA\n");
    fprintf(fp, "------------------------------------------------------------\n");

    // Write All Data (Vertical + Pipe Format)
    for (i = 0; i < total; i++) {
        fprintf(fp, "%-4d | %-19s | %-18s | %.2f\n",
                allStudents[i].roll,
                allStudents[i].name,
                allStudents[i].dept,
                allStudents[i].cgpa);
    }

    fclose(fp);
    free(allStudents);

    printf("\nTotal %d student(s) saved in datafile.txt (Pipe Format)\n", total);

    return 0;
}

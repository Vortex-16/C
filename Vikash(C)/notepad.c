#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256

// Function prototypes
void displayMenu();
void createNewFile(char lines[][MAX_LINE_LENGTH], int *lineCount);
void openFile(char lines[][MAX_LINE_LENGTH], int *lineCount);
void saveFile(char lines[][MAX_LINE_LENGTH], int lineCount);
void displayContent(char lines[][MAX_LINE_LENGTH], int lineCount);
void editContent(char lines[][MAX_LINE_LENGTH], int *lineCount);
void appendLine(char lines[][MAX_LINE_LENGTH], int *lineCount);
void deleteLine(char lines[][MAX_LINE_LENGTH], int *lineCount);
void clearBuffer();

int main() {
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int lineCount = 0;
    int choice;
    
    printf("\n========================================\n");
    printf("    SIMPLE NOTEPAD APPLICATION IN C\n");
    printf("========================================\n");
    
    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();
        
        switch(choice) {
            case 1:
                createNewFile(lines, &lineCount);
                break;
            case 2:
                openFile(lines, &lineCount);
                break;
            case 3:
                saveFile(lines, lineCount);
                break;
            case 4:
                displayContent(lines, lineCount);
                break;
            case 5:
                editContent(lines, &lineCount);
                break;
            case 6:
                appendLine(lines, &lineCount);
                break;
            case 7:
                deleteLine(lines, &lineCount);
                break;
            case 8:
                printf("\nThank you for using Notepad!\n");
                printf("Goodbye!\n\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n========================================\n");
    printf("              MENU\n");
    printf("========================================\n");
    printf("1. Create New File\n");
    printf("2. Open File\n");
    printf("3. Save File\n");
    printf("4. Display Content\n");
    printf("5. Edit Line\n");
    printf("6. Append Line\n");
    printf("7. Delete Line\n");
    printf("8. Exit\n");
    printf("========================================\n");
}

void createNewFile(char lines[][MAX_LINE_LENGTH], int *lineCount) {
    *lineCount = 0;
    printf("\n--- New File Created ---\n");
    printf("Start typing your content (type 'END' on a new line to finish):\n\n");
    
    while(*lineCount < MAX_LINES) {
        printf("Line %d: ", *lineCount + 1);
        fgets(lines[*lineCount], MAX_LINE_LENGTH, stdin);
        
        // Remove newline character
        lines[*lineCount][strcspn(lines[*lineCount], "\n")] = '\0';
        
        // Check if user wants to end input
        if(strcmp(lines[*lineCount], "END") == 0) {
            break;
        }
        
        (*lineCount)++;
    }
    
    printf("\nFile created with %d lines.\n", *lineCount);
}

void openFile(char lines[][MAX_LINE_LENGTH], int *lineCount) {
    char filename[100];
    FILE *file;
    
    printf("\nEnter filename to open: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';
    
    file = fopen(filename, "r");
    
    if(file == NULL) {
        printf("\nError: File not found or cannot be opened!\n");
        return;
    }
    
    *lineCount = 0;
    while(fgets(lines[*lineCount], MAX_LINE_LENGTH, file) != NULL && *lineCount < MAX_LINES) {
        lines[*lineCount][strcspn(lines[*lineCount], "\n")] = '\0';
        (*lineCount)++;
    }
    
    fclose(file);
    printf("\nFile opened successfully! Total lines: %d\n", *lineCount);
}

void saveFile(char lines[][MAX_LINE_LENGTH], int lineCount) {
    char filename[100];
    FILE *file;
    
    if(lineCount == 0) {
        printf("\nNo content to save!\n");
        return;
    }
    
    printf("\nEnter filename to save: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';
    
    file = fopen(filename, "w");
    
    if(file == NULL) {
        printf("\nError: Cannot create file!\n");
        return;
    }
    
    for(int i = 0; i < lineCount; i++) {
        fprintf(file, "%s\n", lines[i]);
    }
    
    fclose(file);
    printf("\nFile saved successfully as '%s'!\n", filename);
}

void displayContent(char lines[][MAX_LINE_LENGTH], int lineCount) {
    if(lineCount == 0) {
        printf("\nNo content to display!\n");
        return;
    }
    
    printf("\n========================================\n");
    printf("         CURRENT CONTENT\n");
    printf("========================================\n");
    
    for(int i = 0; i < lineCount; i++) {
        printf("%3d: %s\n", i + 1, lines[i]);
    }
    
    printf("========================================\n");
    printf("Total lines: %d\n", lineCount);
}

void editContent(char lines[][MAX_LINE_LENGTH], int *lineCount) {
    int lineNum;
    
    if(*lineCount == 0) {
        printf("\nNo content to edit!\n");
        return;
    }
    
    displayContent(lines, *lineCount);
    
    printf("\nEnter line number to edit (1-%d): ", *lineCount);
    scanf("%d", &lineNum);
    clearBuffer();
    
    if(lineNum < 1 || lineNum > *lineCount) {
        printf("\nInvalid line number!\n");
        return;
    }
    
    printf("Current content: %s\n", lines[lineNum - 1]);
    printf("Enter new content: ");
    fgets(lines[lineNum - 1], MAX_LINE_LENGTH, stdin);
    lines[lineNum - 1][strcspn(lines[lineNum - 1], "\n")] = '\0';
    
    printf("\nLine %d updated successfully!\n", lineNum);
}

void appendLine(char lines[][MAX_LINE_LENGTH], int *lineCount) {
    if(*lineCount >= MAX_LINES) {
        printf("\nMaximum line limit reached!\n");
        return;
    }
    
    printf("\nEnter new line to append: ");
    fgets(lines[*lineCount], MAX_LINE_LENGTH, stdin);
    lines[*lineCount][strcspn(lines[*lineCount], "\n")] = '\0';
    
    (*lineCount)++;
    printf("\nLine appended successfully! Total lines: %d\n", *lineCount);
}

void deleteLine(char lines[][MAX_LINE_LENGTH], int *lineCount) {
    int lineNum;
    
    if(*lineCount == 0) {
        printf("\nNo content to delete!\n");
        return;
    }
    
    displayContent(lines, *lineCount);
    
    printf("\nEnter line number to delete (1-%d): ", *lineCount);
    scanf("%d", &lineNum);
    clearBuffer();
    
    if(lineNum < 1 || lineNum > *lineCount) {
        printf("\nInvalid line number!\n");
        return;
    }
    
    // Shift all lines up
    for(int i = lineNum - 1; i < *lineCount - 1; i++) {
        strcpy(lines[i], lines[i + 1]);
    }
    
    (*lineCount)--;
    printf("\nLine %d deleted successfully! Total lines: %d\n", lineNum, *lineCount);
}

void clearBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

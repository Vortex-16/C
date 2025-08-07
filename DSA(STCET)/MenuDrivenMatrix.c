#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter elements (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int a[rows][cols], int b[rows][cols]) {
    int result[rows][cols];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];

    printf("Result of Addition:\n");
    displayMatrix(rows, cols, result);
}

void multiplyMatrices(int r1, int c1, int a[r1][c1], int r2, int c2, int b[r2][c2]) {
    if (c1 != r2) {
        printf("Matrix multiplication not possible. Columns of A must equal rows of B.\n");
        return;
    }

    int result[r1][c2];
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
        }

    printf("Result of Multiplication:\n");
    displayMatrix(r1, c2, result);
}

void traceMatrix(int size, int matrix[size][size]) {
    int trace = 0;
    for (int i = 0; i < size; i++)
        trace += matrix[i][i];

    printf("Trace of the matrix = %d\n", trace);
}

int main() {
    int r1, c1, r2, c2;

    // Get matrix sizes
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d%d", &r2, &c2);

    // Declare matrices using VLAs
    int a[r1][c1], b[r2][c2];

    // Input matrices
    printf("Enter elements for Matrix A:\n");
    inputMatrix(r1, c1, a);
    printf("Enter elements for Matrix B:\n");
    inputMatrix(r2, c2, b);

    // Menu loop
    int choice;
    while (1) {
        printf("\n===== Matrix Operations Menu =====\n");
        printf("1. Add Matrices (only if sizes match)\n");
        printf("2. Multiply Matrices (A x B)\n");
        printf("3. Trace of a Matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (r1 != r2 || c1 != c2) {
                printf("Cannot add matrices of different sizes.\n");
            } else {
                addMatrices(r1, c1, a, b);
            }
            break;

        case 2:
            multiplyMatrices(r1, c1, a, r2, c2, b);
            break;

        case 3:
            printf("Trace of which matrix? (1 for A, 2 for B): ");
            int opt;
            scanf("%d", &opt);
            if (opt == 1 && r1 == c1) {
                traceMatrix(r1, a);
            } else if (opt == 2 && r2 == c2) {
                traceMatrix(r2, b);
            } else {
                printf("Trace is only defined for square matrices.\n");
            }
            break;

        case 4:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

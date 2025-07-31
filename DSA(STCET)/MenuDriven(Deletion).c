#include <stdio.h>

void deleteFirst(int n, int a[]) {
    for (int i = 0; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
    printf("The updated array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void deleteLast(int n, int a[]) {
    n--;
    printf("The updated array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void deleteAtPosition(int n, int a[], int pos) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
    printf("The updated array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    int arr[10], n, pos, choice;

    printf("Enter the range: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n----------------------------\n");
    printf("Choose Deletion Operation:\n");
    printf("1: Delete from first index\n");
    printf("2: Delete from last index\n");
    printf("3: Delete from any index\n");
    printf("----------------------------\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            deleteFirst(n, arr);
            break;

        case 2:
            deleteLast(n, arr);
            break;

        case 3:
            printf("Enter the index (starting from 0) to delete from: ");
            scanf("%d", &pos);
            deleteAtPosition(n, arr, pos);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

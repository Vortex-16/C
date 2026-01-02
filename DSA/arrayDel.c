#include <stdio.h>
void delete(int arr[], int *n, int p) {
    for (int i = p; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int size, p;
    printf("Enter Array Size: ");
    scanf("%d", &size);
    int arr[size]; 
    printf("Enter Array Elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter Position to be deleted: ");
    scanf("%d", &p);
    if (p >= 0 && p < size) {
        delete(arr, &size, p);
        printf("Array after deletion: ");
        display(arr, size);
    } else {
        printf("Deletion failed: Invalid position.\n");
    }
    return 0;
}
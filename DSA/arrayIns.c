#include <stdio.h>

void insert(int arr[], int *n, int p, int value) {
	for (int i = *n; i > p; i--) {
		arr[i] = arr[i - 1];
	}
	arr[p] = value;
	(*n)++;
}
void display(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int size, p, value;
	printf("Enter Array Size: ");
	scanf("%d", &size);
	int arr[size + 1]; 
	printf("Enter Array Elements: ");
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Enter Position and Value to be inserted: ");
	scanf("%d %d", &p, &value);
	if (p >= 0 && p <= size) {
		insert(arr, &size, p, value);
		printf("Array after insertion: ");
		display(arr, size);
	} else {
		printf("Insertion failed: Invalid position.\n");
	}
	return 0;
}
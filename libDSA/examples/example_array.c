#include <stdio.h>
#include "../include/dsa_array.h"

int main() {
    printf("=== Dynamic Array Example ===\n\n");
    
    // Create array
    DArray *arr = darray_create(5);
    if (arr == NULL) {
        printf("Failed to create array\n");
        return 1;
    }
    
    // Append elements
    printf("1. Appending elements: 10, 20, 30, 40, 50\n");
    darray_append(arr, 10);
    darray_append(arr, 20);
    darray_append(arr, 30);
    darray_append(arr, 40);
    darray_append(arr, 50);
    printf("   Array: ");
    darray_print(arr);
    
    // Insert element
    printf("\n2. Inserting 25 at position 2\n");
    darray_insert(arr, 2, 25);
    printf("   Array: ");
    darray_print(arr);
    
    // Search
    printf("\n3. Searching for 30\n");
    int pos = darray_search(arr, 30);
    printf("   Found at index: %d\n", pos);
    
    // Delete element
    printf("\n4. Deleting element at position 1\n");
    int deleted = darray_delete(arr, 1);
    printf("   Deleted value: %d\n", deleted);
    printf("   Array: ");
    darray_print(arr);
    
    // Get element
    printf("\n5. Getting element at position 2\n");
    int value;
    if (darray_get(arr, 2, &value) == 0) {
        printf("   Value: %d\n", value);
    }
    
    // Set element
    printf("\n6. Setting position 2 to 99\n");
    darray_set(arr, 2, 99);
    printf("   Array: ");
    darray_print(arr);
    
    // Reverse
    printf("\n7. Reversing array\n");
    darray_reverse(arr);
    printf("   Array: ");
    darray_print(arr);
    
    // Clear and add new elements
    printf("\n8. Testing sorting algorithms\n");
    darray_clear(arr);
    darray_append(arr, 64);
    darray_append(arr, 34);
    darray_append(arr, 25);
    darray_append(arr, 12);
    darray_append(arr, 22);
    darray_append(arr, 11);
    darray_append(arr, 90);
    printf("   Unsorted: ");
    darray_print(arr);
    
    // Bubble sort
    printf("\n   Bubble Sort: ");
    darray_bubble_sort(arr);
    darray_print(arr);
    
    // Test quick sort
    darray_clear(arr);
    darray_append(arr, 64);
    darray_append(arr, 34);
    darray_append(arr, 25);
    darray_append(arr, 12);
    darray_append(arr, 22);
    darray_append(arr, 11);
    darray_append(arr, 90);
    printf("   Quick Sort: ");
    darray_quick_sort(arr);
    darray_print(arr);
    
    // Test merge sort
    darray_clear(arr);
    darray_append(arr, 64);
    darray_append(arr, 34);
    darray_append(arr, 25);
    darray_append(arr, 12);
    darray_append(arr, 22);
    darray_append(arr, 11);
    darray_append(arr, 90);
    printf("   Merge Sort: ");
    darray_merge_sort(arr);
    darray_print(arr);
    
    // Size and empty check
    printf("\n9. Array size: %zu\n", darray_size(arr));
    printf("   Is empty: %s\n", darray_is_empty(arr) ? "Yes" : "No");
    
    // Free memory
    darray_free(arr);
    printf("\n=== Array freed successfully ===\n");
    
    return 0;
}

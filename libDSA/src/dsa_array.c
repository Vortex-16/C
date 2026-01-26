#include "dsa_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESIZE_FACTOR 2
#define MIN_CAPACITY 10

// Helper function to resize array
static int darray_resize(DArray *arr, size_t new_capacity) {
    int *new_data = (int *)realloc(arr->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
        return -1;
    }
    arr->data = new_data;
    arr->capacity = new_capacity;
    return 0;
}

// Create a new dynamic array
DArray* darray_create(size_t initial_capacity) {
    if (initial_capacity < MIN_CAPACITY) {
        initial_capacity = MIN_CAPACITY;
    }
    
    DArray *arr = (DArray *)malloc(sizeof(DArray));
    if (arr == NULL) {
        return NULL;
    }
    
    arr->data = (int *)malloc(initial_capacity * sizeof(int));
    if (arr->data == NULL) {
        free(arr);
        return NULL;
    }
    
    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

// Free memory
void darray_free(DArray *arr) {
    if (arr != NULL) {
        free(arr->data);
        free(arr);
    }
}

// Insert at position
int darray_insert(DArray *arr, size_t pos, int value) {
    if (arr == NULL || pos > arr->size) {
        return -1;
    }
    
    // Resize if needed
    if (arr->size >= arr->capacity) {
        if (darray_resize(arr, arr->capacity * RESIZE_FACTOR) != 0) {
            return -1;
        }
    }
    
    // Shift elements to the right
    for (size_t i = arr->size; i > pos; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    
    arr->data[pos] = value;
    arr->size++;
    return 0;
}

// Append to end
int darray_append(DArray *arr, int value) {
    return darray_insert(arr, arr->size, value);
}

// Delete at position
int darray_delete(DArray *arr, size_t pos) {
    if (arr == NULL || pos >= arr->size) {
        return -1;
    }
    
    int deleted_value = arr->data[pos];
    
    // Shift elements to the left
    for (size_t i = pos; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    
    arr->size--;
    
    // Shrink if size is much smaller than capacity
    if (arr->size > MIN_CAPACITY && arr->size < arr->capacity / 4) {
        darray_resize(arr, arr->capacity / 2);
    }
    
    return deleted_value;
}

// Get element at position
int darray_get(const DArray *arr, size_t pos, int *value) {
    if (arr == NULL || pos >= arr->size || value == NULL) {
        return -1;
    }
    *value = arr->data[pos];
    return 0;
}

// Set element at position
int darray_set(DArray *arr, size_t pos, int value) {
    if (arr == NULL || pos >= arr->size) {
        return -1;
    }
    arr->data[pos] = value;
    return 0;
}

// Linear search
int darray_search(const DArray *arr, int value) {
    if (arr == NULL) {
        return -1;
    }
    
    for (size_t i = 0; i < arr->size; i++) {
        if (arr->data[i] == value) {
            return (int)i;
        }
    }
    return -1;
}

// Get size
size_t darray_size(const DArray *arr) {
    return (arr != NULL) ? arr->size : 0;
}

// Check if empty
int darray_is_empty(const DArray *arr) {
    return (arr == NULL || arr->size == 0) ? 1 : 0;
}

// Clear array
void darray_clear(DArray *arr) {
    if (arr != NULL) {
        arr->size = 0;
    }
}

// Print array
void darray_print(const DArray *arr) {
    if (arr == NULL || arr->size == 0) {
        printf("[]\n");
        return;
    }
    
    printf("[");
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Reverse array
void darray_reverse(DArray *arr) {
    if (arr == NULL || arr->size <= 1) {
        return;
    }
    
    size_t left = 0;
    size_t right = arr->size - 1;
    
    while (left < right) {
        int temp = arr->data[left];
        arr->data[left] = arr->data[right];
        arr->data[right] = temp;
        left++;
        right--;
    }
}

// Bubble sort
void darray_bubble_sort(DArray *arr) {
    if (arr == NULL || arr->size <= 1) {
        return;
    }
    
    for (size_t i = 0; i < arr->size - 1; i++) {
        for (size_t j = 0; j < arr->size - 1 - i; j++) {
            if (arr->data[j] > arr->data[j + 1]) {
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

// Helper function for quick sort partition
static int partition(int *data, int low, int high) {
    int pivot = data[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (data[j] < pivot) {
            i++;
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    
    int temp = data[i + 1];
    data[i + 1] = data[high];
    data[high] = temp;
    
    return i + 1;
}

// Helper function for quick sort
static void quick_sort_helper(int *data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quick_sort_helper(data, low, pi - 1);
        quick_sort_helper(data, pi + 1, high);
    }
}

// Quick sort
void darray_quick_sort(DArray *arr) {
    if (arr == NULL || arr->size <= 1) {
        return;
    }
    quick_sort_helper(arr->data, 0, arr->size - 1);
}

// Helper function for merge
static void merge(int *data, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++) {
        L[i] = data[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = data[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data[k++] = L[i++];
        } else {
            data[k++] = R[j++];
        }
    }
    
    while (i < n1) {
        data[k++] = L[i++];
    }
    
    while (j < n2) {
        data[k++] = R[j++];
    }
    
    free(L);
    free(R);
}

// Helper function for merge sort
static void merge_sort_helper(int *data, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_helper(data, left, mid);
        merge_sort_helper(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

// Merge sort
void darray_merge_sort(DArray *arr) {
    if (arr == NULL || arr->size <= 1) {
        return;
    }
    merge_sort_helper(arr->data, 0, arr->size - 1);
}

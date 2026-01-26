#ifndef DSA_ARRAY_H
#define DSA_ARRAY_H

#include <stddef.h>

/**
 * @file dsa_array.h
 * @brief Dynamic Array Data Structure
 * @author Vikash Gupta (@Vortex-16)
 * @date January 2026
 * 
 * This header provides a dynamic array implementation with automatic resizing,
 * insertion, deletion, and various utility operations.
 */

// Structure for dynamic array
typedef struct {
    int *data;          // Pointer to array data
    size_t size;        // Current number of elements
    size_t capacity;    // Total allocated capacity
} DArray;

// Array Creation and Destruction
/**
 * Create a new dynamic array with initial capacity
 * @param initial_capacity Initial capacity of the array
 * @return Pointer to newly created DArray, or NULL on failure
 */
DArray* darray_create(size_t initial_capacity);

/**
 * Free memory allocated for the dynamic array
 * @param arr Pointer to the DArray to be freed
 */
void darray_free(DArray *arr);

// Array Operations
/**
 * Insert an element at a specific position
 * @param arr Pointer to the DArray
 * @param pos Position to insert at (0-based index)
 * @param value Value to insert
 * @return 0 on success, -1 on failure
 */
int darray_insert(DArray *arr, size_t pos, int value);

/**
 * Append an element to the end of the array
 * @param arr Pointer to the DArray
 * @param value Value to append
 * @return 0 on success, -1 on failure
 */
int darray_append(DArray *arr, int value);

/**
 * Delete an element at a specific position
 * @param arr Pointer to the DArray
 * @param pos Position to delete from (0-based index)
 * @return Deleted value on success, -1 on failure
 */
int darray_delete(DArray *arr, size_t pos);

/**
 * Get element at a specific position
 * @param arr Pointer to the DArray
 * @param pos Position to get (0-based index)
 * @param value Pointer to store the value
 * @return 0 on success, -1 on failure
 */
int darray_get(const DArray *arr, size_t pos, int *value);

/**
 * Set element at a specific position
 * @param arr Pointer to the DArray
 * @param pos Position to set (0-based index)
 * @param value Value to set
 * @return 0 on success, -1 on failure
 */
int darray_set(DArray *arr, size_t pos, int value);

// Search Operations
/**
 * Linear search for an element
 * @param arr Pointer to the DArray
 * @param value Value to search for
 * @return Index of element if found, -1 if not found
 */
int darray_search(const DArray *arr, int value);

// Utility Functions
/**
 * Get the current size of the array
 * @param arr Pointer to the DArray
 * @return Current size of the array
 */
size_t darray_size(const DArray *arr);

/**
 * Check if array is empty
 * @param arr Pointer to the DArray
 * @return 1 if empty, 0 otherwise
 */
int darray_is_empty(const DArray *arr);

/**
 * Clear all elements from the array
 * @param arr Pointer to the DArray
 */
void darray_clear(DArray *arr);

/**
 * Print all elements in the array
 * @param arr Pointer to the DArray
 */
void darray_print(const DArray *arr);

/**
 * Reverse the array in place
 * @param arr Pointer to the DArray
 */
void darray_reverse(DArray *arr);

// Sorting Functions
/**
 * Sort array using bubble sort
 * @param arr Pointer to the DArray
 */
void darray_bubble_sort(DArray *arr);

/**
 * Sort array using quick sort
 * @param arr Pointer to the DArray
 */
void darray_quick_sort(DArray *arr);

/**
 * Sort array using merge sort
 * @param arr Pointer to the DArray
 */
void darray_merge_sort(DArray *arr);

#endif // DSA_ARRAY_H

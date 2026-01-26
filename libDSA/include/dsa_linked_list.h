#ifndef DSA_LINKED_LIST_H
#define DSA_LINKED_LIST_H

#include <stddef.h>

/**
 * @file dsa_linked_list.h
 * @brief Singly Linked List Data Structure
 * @author Vikash Gupta (@Vortex-16)
 * @date January 2026
 * 
 * This header provides a singly linked list implementation with operations
 * for insertion, deletion, traversal, and various utility functions.
 */

// Node structure for linked list
typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

// Linked list structure
typedef struct {
    ListNode *head;
    size_t size;
} LinkedList;

// List Creation and Destruction
/**
 * Create a new empty linked list
 * @return Pointer to newly created LinkedList, or NULL on failure
 */
LinkedList* list_create(void);

/**
 * Free all memory allocated for the linked list
 * @param list Pointer to the LinkedList to be freed
 */
void list_free(LinkedList *list);

// Insertion Operations
/**
 * Insert a node at the beginning of the list
 * @param list Pointer to the LinkedList
 * @param data Data to insert
 * @return 0 on success, -1 on failure
 */
int list_insert_begin(LinkedList *list, int data);

/**
 * Insert a node at the end of the list
 * @param list Pointer to the LinkedList
 * @param data Data to insert
 * @return 0 on success, -1 on failure
 */
int list_insert_end(LinkedList *list, int data);

/**
 * Insert a node at a specific position (1-based index)
 * @param list Pointer to the LinkedList
 * @param data Data to insert
 * @param pos Position to insert at (1-based)
 * @return 0 on success, -1 on failure
 */
int list_insert_at(LinkedList *list, int data, size_t pos);

// Deletion Operations
/**
 * Delete the first node from the list
 * @param list Pointer to the LinkedList
 * @return Deleted value on success, -1 on failure
 */
int list_delete_begin(LinkedList *list);

/**
 * Delete the last node from the list
 * @param list Pointer to the LinkedList
 * @return Deleted value on success, -1 on failure
 */
int list_delete_end(LinkedList *list);

/**
 * Delete a node at a specific position (1-based index)
 * @param list Pointer to the LinkedList
 * @param pos Position to delete from (1-based)
 * @return Deleted value on success, -1 on failure
 */
int list_delete_at(LinkedList *list, size_t pos);

/**
 * Delete first occurrence of a value
 * @param list Pointer to the LinkedList
 * @param data Value to delete
 * @return 0 on success, -1 if not found
 */
int list_delete_value(LinkedList *list, int data);

// Search and Access
/**
 * Search for a value in the list
 * @param list Pointer to the LinkedList
 * @param data Value to search for
 * @return Position (1-based) if found, -1 if not found
 */
int list_search(const LinkedList *list, int data);

/**
 * Get value at a specific position
 * @param list Pointer to the LinkedList
 * @param pos Position to get (1-based)
 * @param value Pointer to store the value
 * @return 0 on success, -1 on failure
 */
int list_get(const LinkedList *list, size_t pos, int *value);

// Utility Functions
/**
 * Get the size of the list
 * @param list Pointer to the LinkedList
 * @return Size of the list
 */
size_t list_size(const LinkedList *list);

/**
 * Check if list is empty
 * @param list Pointer to the LinkedList
 * @return 1 if empty, 0 otherwise
 */
int list_is_empty(const LinkedList *list);

/**
 * Clear all nodes from the list
 * @param list Pointer to the LinkedList
 */
void list_clear(LinkedList *list);

/**
 * Print all elements in the list
 * @param list Pointer to the LinkedList
 */
void list_print(const LinkedList *list);

/**
 * Reverse the linked list
 * @param list Pointer to the LinkedList
 */
void list_reverse(LinkedList *list);

/**
 * Sort the linked list using bubble sort
 * @param list Pointer to the LinkedList
 */
void list_sort(LinkedList *list);

#endif // DSA_LINKED_LIST_H

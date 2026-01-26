#include "dsa_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// Helper function to create a new node
static ListNode* create_node(int data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

// Create a new linked list
LinkedList* list_create(void) {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list != NULL) {
        list->head = NULL;
        list->size = 0;
    }
    return list;
}

// Free the linked list
void list_free(LinkedList *list) {
    if (list != NULL) {
        list_clear(list);
        free(list);
    }
}

// Insert at beginning
int list_insert_begin(LinkedList *list, int data) {
    if (list == NULL) {
        return -1;
    }
    
    ListNode *node = create_node(data);
    if (node == NULL) {
        return -1;
    }
    
    node->next = list->head;
    list->head = node;
    list->size++;
    return 0;
}

// Insert at end
int list_insert_end(LinkedList *list, int data) {
    if (list == NULL) {
        return -1;
    }
    
    ListNode *node = create_node(data);
    if (node == NULL) {
        return -1;
    }
    
    if (list->head == NULL) {
        list->head = node;
    } else {
        ListNode *temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    
    list->size++;
    return 0;
}

// Insert at position (1-based)
int list_insert_at(LinkedList *list, int data, size_t pos) {
    if (list == NULL || pos < 1 || pos > list->size + 1) {
        return -1;
    }
    
    if (pos == 1) {
        return list_insert_begin(list, data);
    }
    
    ListNode *node = create_node(data);
    if (node == NULL) {
        return -1;
    }
    
    ListNode *temp = list->head;
    for (size_t i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    node->next = temp->next;
    temp->next = node;
    list->size++;
    return 0;
}

// Delete from beginning
int list_delete_begin(LinkedList *list) {
    if (list == NULL || list->head == NULL) {
        return -1;
    }
    
    ListNode *temp = list->head;
    int data = temp->data;
    list->head = list->head->next;
    free(temp);
    list->size--;
    return data;
}

// Delete from end
int list_delete_end(LinkedList *list) {
    if (list == NULL || list->head == NULL) {
        return -1;
    }
    
    if (list->head->next == NULL) {
        int data = list->head->data;
        free(list->head);
        list->head = NULL;
        list->size--;
        return data;
    }
    
    ListNode *temp = list->head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    int data = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    list->size--;
    return data;
}

// Delete at position (1-based)
int list_delete_at(LinkedList *list, size_t pos) {
    if (list == NULL || list->head == NULL || pos < 1 || pos > list->size) {
        return -1;
    }
    
    if (pos == 1) {
        return list_delete_begin(list);
    }
    
    ListNode *temp = list->head;
    for (size_t i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    ListNode *to_delete = temp->next;
    int data = to_delete->data;
    temp->next = to_delete->next;
    free(to_delete);
    list->size--;
    return data;
}

// Delete first occurrence of value
int list_delete_value(LinkedList *list, int data) {
    if (list == NULL || list->head == NULL) {
        return -1;
    }
    
    // Check if head node contains the value
    if (list->head->data == data) {
        return list_delete_begin(list);
    }
    
    ListNode *temp = list->head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    
    if (temp->next == NULL) {
        return -1; // Value not found
    }
    
    ListNode *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
    list->size--;
    return 0;
}

// Search for value
int list_search(const LinkedList *list, int data) {
    if (list == NULL || list->head == NULL) {
        return -1;
    }
    
    ListNode *temp = list->head;
    size_t pos = 1;
    
    while (temp != NULL) {
        if (temp->data == data) {
            return (int)pos;
        }
        temp = temp->next;
        pos++;
    }
    
    return -1;
}

// Get value at position
int list_get(const LinkedList *list, size_t pos, int *value) {
    if (list == NULL || value == NULL || pos < 1 || pos > list->size) {
        return -1;
    }
    
    ListNode *temp = list->head;
    for (size_t i = 1; i < pos; i++) {
        temp = temp->next;
    }
    
    *value = temp->data;
    return 0;
}

// Get size
size_t list_size(const LinkedList *list) {
    return (list != NULL) ? list->size : 0;
}

// Check if empty
int list_is_empty(const LinkedList *list) {
    return (list == NULL || list->head == NULL) ? 1 : 0;
}

// Clear list
void list_clear(LinkedList *list) {
    if (list == NULL) {
        return;
    }
    
    ListNode *current = list->head;
    while (current != NULL) {
        ListNode *next = current->next;
        free(current);
        current = next;
    }
    
    list->head = NULL;
    list->size = 0;
}

// Print list
void list_print(const LinkedList *list) {
    if (list == NULL || list->head == NULL) {
        printf("[]\n");
        return;
    }
    
    printf("[");
    ListNode *temp = list->head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("]\n");
}

// Reverse list
void list_reverse(LinkedList *list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        return;
    }
    
    ListNode *prev = NULL;
    ListNode *current = list->head;
    ListNode *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    list->head = prev;
}

// Sort list using bubble sort
void list_sort(LinkedList *list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        return;
    }
    
    int swapped;
    ListNode *ptr1;
    ListNode *lptr = NULL;
    
    do {
        swapped = 0;
        ptr1 = list->head;
        
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

#include <stdio.h>
#include "../include/dsa_linked_list.h"

int main() {
    printf("=== Linked List Example ===\n\n");
    
    // Create list
    LinkedList *list = list_create();
    if (list == NULL) {
        printf("Failed to create list\n");
        return 1;
    }
    
    // Insert at beginning
    printf("1. Inserting at beginning: 30, 20, 10\n");
    list_insert_begin(list, 30);
    list_insert_begin(list, 20);
    list_insert_begin(list, 10);
    printf("   List: ");
    list_print(list);
    
    // Insert at end
    printf("\n2. Inserting at end: 40, 50\n");
    list_insert_end(list, 40);
    list_insert_end(list, 50);
    printf("   List: ");
    list_print(list);
    
    // Insert at position
    printf("\n3. Inserting 25 at position 3\n");
    list_insert_at(list, 25, 3);
    printf("   List: ");
    list_print(list);
    
    // Search
    printf("\n4. Searching for 40\n");
    int pos = list_search(list, 40);
    if (pos != -1) {
        printf("   Found at position: %d\n", pos);
    }
    
    // Get element
    printf("\n5. Getting element at position 2\n");
    int value;
    if (list_get(list, 2, &value) == 0) {
        printf("   Value: %d\n", value);
    }
    
    // Delete from beginning
    printf("\n6. Deleting from beginning\n");
    int deleted = list_delete_begin(list);
    printf("   Deleted: %d\n", deleted);
    printf("   List: ");
    list_print(list);
    
    // Delete from end
    printf("\n7. Deleting from end\n");
    deleted = list_delete_end(list);
    printf("   Deleted: %d\n", deleted);
    printf("   List: ");
    list_print(list);
    
    // Delete at position
    printf("\n8. Deleting at position 2\n");
    deleted = list_delete_at(list, 2);
    printf("   Deleted: %d\n", deleted);
    printf("   List: ");
    list_print(list);
    
    // Delete value
    printf("\n9. Deleting value 30\n");
    list_delete_value(list, 30);
    printf("   List: ");
    list_print(list);
    
    // Add more elements for sorting
    printf("\n10. Adding elements for sorting: 50, 10, 30, 20, 40\n");
    list_clear(list);
    list_insert_end(list, 50);
    list_insert_end(list, 10);
    list_insert_end(list, 30);
    list_insert_end(list, 20);
    list_insert_end(list, 40);
    printf("    Unsorted: ");
    list_print(list);
    
    // Sort
    printf("    Sorted: ");
    list_sort(list);
    list_print(list);
    
    // Reverse
    printf("\n11. Reversing list\n");
    list_reverse(list);
    printf("    Reversed: ");
    list_print(list);
    
    // Size and empty check
    printf("\n12. List size: %zu\n", list_size(list));
    printf("    Is empty: %s\n", list_is_empty(list) ? "Yes" : "No");
    
    // Free memory
    list_free(list);
    printf("\n=== List freed successfully ===\n");
    
    return 0;
}

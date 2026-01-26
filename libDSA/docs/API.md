# API Reference

## Table of Contents

1. [Dynamic Array](#dynamic-array)
2. [Linked List](#linked-list)
3. [Stack](#stack)
4. [Queue](#queue)
5. [Error Handling](#error-handling)
6. [Memory Management](#memory-management)

---

## Dynamic Array

### Type Definition

```c
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DArray;
```

### Functions

#### darray_create

```c
DArray* darray_create(size_t initial_capacity);
```

Creates a new dynamic array.

**Parameters:**
- `initial_capacity`: Initial capacity (minimum 10)

**Returns:**
- Pointer to newly created DArray
- NULL on failure

**Example:**
```c
DArray *arr = darray_create(20);
```

---

#### darray_free

```c
void darray_free(DArray *arr);
```

Frees memory allocated for the array.

**Parameters:**
- `arr`: Pointer to the DArray

**Example:**
```c
darray_free(arr);
```

---

#### darray_append

```c
int darray_append(DArray *arr, int value);
```

Appends an element to the end of the array.

**Parameters:**
- `arr`: Pointer to the DArray
- `value`: Value to append

**Returns:**
- 0 on success
- -1 on failure

**Time Complexity:** O(1) amortized

**Example:**
```c
darray_append(arr, 42);
```

---

#### darray_insert

```c
int darray_insert(DArray *arr, size_t pos, int value);
```

Inserts an element at a specific position.

**Parameters:**
- `arr`: Pointer to the DArray
- `pos`: Position to insert (0-based index)
- `value`: Value to insert

**Returns:**
- 0 on success
- -1 on failure or invalid position

**Time Complexity:** O(n)

**Example:**
```c
darray_insert(arr, 2, 99);  // Insert 99 at index 2
```

---

#### darray_delete

```c
int darray_delete(DArray *arr, size_t pos);
```

Deletes an element at a specific position.

**Parameters:**
- `arr`: Pointer to the DArray
- `pos`: Position to delete (0-based index)

**Returns:**
- Deleted value on success
- -1 on failure or invalid position

**Time Complexity:** O(n)

**Example:**
```c
int deleted = darray_delete(arr, 2);
```

---

#### darray_search

```c
int darray_search(const DArray *arr, int value);
```

Searches for a value using linear search.

**Parameters:**
- `arr`: Pointer to the DArray
- `value`: Value to search for

**Returns:**
- Index of element if found
- -1 if not found

**Time Complexity:** O(n)

**Example:**
```c
int pos = darray_search(arr, 42);
if (pos != -1) {
    printf("Found at index %d\n", pos);
}
```

---

#### darray_bubble_sort

```c
void darray_bubble_sort(DArray *arr);
```

Sorts the array using bubble sort algorithm.

**Parameters:**
- `arr`: Pointer to the DArray

**Time Complexity:** O(n²)

**Example:**
```c
darray_bubble_sort(arr);
```

---

#### darray_quick_sort

```c
void darray_quick_sort(DArray *arr);
```

Sorts the array using quick sort algorithm.

**Parameters:**
- `arr`: Pointer to the DArray

**Time Complexity:** O(n log n) average, O(n²) worst case

**Example:**
```c
darray_quick_sort(arr);
```

---

#### darray_merge_sort

```c
void darray_merge_sort(DArray *arr);
```

Sorts the array using merge sort algorithm.

**Parameters:**
- `arr`: Pointer to the DArray

**Time Complexity:** O(n log n)

**Example:**
```c
darray_merge_sort(arr);
```

---

## Linked List

### Type Definition

```c
typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode *head;
    size_t size;
} LinkedList;
```

### Functions

#### list_create

```c
LinkedList* list_create(void);
```

Creates a new empty linked list.

**Returns:**
- Pointer to newly created LinkedList
- NULL on failure

**Example:**
```c
LinkedList *list = list_create();
```

---

#### list_insert_begin

```c
int list_insert_begin(LinkedList *list, int data);
```

Inserts a node at the beginning.

**Parameters:**
- `list`: Pointer to the LinkedList
- `data`: Data to insert

**Returns:**
- 0 on success
- -1 on failure

**Time Complexity:** O(1)

**Example:**
```c
list_insert_begin(list, 42);
```

---

#### list_insert_end

```c
int list_insert_end(LinkedList *list, int data);
```

Inserts a node at the end.

**Parameters:**
- `list`: Pointer to the LinkedList
- `data`: Data to insert

**Returns:**
- 0 on success
- -1 on failure

**Time Complexity:** O(n)

**Example:**
```c
list_insert_end(list, 42);
```

---

## Stack

### Type Definition

```c
typedef struct {
    int *data;
    size_t top;
    size_t capacity;
} Stack;
```

### Functions

#### stack_create

```c
Stack* stack_create(size_t initial_capacity);
```

Creates a new stack.

**Parameters:**
- `initial_capacity`: Initial capacity

**Returns:**
- Pointer to newly created Stack
- NULL on failure

**Example:**
```c
Stack *stack = stack_create(10);
```

---

#### stack_push

```c
int stack_push(Stack *stack, int value);
```

Pushes an element onto the stack.

**Parameters:**
- `stack`: Pointer to the Stack
- `value`: Value to push

**Returns:**
- 0 on success
- -1 on failure

**Time Complexity:** O(1) amortized

**Example:**
```c
stack_push(stack, 42);
```

---

#### stack_pop

```c
int stack_pop(Stack *stack, int *value);
```

Pops an element from the stack.

**Parameters:**
- `stack`: Pointer to the Stack
- `value`: Pointer to store popped value

**Returns:**
- 0 on success
- -1 if stack is empty

**Time Complexity:** O(1)

**Example:**
```c
int value;
if (stack_pop(stack, &value) == 0) {
    printf("Popped: %d\n", value);
}
```

---

## Queue

### Type Definition

```c
typedef struct {
    int *data;
    size_t front;
    size_t rear;
    size_t size;
    size_t capacity;
} Queue;
```

### Functions

#### queue_create

```c
Queue* queue_create(size_t initial_capacity);
```

Creates a new circular queue.

**Parameters:**
- `initial_capacity`: Initial capacity

**Returns:**
- Pointer to newly created Queue
- NULL on failure

**Example:**
```c
Queue *queue = queue_create(10);
```

---

#### queue_enqueue

```c
int queue_enqueue(Queue *queue, int value);
```

Enqueues an element to the rear.

**Parameters:**
- `queue`: Pointer to the Queue
- `value`: Value to enqueue

**Returns:**
- 0 on success
- -1 on failure

**Time Complexity:** O(1) amortized

**Example:**
```c
queue_enqueue(queue, 42);
```

---

#### queue_dequeue

```c
int queue_dequeue(Queue *queue, int *value);
```

Dequeues an element from the front.

**Parameters:**
- `queue`: Pointer to the Queue
- `value`: Pointer to store dequeued value

**Returns:**
- 0 on success
- -1 if queue is empty

**Time Complexity:** O(1)

**Example:**
```c
int value;
if (queue_dequeue(queue, &value) == 0) {
    printf("Dequeued: %d\n", value);
}
```

---

## Error Handling

All functions return appropriate error codes:

- **0**: Success
- **-1**: Failure (invalid parameters, memory allocation failure, etc.)

Always check return values:

```c
if (darray_append(arr, 42) != 0) {
    fprintf(stderr, "Failed to append\n");
    return 1;
}
```

---

## Memory Management

### Best Practices

1. **Always free** allocated data structures:
```c
DArray *arr = darray_create(10);
// ... use array ...
darray_free(arr);
```

2. **Check for NULL** after creation:
```c
DArray *arr = darray_create(10);
if (arr == NULL) {
    // Handle error
}
```

3. **Don't use after free**:
```c
darray_free(arr);
// arr is now invalid - don't use it
```

---

## Complete Example

```c
#include <libdsa/libdsa.h>
#include <stdio.h>

int main() {
    // Create array
    DArray *arr = darray_create(10);
    if (arr == NULL) {
        return 1;
    }
    
    // Add data
    darray_append(arr, 30);
    darray_append(arr, 10);
    darray_append(arr, 20);
    
    // Sort
    darray_quick_sort(arr);
    
    // Search
    int pos = darray_search(arr, 20);
    printf("Found at: %d\n", pos);
    
    // Clean up
    darray_free(arr);
    
    return 0;
}
```

---

For more examples, see the `/examples` directory.

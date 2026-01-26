# Getting Started with libDSA

This guide will help you get started with libDSA in just 5 minutes!

## Table of Contents

1. [Installation](#installation)
2. [Your First Program](#your-first-program)
3. [Common Patterns](#common-patterns)
4. [Next Steps](#next-steps)

---

## Installation

### Quick Install (3 steps)

```bash
# 1. Clone the repository
git clone https://github.com/Vortex-16/C.git
cd C/libDSA

# 2. Build the library
make

# 3. Test that it works
make demo
```

You should see a demo output with arrays, lists, stacks, and queues!

---

## Your First Program

### Step 1: Create a file

Create a file called `my_first_program.c`:

```c
#include <stdio.h>
#include "include/dsa_array.h"

int main() {
    // Create an array
    DArray *arr = darray_create(10);
    
    // Add some numbers
    darray_append(arr, 5);
    darray_append(arr, 2);
    darray_append(arr, 8);
    
    // Print the array
    printf("My array: ");
    darray_print(arr);
    
    // Sort it
    darray_quick_sort(arr);
    printf("Sorted: ");
    darray_print(arr);
    
    // Clean up
    darray_free(arr);
    
    return 0;
}
```

### Step 2: Compile and Run

```bash
# From the libDSA directory
gcc -I./include my_first_program.c -o my_program -L./build -ldsa

# Run it
LD_LIBRARY_PATH=./build:$LD_LIBRARY_PATH ./my_program
```

**Output:**
```
My array: [5, 2, 8]
Sorted: [2, 5, 8]
```

🎉 **Congratulations!** You've just created your first program with libDSA!

---

## Common Patterns

### Pattern 1: Working with Arrays

```c
DArray *arr = darray_create(10);

// Adding elements
darray_append(arr, 10);
darray_append(arr, 20);
darray_insert(arr, 1, 15);  // Insert 15 at position 1

// Accessing elements
int value;
darray_get(arr, 0, &value);
printf("First element: %d\n", value);

// Searching
int pos = darray_search(arr, 20);
printf("20 is at position %d\n", pos);

// Clean up
darray_free(arr);
```

### Pattern 2: Working with Linked Lists

```c
LinkedList *list = list_create();

// Adding elements
list_insert_end(list, 10);
list_insert_end(list, 20);
list_insert_begin(list, 5);  // Add to front

// Print the list
list_print(list);  // [5 -> 10 -> 20]

// Reverse it
list_reverse(list);
list_print(list);  // [20 -> 10 -> 5]

// Clean up
list_free(list);
```

### Pattern 3: Working with Stacks

```c
Stack *stack = stack_create(10);

// Push elements
stack_push(stack, 1);
stack_push(stack, 2);
stack_push(stack, 3);

// Pop elements (LIFO - Last In First Out)
int value;
while (!stack_is_empty(stack)) {
    stack_pop(stack, &value);
    printf("Popped: %d\n", value);  // 3, 2, 1
}

// Clean up
stack_free(stack);
```

### Pattern 4: Working with Queues

```c
Queue *queue = queue_create(10);

// Enqueue elements
queue_enqueue(queue, 1);
queue_enqueue(queue, 2);
queue_enqueue(queue, 3);

// Dequeue elements (FIFO - First In First Out)
int value;
while (!queue_is_empty(queue)) {
    queue_dequeue(queue, &value);
    printf("Dequeued: %d\n", value);  // 1, 2, 3
}

// Clean up
queue_free(queue);
```

---

## Common Use Cases

### Use Case 1: Sorting Data

```c
DArray *arr = darray_create(100);

// Add your data
for (int i = 0; i < 10; i++) {
    darray_append(arr, rand() % 100);
}

// Choose your sorting algorithm
darray_quick_sort(arr);      // Fast for most cases
// darray_merge_sort(arr);   // Stable sort
// darray_bubble_sort(arr);  // Simple, good for small arrays

darray_print(arr);
darray_free(arr);
```

### Use Case 2: Reversing a String with Stack

```c
Stack *stack = stack_create(100);
char str[] = "Hello World";

// Push each character
for (int i = 0; str[i] != '\0'; i++) {
    stack_push(stack, str[i]);
}

// Pop to reverse
printf("Reversed: ");
int ch;
while (!stack_is_empty(stack)) {
    stack_pop(stack, &ch);
    printf("%c", (char)ch);
}
printf("\n");

stack_free(stack);
```

### Use Case 3: Task Queue Simulation

```c
Queue *tasks = queue_create(50);

// Add tasks
printf("Adding tasks...\n");
for (int i = 1; i <= 5; i++) {
    queue_enqueue(tasks, i);
    printf("  Task %d added\n", i);
}

// Process tasks
printf("\nProcessing tasks...\n");
int task_id;
while (!queue_is_empty(tasks)) {
    queue_dequeue(tasks, &task_id);
    printf("  Processing task %d\n", task_id);
}

queue_free(tasks);
```

---

## Error Handling

Always check return values:

```c
DArray *arr = darray_create(10);
if (arr == NULL) {
    fprintf(stderr, "Error: Failed to create array\n");
    return 1;
}

if (darray_append(arr, 42) != 0) {
    fprintf(stderr, "Error: Failed to append\n");
    darray_free(arr);
    return 1;
}

darray_free(arr);
```

---

## Memory Management Tips

1. **Always free** what you create:
```c
DArray *arr = darray_create(10);
// ... use arr ...
darray_free(arr);  // Don't forget this!
```

2. **Don't use after free**:
```c
darray_free(arr);
// arr is now invalid - don't use it!
```

3. **Check for NULL**:
```c
DArray *arr = darray_create(10);
if (arr == NULL) {
    // Handle error
}
```

---

## Next Steps

Now that you know the basics, explore:

1. **Examples** - Check out the `examples/` directory for more
2. **API Reference** - Read `docs/API.md` for detailed documentation
3. **Source Code** - Study the implementation in `src/`
4. **Build Your Own** - Start creating your own programs!

### More Examples to Try

Run these to see more features:

```bash
make run-array    # Array operations
make run-list     # Linked list operations
make run-stack    # Stack operations
make run-queue    # Queue operations
make run-all      # Run all examples
```

---

## Troubleshooting

### "cannot open shared object file"

If you get this error when running:
```bash
# Solution: Set library path
LD_LIBRARY_PATH=./build:$LD_LIBRARY_PATH ./your_program

# Or use static linking
gcc -static your_program.c -L./build -ldsa
```

### Compilation Errors

Make sure you're including the right headers:
```c
#include "include/dsa_array.h"      // If in libDSA dir
// or
#include <libdsa/libdsa.h>          // If installed system-wide
```

---

## Quick Reference Card

```c
// ARRAYS
DArray *arr = darray_create(size);
darray_append(arr, value);
darray_insert(arr, pos, value);
darray_delete(arr, pos);
darray_search(arr, value);
darray_quick_sort(arr);
darray_free(arr);

// LINKED LISTS
LinkedList *list = list_create();
list_insert_end(list, value);
list_delete_begin(list);
list_search(list, value);
list_reverse(list);
list_free(list);

// STACKS
Stack *stack = stack_create(size);
stack_push(stack, value);
stack_pop(stack, &value);
stack_peek(stack, &value);
stack_free(stack);

// QUEUES
Queue *queue = queue_create(size);
queue_enqueue(queue, value);
queue_dequeue(queue, &value);
queue_peek(queue, &value);
queue_free(queue);
```

---

## Need Help?

- 📖 Read the [full documentation](../README.md)
- 💻 Check [examples](../examples/)
- 🐛 [Report issues](https://github.com/Vortex-16/C/issues)
- 💬 Ask questions in discussions

Happy coding! 🚀

# 📚 libDSA - Data Structures & Algorithms Library

<div align="center">

![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![C](https://img.shields.io/badge/language-C-orange.svg)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey.svg)

**A comprehensive, production-ready C library for data structures and algorithms**

[Features](#-features) • [Installation](#-installation) • [Quick Start](#-quick-start) • [Documentation](#-documentation) • [Examples](#-examples) • [Contributing](#-contributing)

</div>

---

## 📖 Overview

**libDSA** is a well-documented, efficient, and easy-to-use C library that provides implementations of fundamental data structures and algorithms. Perfect for students, educators, and developers who need reliable data structure implementations in C.

### Why libDSA?

- ✅ **Production-Ready**: Thoroughly tested and memory-safe
- ✅ **Well-Documented**: Comprehensive API documentation with examples
- ✅ **Easy to Use**: Simple, intuitive API design
- ✅ **Efficient**: Optimized implementations with proper memory management
- ✅ **Educational**: Clear code structure, perfect for learning
- ✅ **Portable**: Works on Linux, macOS, and Windows

---

## 🎯 Features

### Data Structures

| Data Structure | Description | Operations |
|----------------|-------------|------------|
| **Dynamic Array** | Resizable array with automatic memory management | Insert, Delete, Search, Sort, Reverse |
| **Linked List** | Singly linked list implementation | Insert, Delete, Search, Sort, Reverse |
| **Stack** | LIFO (Last In First Out) structure | Push, Pop, Peek |
| **Queue** | FIFO (First In First Out) circular queue | Enqueue, Dequeue, Peek |

### Algorithms

- **Sorting**: Bubble Sort, Quick Sort, Merge Sort
- **Searching**: Linear Search
- **Array Operations**: Insert, Delete, Reverse
- **List Operations**: Traversal, Reversal, Sorting

---

## 🚀 Installation

### Prerequisites

- GCC or any C compiler
- Make (for building)
- Linux, macOS, or Windows with MinGW/Cygwin

### Build from Source

```bash
# Clone the repository
git clone https://github.com/Vortex-16/C.git
cd C/libDSA

# Build the library
make

# Run examples to verify installation
make run-all

# (Optional) Install system-wide
sudo make install
```

### What Gets Built

- `build/libdsa.a` - Static library
- `build/libdsa.so` - Shared library
- `build/example_*` - Example programs

---

## 🔧 Quick Start

### Using the Library

#### Option 1: Include Header Only (After Installation)

```c
#include <libdsa/libdsa.h>

int main() {
    // Create a dynamic array
    DArray *arr = darray_create(10);
    
    // Add elements
    darray_append(arr, 42);
    darray_append(arr, 17);
    darray_append(arr, 99);
    
    // Print array
    darray_print(arr);  // Output: [42, 17, 99]
    
    // Sort
    darray_quick_sort(arr);
    darray_print(arr);  // Output: [17, 42, 99]
    
    // Clean up
    darray_free(arr);
    return 0;
}
```

#### Option 2: Link Against Library

```bash
# Compile and link
gcc myprogram.c -o myprogram -ldsa

# Run
./myprogram
```

---

## 📚 Documentation

### Dynamic Array API

```c
// Creation and Destruction
DArray* darray_create(size_t initial_capacity);
void darray_free(DArray *arr);

// Operations
int darray_append(DArray *arr, int value);
int darray_insert(DArray *arr, size_t pos, int value);
int darray_delete(DArray *arr, size_t pos);
int darray_get(const DArray *arr, size_t pos, int *value);
int darray_set(DArray *arr, size_t pos, int value);

// Search and Sort
int darray_search(const DArray *arr, int value);
void darray_bubble_sort(DArray *arr);
void darray_quick_sort(DArray *arr);
void darray_merge_sort(DArray *arr);

// Utilities
size_t darray_size(const DArray *arr);
int darray_is_empty(const DArray *arr);
void darray_print(const DArray *arr);
void darray_reverse(DArray *arr);
void darray_clear(DArray *arr);
```

### Linked List API

```c
// Creation and Destruction
LinkedList* list_create(void);
void list_free(LinkedList *list);

// Insertion
int list_insert_begin(LinkedList *list, int data);
int list_insert_end(LinkedList *list, int data);
int list_insert_at(LinkedList *list, int data, size_t pos);

// Deletion
int list_delete_begin(LinkedList *list);
int list_delete_end(LinkedList *list);
int list_delete_at(LinkedList *list, size_t pos);
int list_delete_value(LinkedList *list, int data);

// Search and Access
int list_search(const LinkedList *list, int data);
int list_get(const LinkedList *list, size_t pos, int *value);

// Utilities
size_t list_size(const LinkedList *list);
int list_is_empty(const LinkedList *list);
void list_print(const LinkedList *list);
void list_reverse(LinkedList *list);
void list_sort(LinkedList *list);
void list_clear(LinkedList *list);
```

### Stack API

```c
// Creation and Destruction
Stack* stack_create(size_t initial_capacity);
void stack_free(Stack *stack);

// Operations
int stack_push(Stack *stack, int value);
int stack_pop(Stack *stack, int *value);
int stack_peek(const Stack *stack, int *value);

// Utilities
size_t stack_size(const Stack *stack);
int stack_is_empty(const Stack *stack);
int stack_is_full(const Stack *stack);
void stack_clear(Stack *stack);
void stack_print(const Stack *stack);
```

### Queue API

```c
// Creation and Destruction
Queue* queue_create(size_t initial_capacity);
void queue_free(Queue *queue);

// Operations
int queue_enqueue(Queue *queue, int value);
int queue_dequeue(Queue *queue, int *value);
int queue_peek(const Queue *queue, int *value);

// Utilities
size_t queue_size(const Queue *queue);
int queue_is_empty(const Queue *queue);
int queue_is_full(const Queue *queue);
void queue_clear(Queue *queue);
void queue_print(const Queue *queue);
```

---

## 💡 Examples

### Example 1: Dynamic Array Sorting

```c
#include <libdsa/libdsa.h>

int main() {
    DArray *arr = darray_create(10);
    
    // Add unsorted data
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    for (int i = 0; i < 7; i++) {
        darray_append(arr, data[i]);
    }
    
    printf("Unsorted: ");
    darray_print(arr);
    
    // Sort using quick sort
    darray_quick_sort(arr);
    
    printf("Sorted: ");
    darray_print(arr);
    
    darray_free(arr);
    return 0;
}
```

### Example 2: Linked List Operations

```c
#include <libdsa/libdsa.h>

int main() {
    LinkedList *list = list_create();
    
    // Build list: 10 -> 20 -> 30
    list_insert_end(list, 10);
    list_insert_end(list, 20);
    list_insert_end(list, 30);
    
    list_print(list);  // [10 -> 20 -> 30]
    
    // Reverse
    list_reverse(list);
    list_print(list);  // [30 -> 20 -> 10]
    
    list_free(list);
    return 0;
}
```

### Example 3: Stack for String Reversal

```c
#include <libdsa/libdsa.h>
#include <string.h>

int main() {
    Stack *stack = stack_create(20);
    char str[] = "HELLO";
    
    // Push each character
    for (int i = 0; i < strlen(str); i++) {
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
    return 0;
}
```

### Example 4: Queue for Task Scheduling

```c
#include <libdsa/libdsa.h>

int main() {
    Queue *queue = queue_create(10);
    
    // Add tasks
    printf("Scheduling tasks...\n");
    for (int i = 1; i <= 5; i++) {
        queue_enqueue(queue, i * 100);
        printf("  Task %d added\n", i * 100);
    }
    
    // Process tasks (FIFO)
    printf("\nProcessing tasks:\n");
    int task;
    while (!queue_is_empty(queue)) {
        queue_dequeue(queue, &task);
        printf("  Processing task %d\n", task);
    }
    
    queue_free(queue);
    return 0;
}
```

---

## 🛠️ Building and Testing

### Build Commands

```bash
# Build everything
make

# Build only static library
make static

# Build only shared library
make shared

# Build examples
make examples

# Run complete demo
make demo

# Run all examples
make run-all

# Run specific example
make run-array
make run-list
make run-stack
make run-queue

# Clean build files
make clean

# Show help
make help
```

---

## 📁 Project Structure

```
libDSA/
├── include/              # Public header files
│   ├── libdsa.h         # Main header (includes all)
│   ├── dsa_array.h      # Dynamic array
│   ├── dsa_linked_list.h# Linked list
│   ├── dsa_stack.h      # Stack
│   └── dsa_queue.h      # Queue
├── src/                 # Implementation files
│   ├── dsa_array.c
│   ├── dsa_linked_list.c
│   ├── dsa_stack.c
│   ├── dsa_queue.c
│   └── libdsa.c
├── examples/            # Example programs
│   ├── complete_demo.c
│   ├── example_array.c
│   ├── example_linked_list.c
│   ├── example_stack.c
│   └── example_queue.c
├── build/               # Build output directory
├── docs/                # Documentation
├── Makefile            # Build system
└── README.md           # This file
```

---

## 🎓 Learning Resources

### For Beginners

1. Start with `examples/complete_demo.c` - Shows all data structures
2. Read through individual examples in `examples/`
3. Check header files for API documentation

### For Advanced Users

1. Study implementation files in `src/`
2. Understand memory management techniques
3. Analyze algorithm implementations

---

## 📊 Performance

| Operation | Dynamic Array | Linked List | Stack | Queue |
|-----------|--------------|-------------|-------|-------|
| Access | O(1) | O(n) | O(1) peek | O(1) peek |
| Insert (end) | O(1)* | O(n) | O(1) | O(1) |
| Insert (start) | O(n) | O(1) | - | - |
| Delete (end) | O(1)* | O(n) | O(1) | - |
| Delete (start) | O(n) | O(1) | - | O(1) |
| Search | O(n) | O(n) | - | - |

*Amortized time complexity

---

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/AmazingFeature`)
3. **Commit** your changes (`git commit -m 'Add some AmazingFeature'`)
4. **Push** to the branch (`git push origin feature/AmazingFeature`)
5. **Open** a Pull Request

### Contribution Guidelines

- Follow existing code style
- Add tests for new features
- Update documentation
- Ensure all tests pass

---

## 📝 License

This project is licensed under the MIT License - see the LICENSE file for details.

---

## 👨‍💻 Author

**Vikash Gupta**

- GitHub: [@Vortex-16](https://github.com/Vortex-16)
- Repository: [C Programming Collection](https://github.com/Vortex-16/C)

---

## 🙏 Acknowledgments

- Inspired by classic data structure textbooks
- Built for educational purposes and real-world usage
- Thanks to the open-source community

---

## 📞 Support

- 🐛 **Bug Reports**: Open an issue on GitHub
- 💡 **Feature Requests**: Open an issue with enhancement label
- 📖 **Documentation**: Check the `/docs` folder
- 💬 **Questions**: Open a discussion on GitHub

---

## 🗺️ Roadmap

### Version 1.1.0 (Planned)
- [ ] Binary Search Tree
- [ ] Hash Table
- [ ] Graph implementations
- [ ] More sorting algorithms

### Version 1.2.0 (Planned)
- [ ] Generic data types support
- [ ] Thread-safe operations
- [ ] Performance benchmarks
- [ ] Python bindings

---

## ⭐ Star History

If you find libDSA useful, please consider giving it a star! ⭐

---

<div align="center">

**Made with ❤️ by Vikash Gupta**

[⬆ Back to Top](#-libdsa---data-structures--algorithms-library)

</div>

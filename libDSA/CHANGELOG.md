# Changelog

All notable changes to libDSA will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2026-01-26

### Added
- Initial release of libDSA
- Dynamic Array implementation with:
  - Insert, delete, append operations
  - Linear search
  - Bubble sort, quick sort, merge sort
  - Reverse operation
  - Automatic resizing
- Singly Linked List implementation with:
  - Insert at beginning, end, and position
  - Delete from beginning, end, and position
  - Delete by value
  - Search operation
  - Reverse operation
  - Bubble sort
- Stack (LIFO) implementation with:
  - Push and pop operations
  - Peek operation
  - Dynamic resizing
- Queue (FIFO) implementation with:
  - Enqueue and dequeue operations
  - Peek operation
  - Circular buffer implementation
  - Dynamic resizing
- Comprehensive API documentation
- Example programs for all data structures
- Complete demo program
- Makefile build system
- MIT License

### Documentation
- README.md with installation and usage instructions
- API.md with detailed function reference
- CONTRIBUTING.md with contribution guidelines
- Inline code documentation using Doxygen-style comments

### Examples
- example_array.c - Dynamic array operations
- example_linked_list.c - Linked list operations
- example_stack.c - Stack operations including string reversal
- example_queue.c - Queue operations including task scheduling
- complete_demo.c - Demonstration of all data structures

### Build System
- Makefile with targets for:
  - Building static and shared libraries
  - Compiling examples
  - Running tests
  - Installation and uninstallation
  - Cleaning build files

## [Unreleased]

### Planned for v1.1.0
- Binary Search Tree implementation
- Hash Table implementation
- Graph data structure (adjacency list and matrix)
- More sorting algorithms (heap sort, radix sort)
- Binary search for sorted arrays
- Double-ended queue (deque)
- Priority queue

### Planned for v1.2.0
- Generic data type support using void pointers
- Thread-safe versions of data structures
- Performance benchmarking suite
- Memory leak detection tests
- Python bindings
- Extended documentation with tutorials

### Planned for v1.3.0
- AVL Tree (self-balancing BST)
- Red-Black Tree
- B-Tree implementation
- Trie (prefix tree)
- Graph algorithms (DFS, BFS, Dijkstra's, etc.)

---

[1.0.0]: https://github.com/Vortex-16/C/releases/tag/v1.0.0

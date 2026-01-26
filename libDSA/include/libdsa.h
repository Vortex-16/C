#ifndef LIBDSA_H
#define LIBDSA_H

/**
 * @file libdsa.h
 * @brief Main header file for libDSA - Data Structures and Algorithms Library
 * @author Vikash Gupta (@Vortex-16)
 * @date January 2026
 * @version 1.0.0
 * 
 * libDSA is a comprehensive C library providing implementations of common
 * data structures and algorithms. It includes:
 * - Dynamic Arrays
 * - Linked Lists
 * - Stacks
 * - Queues
 * - Sorting Algorithms
 * - Searching Algorithms
 * 
 * Usage:
 *   #include <libdsa.h>
 *   
 *   // Or include specific modules:
 *   #include <dsa_array.h>
 *   #include <dsa_linked_list.h>
 *   #include <dsa_stack.h>
 *   #include <dsa_queue.h>
 */

// Include all data structure headers
#include "dsa_array.h"
#include "dsa_linked_list.h"
#include "dsa_stack.h"
#include "dsa_queue.h"

// Library version information
#define LIBDSA_VERSION_MAJOR 1
#define LIBDSA_VERSION_MINOR 0
#define LIBDSA_VERSION_PATCH 0

#define LIBDSA_VERSION "1.0.0"

/**
 * Get the library version string
 * @return Version string in format "MAJOR.MINOR.PATCH"
 */
const char* libdsa_version(void);

/**
 * Get the library author
 * @return Author name
 */
const char* libdsa_author(void);

#endif // LIBDSA_H

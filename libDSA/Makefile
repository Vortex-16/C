# Makefile for libDSA - Data Structures & Algorithms Library
# Author: Vikash Gupta (@Vortex-16)
# Version: 1.0.0

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2 -fPIC
LDFLAGS = -shared
INCLUDES = -Iinclude

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
EXAMPLES_DIR = examples
TESTS_DIR = tests

# Library name
LIB_NAME = libdsa
STATIC_LIB = $(BUILD_DIR)/$(LIB_NAME).a
SHARED_LIB = $(BUILD_DIR)/$(LIB_NAME).so

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

# Example programs
EXAMPLE_SOURCES = $(wildcard $(EXAMPLES_DIR)/*.c)
EXAMPLE_BINS = $(patsubst $(EXAMPLES_DIR)/%.c,$(BUILD_DIR)/%,$(EXAMPLE_SOURCES))

# Colors for output
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m # No Color

# Default target
.PHONY: all
all: static shared examples
	@echo "$(GREEN)✓ Build completed successfully!$(NC)"
	@echo "$(YELLOW)  Static library: $(STATIC_LIB)$(NC)"
	@echo "$(YELLOW)  Shared library: $(SHARED_LIB)$(NC)"

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@echo "$(GREEN)Created build directory$(NC)"

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build static library
.PHONY: static
static: $(STATIC_LIB)

$(STATIC_LIB): $(OBJECTS)
	@echo "$(GREEN)Creating static library...$(NC)"
	@ar rcs $@ $^
	@echo "$(GREEN)✓ Static library created: $@$(NC)"

# Build shared library
.PHONY: shared
shared: $(SHARED_LIB)

$(SHARED_LIB): $(OBJECTS)
	@echo "$(GREEN)Creating shared library...$(NC)"
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "$(GREEN)✓ Shared library created: $@$(NC)"

# Build examples
.PHONY: examples
examples: $(EXAMPLE_BINS)

$(BUILD_DIR)/%: $(EXAMPLES_DIR)/%.c $(STATIC_LIB)
	@echo "$(YELLOW)Building example: $@...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ -L$(BUILD_DIR) -ldsa -lm

# Run complete demo
.PHONY: demo
demo: $(BUILD_DIR)/complete_demo
	@echo "$(GREEN)Running complete demo...$(NC)"
	@./$(BUILD_DIR)/complete_demo

# Run individual examples
.PHONY: run-array
run-array: $(BUILD_DIR)/example_array
	@echo "$(GREEN)Running array example...$(NC)"
	@./$(BUILD_DIR)/example_array

.PHONY: run-list
run-list: $(BUILD_DIR)/example_linked_list
	@echo "$(GREEN)Running linked list example...$(NC)"
	@./$(BUILD_DIR)/example_linked_list

.PHONY: run-stack
run-stack: $(BUILD_DIR)/example_stack
	@echo "$(GREEN)Running stack example...$(NC)"
	@./$(BUILD_DIR)/example_stack

.PHONY: run-queue
run-queue: $(BUILD_DIR)/example_queue
	@echo "$(GREEN)Running queue example...$(NC)"
	@./$(BUILD_DIR)/example_queue

# Run all examples
.PHONY: run-all
run-all: examples
	@echo "$(GREEN)════════════════════════════════════$(NC)"
	@echo "$(GREEN)   Running all examples$(NC)"
	@echo "$(GREEN)════════════════════════════════════$(NC)"
	@echo ""
	@make run-array
	@echo ""
	@make run-list
	@echo ""
	@make run-stack
	@echo ""
	@make run-queue

# Install library (requires sudo)
.PHONY: install
install: static shared
	@echo "$(YELLOW)Installing libDSA...$(NC)"
	@sudo cp $(STATIC_LIB) /usr/local/lib/
	@sudo cp $(SHARED_LIB) /usr/local/lib/
	@sudo mkdir -p /usr/local/include/libdsa
	@sudo cp $(INC_DIR)/*.h /usr/local/include/libdsa/
	@sudo ldconfig
	@echo "$(GREEN)✓ libDSA installed successfully!$(NC)"
	@echo "$(YELLOW)Include in your projects: #include <libdsa/libdsa.h>$(NC)"
	@echo "$(YELLOW)Compile with: gcc -ldsa$(NC)"

# Uninstall library (requires sudo)
.PHONY: uninstall
uninstall:
	@echo "$(YELLOW)Uninstalling libDSA...$(NC)"
	@sudo rm -f /usr/local/lib/$(LIB_NAME).a
	@sudo rm -f /usr/local/lib/$(LIB_NAME).so
	@sudo rm -rf /usr/local/include/libdsa
	@sudo ldconfig
	@echo "$(GREEN)✓ libDSA uninstalled successfully!$(NC)"

# Clean build files
.PHONY: clean
clean:
	@echo "$(YELLOW)Cleaning build files...$(NC)"
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN)✓ Clean completed$(NC)"

# Show help
.PHONY: help
help:
	@echo "$(GREEN)libDSA - Data Structures & Algorithms Library$(NC)"
	@echo "$(GREEN)═══════════════════════════════════════════════$(NC)"
	@echo ""
	@echo "Available targets:"
	@echo "  $(YELLOW)all$(NC)          - Build static & shared libraries and examples (default)"
	@echo "  $(YELLOW)static$(NC)       - Build static library only"
	@echo "  $(YELLOW)shared$(NC)       - Build shared library only"
	@echo "  $(YELLOW)examples$(NC)     - Build all example programs"
	@echo ""
	@echo "Running examples:"
	@echo "  $(YELLOW)demo$(NC)         - Run complete demo"
	@echo "  $(YELLOW)run-array$(NC)    - Run array example"
	@echo "  $(YELLOW)run-list$(NC)     - Run linked list example"
	@echo "  $(YELLOW)run-stack$(NC)    - Run stack example"
	@echo "  $(YELLOW)run-queue$(NC)    - Run queue example"
	@echo "  $(YELLOW)run-all$(NC)      - Run all examples"
	@echo ""
	@echo "Installation:"
	@echo "  $(YELLOW)install$(NC)      - Install library to system (requires sudo)"
	@echo "  $(YELLOW)uninstall$(NC)    - Uninstall library from system (requires sudo)"
	@echo ""
	@echo "Maintenance:"
	@echo "  $(YELLOW)clean$(NC)        - Remove all build files"
	@echo "  $(YELLOW)help$(NC)         - Show this help message"
	@echo ""
	@echo "Author: Vikash Gupta (@Vortex-16)"
	@echo "Version: 1.0.0"

# Phony targets
.PHONY: all static shared examples demo run-array run-list run-stack run-queue run-all install uninstall clean help

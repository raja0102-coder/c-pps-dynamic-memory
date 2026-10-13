# PPS Dynamic Memory Allocation Engine

A Semester 1 Programming for Problem Solving (PPS) C application demonstrating heap memory management using `malloc`, `calloc`, `realloc`, and `free`.

## PPS Concepts Covered
* **Stack vs Heap**: Understanding automatic stack allocation versus dynamic heap allocation.
* **`malloc()`**: Allocating blocks of uninitialized bytes.
* **`calloc()`**: Allocating contiguous memory blocks initialized automatically to zero.
* **`realloc()`**: Dynamically resizing previously allocated memory blocks at runtime.
* **Memory Leak Prevention**: Releasing heap memory via `free()` and nullifying dangling pointers.

## How to Compile & Run
```bash
gcc main.c -o dynamic_memory
./dynamic_memory

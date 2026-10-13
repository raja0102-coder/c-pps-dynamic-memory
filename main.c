#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("==================================================\n");
    printf("     PPS DYNAMIC MEMORY ALLOCATION ENGINE         \n");
    printf("==================================================\n\n");

    int n = 5;
    int *arr;

    // 1. malloc() - Allocates uninitialized memory
    printf("[1] USING malloc() (Allocation of %d integers):\n", n);
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("    [ERROR] Memory allocation failed!\n");
        return 1;
    }

    // Populate values
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
    }

    printf("    Elements after malloc: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n\n");

    // 2. calloc() - Allocates and zero-initializes memory
    printf("[2] USING calloc() (Zero-initialized allocation):\n");
    int *zeroArr = (int*)calloc(n, sizeof(int));
    if (zeroArr == NULL) {
        printf("    [ERROR] Memory allocation failed!\n");
        free(arr);
        return 1;
    }

    printf("    Elements after calloc (pre-initialized to 0): [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", zeroArr[i]);
    }
    printf("]\n\n");
    free(zeroArr); // Free calloc block

    // 3. realloc() - Resizing existing dynamic allocation
    printf("[3] USING realloc() (Resizing array from %d to %d elements):\n", n, n + 3);
    int newSize = n + 3;
    int *temp = (int*)realloc(arr, newSize * sizeof(int));
    if (temp == NULL) {
        printf("    [ERROR] Reallocation failed!\n");
        free(arr);
        return 1;
    }
    arr = temp; // Update pointer

    // Initialize new elements
    for (int i = n; i < newSize; i++) {
        arr[i] = (i + 1) * 10;
    }

    printf("    Elements after realloc: [ ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n\n");

    // 4. Freeing Memory & Preventing Dangling Pointers
    free(arr);
    arr = NULL; // Safe pointer practice
    printf("[4] MEMORY MANAGEMENT:\n");
    printf("    [SUCCESS] Heap memory successfully released and pointer safely reset.\n");

    printf("\n==================================================\n");

    return 0;
}

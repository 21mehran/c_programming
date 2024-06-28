// 1. Dereferencing a NULL Pointer

#include <stdio.h>

int main() {
    int *ptr = NULL;  // ptr is a NULL pointer
    printf("%d\n", *ptr);  // Dereferencing NULL pointer
    return 0;
}

// Explanation: This code tries to dereference a NULL pointer, leading to a segmentation fault.

// 2. Accessing Array Out of Bounds

#include <stdio.h>

int main() {
    int arr[5];
    arr[10] = 100;  // Accessing out-of-bounds array element
    printf("%d\n", arr[10]);
    return 0;
}

// Explanation: This code tries to access an element outside the bounds of the array arr, leading to undefined behavior and likely a segmentation fault.

// 3. Using Uninitialized Pointer

#include <stdio.h>

int main() {
    int *ptr;  // Uninitialized pointer
    *ptr = 10;  // Dereferencing uninitialized pointer
    printf("%d\n", *ptr);
    return 0;
}

// Explanation: This code uses an uninitialized pointer, which points to an unknown memory location leading to a segmentation fault when dereferenced.

// 4. Writing to Read-Only Memory

#include <stdio.h>

int main() {
    char *str = "Hello, World!";
    str[0] = 'h';  // Trying to modify a string literal
    printf("%s\n", str);
    return 0;
}

// Explanation: This code attempts to modify a string literal, which is stored in read-only memory, leading to a segmentation fault.

// 5. Stack Overflow

#include <stdio.h>

void recursiveFunction() {
    recursiveFunction();  // Infinite recursion
}

int main() {
    recursiveFunction();
    return 0;
}

// Explanation: This code causes an infinite recursion, which eventually leads to a stack overflow and a segmentation fault.

// 6. Freeing Memory Twice

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*) malloc(sizeof(int));
    free(ptr);  // Freeing memory once
    free(ptr);  // Freeing memory again
    return 0;
}

// Explanation: This code attempts to free the same memory twice, leading to undefined behavior and potentially a segmentation fault.

// 7. Accessing Freed Memory.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*) malloc(sizeof(int));
    free(ptr);  // Freeing allocated memory
    *ptr = 10;  // Accessing freed memory
    printf("%d\n", *ptr);
    return 0;
}

// Explanation:
// This code attempts to access memory that has already been freed, leading to a segmentation fault.

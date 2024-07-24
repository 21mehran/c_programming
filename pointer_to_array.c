// Implement a pointer to array.

#include <stdio.h>

int main() {
   
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 9, 2}
    };

    int (*ptr)[4];  // pointer to an array of 4 integers
    ptr = arr;      // Points to first row of 2D array.

    // ptr++;
    // printf ("%d ", (*(*ptr))); // This will print 4 : ptr[1][0]

    // When printing entire 2D array.
    // ptr[i][j] is same as *(ptr)[j] followed by ptr++;

    for (int i = 0; i < 3; i++) {
        printf("%p %d\n", *ptr, *((*ptr))); // Same as (*ptr)[0];
            
        ptr++;      // Move pointer to next row.
    }
    
    // The difference between the pointer is 10 
    // (1 * (16 ^ 1)) + (0 * (16 ^ 0)) = 16 = 4 * sizeof (int);

    return 0;
}


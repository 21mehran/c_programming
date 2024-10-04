
// Find the nth largest number in an array.

#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b) 
{
    return (*(int *)b - *(int *)a);
}

// Function to find the nth largest number in an array
int find_nth_largest (int arr[], int size, int n) 
{
    qsort (arr, size, sizeof(int), compare);
    return arr[n - 1];
}

int main () 
{
    int arr[] = { 3, 1, 14, 7, 9, 23, 5 };
    int size  = sizeof(arr) / sizeof(arr[0]);
    int n;

    printf ("Nth largest : ");
    scanf ("%d", &n);
    
    if (n > size || n < 1) {
        printf("Invalid value of n\n");
        return 1;
    }

    int nth_largest = find_nth_largest (arr, size, n);
    printf ("The %dth largest number is: %d\n", n, nth_largest);

    return 0;
}


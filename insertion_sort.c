// Insertion sort - Implementation.

#include <stdio.h>

void insertion_sort (int arr[], int len) 
{
    for (int i = 1, j; i < n; i++) {
        
        int key = arr[i];
        
        for (j = i - 1; j >= 0 && key < arr[j]; j--) // < Ascending : > desending
            arr[j + 1] = arr[j];

        arr[j + 1] = key;   // Since j is already decremented therefore j + 1;
    }
}

void print_array (int arr[], int size)
{
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]);
        
    printf("\n");
}

int main () 
{
    int arr[] = {12, 11, 13, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    insertion_sort (arr, len);
    print_array (arr, len);

    return 0;
}


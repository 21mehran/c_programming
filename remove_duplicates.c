// Remove Duplicates from an array.

#include <stdio.h>

int remove_duplicates(int arr[], int size) 
{
    if (size == 0 || size == 1)
        return size;
        
    int new_length = 0; // New length of the array after removing duplicates

    for (int i = 0; i < size; i++) {
        // Check if arr[i] is already in the unique part of the array
        int isDuplicate = 0;
        for (int j = 0; j < new_length; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        
        // If arr[i] is not a duplicate, add it to the unique part of the array
        if (!isDuplicate) 
            arr[new_length++] = arr[i];
        
    }

    return new_length; 
}

int main () 
{
    int arr[] = {1,3,2,3,2,3,4,5,2,1,6,7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array before removing duplicates:\n");
    for (int i = 0; i < size; i++) 
        printf ("%d ", arr[i]);
    
    size = remove_duplicates(arr, size);

    printf("\n\nArray after removing duplicates:\n");
    for (int i = 0; i < size; i++) 
        printf ("%d ", arr[i]);
    
    return 0;
}


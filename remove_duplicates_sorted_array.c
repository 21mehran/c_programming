// Remove duplicate elements from a sorted array.

#include <stdio.h>

void print_array (int arr[], int len) 
{
    for (int i = 0; i < len; i++)
        printf ("%d ", arr[i]);
}

int remove_duplicates (int arr[], int len)
{   
    int i = 0;
    int index = 0;
    
    for (int i = 0; i < len; i++) {
        
         if (arr[index] != arr[i]) {
                index++;
                arr[index] = arr[i];
         }
    }
    
    return index + 1;
}

int main () 
{
    int arr[] = {1, 1, 2, 2, 3, 3, 3, 4, 5, 5, 6 , 6};
    int len = sizeof (arr) / sizeof (arr[0]);
    
    int index = remove_duplicates (arr, len);
    print_array (arr, index);

    return 0;
}

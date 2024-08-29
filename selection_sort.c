// SELECTION SORT - IMPLEMENTATION.

#include <stdio.h>

void print_array (int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf ("%d ", arr[i]);
}

void swap (int *one, int *two) 
{
    int temp = *one;
    *one = *two;
    *two = temp;
}

void selection_sort (int arr[], int len) 
{
    for (int i = 0; i < len; i++) {
        
        int min_index = i;
        
        for (int j = i + 1; j < len; j++) 
        {
            if (arr[j] < arr[min_index]) 
                min_index = j;
        }
        
        if (min_index != i)
        swap (&arr[min_index], &arr[i]);
    }
}

int main ()
{
    int arr[] = { 2, 8, 5, 3, 9, 4, 1 };
    int len = sizeof (arr) / sizeof (arr[0]);
    
    selection_sort (arr, len);
    print_array (arr, len);
    
    return 0;
}

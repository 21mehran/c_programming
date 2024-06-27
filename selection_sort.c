// SELECTION SORT - ALGORITHM

#include <stdio.h>

int selection_sort (int arr[], int len) 
{
    for (int i = 0; i < len; i++) {
        
        int min_index = i;
        
        for (int j = i + 1; j < len; j++) {
            
            if (arr[j] < arr[min_index])
                min_index = j;
        }
            
        if (min_index != i) {
            int temp = arr[i];
            arr[i] =  arr[min_index];
            arr[min_index] = temp;
        }    
    }
}


int main ()
{
    int arr[] = {2,3,1,5,7,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    selection_sort (arr, len);
    
    for (int i = 0; i < 6; i++)
        printf ("%d ", arr[i]);
}


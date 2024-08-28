// Find the second largest element in the array witout sorting.

#include <stdio.h>
#include <limits.h>

int find_second_largest (int arr[], int size)
{
    int large = arr[0];
    int second_large = INT_MIN;
    
    int second_large_index = -1;
    
    for (int i = 0; i < size; i++) {
        
        if (arr[i] > large) {
            
            second_large = large;
            large = arr[i];
            second_large_index = i;
            
        } else if (arr[i] > second_large && arr[i] != large) {
            
            second_large = arr[i];
            second_large_index = i;
        }
    }
    
    return second_large_index;
}

int main ()
{
    int arr[] = {12, 35, 1, 10, 34, 13};
    int size = sizeof (arr) / sizeof (arr[0]);
    
    int second_large_index = find_second_largest (arr, size);
    printf ("%d ", arr[second_large_index]);
    
    return 0;
}

// Find the Second Largest Number in an array.

#include <stdio.h>
#include <limits.h>

int find_second_largest (int arr[], int len)
{
    int smallest = arr[0];
    int second_smallest = INT_MAX;
    
    for (int i = 0; i < len; i++) {
        
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if(arr[i] < second_smallest && arr[i] != smallest)
            second_smallest = arr[i];
    }
    
    return second_smallest;
}

int main () 
{
    int arr[] = {1, 3, 2, 6, 7, 2, 6, 5};
    int len = sizeof (arr)/ sizeof (arr[0]);
    
    printf("Second Smallest Number : %d ", find_second_largest (arr, len));
    return 0;
}

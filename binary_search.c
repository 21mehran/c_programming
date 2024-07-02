// Binary search algorithm.
// Condition is the array needs to be sorted.

#include <stdio.h>

int binary_search (int *arr, int len, int target)
{
    int start = 0;
    int end = len - 1;
    int mid = start + (end - start) / 2;
    
    while (start <= end) {
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
            
        start++;
        end--;
    }
}

int main ()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int len = sizeof (arr) / sizeof (arr[0]);
    int target = 70;
    
    int position = binary_search (arr, len, target);
    
    printf ("Target is at position - %d ", position);
}

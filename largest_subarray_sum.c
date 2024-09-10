// Find the smallest subarray who sum is equal to target

#include <stdio.h>

void largest_subarray_sum (int arr[], int len, int target)
{
    int large_subarray = len;
    int large_start = 0;
    int large_end = 0;
    
    for (int win_size = 1; win_size <= len; win_size++) {
        
        for (int start = 0; start <= len - win_size; start++) {
            
            int end = start + win_size - 1;
            int sum = 0;
            
            for (int i = start; i <= end; i++) 
                sum = sum + arr[i];
            
            if (win_size < large_subarray && sum == target) {
                
                large_subarray = win_size;
                large_start = start;
                large_end = end;
            }
        }
    }

	// Printing the smallest subarray
    for (int i = large_start; i <= large_end; i++)
        printf ("%d ", arr[i]);
}

int main() 
{
   int arr[] = {1, 2, 4, 5};
   int len = sizeof (arr) / sizeof (arr[0]);
   int target = 7;
   
   smallest_subarray_sum (arr, len, target);
   return 0;
}

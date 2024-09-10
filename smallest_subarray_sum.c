// Find the smallest subarray who sum is equal to target

#include <stdio.h>

void smallest_subarray_sum (int arr[], int len, int target)
{
    int small_subarray = len;
    int small_start = 0;
    int small_end = 0;
    
    for (int win_size = 1; win_size <= len; win_size++) {
        
        for (int start = 0; start <= len - win_size; start++) {
            
            int end = start + win_size - 1;
            int sum = 0;
            
            for (int i = start; i <= end; i++) 
                sum = sum + arr[i];
            
            if (win_size < small_subarray && sum == target) {
                
                small_subarray = win_size;
                small_start = start;
                small_end = end;
            }
        }
    }

	// Printing the smallest subarray
    for (int i = small_start; i <= small_end; i++)
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

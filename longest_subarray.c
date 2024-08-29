// Find the longest subarray whose sum equals target.

#include <stdio.h>

void print_subset (int arr[], int start, int end)
{
    printf("The subarray with the maximum sum is : ");
    for (int i = start; i < end; i++) 
        printf("%d ", arr[i]);
}

void max_sum_subarray (int arr[], int len, int target) 
{
    int start, end, sum, j;
    start = end = sum = j = 0;
    
    for (int i = 0; i < len; i++) {
        
        sum = 0;  
        
        for (j = i; j < len; j++) 
            sum = sum + arr[j];  

        if (sum == target) {
            start = i;  
            end = j;   
        }
    }
    
    print_subset (arr, start, end);
}

int main ()
{
    int arr[] = {1, 2, -1, 0, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    max_sum_subarray (arr, len, target);
    return 0;
}


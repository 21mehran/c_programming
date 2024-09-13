// Find the array elements that add up to give a target
// Sorted arrays.

#include <stdio.h>

void two_pointer (int arr[], int start, int end, int target)
{
    while (end >= start) {
        
        int sum = arr[start] + arr[end];
        
        if (arr[start] + arr[end] == target) 
            printf ("[%d %d]\n", arr[start++], arr[end--]);
        else if (sum < target)
            start++;
        else
            end--;   
    }
}

int main () 
{
    int arr[] = { 1, 5, 2, 6, 3, 7, 4, 8 };
    int target = 9;
    int start = 0;
    int end = 9;

    two_pointer (arr, start, end, target);

    return 0;
}


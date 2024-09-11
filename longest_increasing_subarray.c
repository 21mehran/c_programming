// Find the longest increasing subarray 

#include <stdio.h>

void sub_seq (int arr[], int len) 
{
    int max = 0;
    int count = 0;
    int start = 0;
    
    for (int i = 0; i + 1 < len; i++) {
        
        if (arr[i + 1] > arr[i])
            count++;
        else
            count = 1;
        
        if (count > max) {
            max = count;
            start = (i + 1) - (max - 1);
        }    
    }
    
    for (int i = start; i < start + max; i++)
        printf ("%d ", arr[i]);
}

int main () 
{
    int arr[] = {10, 9, 2, 5, 3, 1, 2, 3, 4, 2, 1};
    int len = sizeof (arr) / sizeof (arr[0]);

    sub_seq (arr, len);
    
    return 0;
}

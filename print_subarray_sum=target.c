// Print all subsequences whos sum equals target.

#include <stdio.h>

void sub_seq (int arr[], int len, int target) 
{
    int start = 0;
    int end = 0;
    
    for (int size = 1; size <= len; size++) {
        
        for (int start = 0; start <= len - size; start++) {
         
            end = start + size - 1;
            int sum = 0;
            
            for (int i = start; i <= end; i++) 
                sum = sum + arr[i];
                
            if (sum == target) {   
                
                for (int j = start; j <= end; j++)
                    printf ("%d ", arr[j]);
             
                printf ("\n");   
            }    
        }
    }
}

int main () 
{
    int arr[] = {10, 9, 2, 5, 3, 1, 2, 3, 4, 2, 1};
    int len = sizeof (arr) / sizeof (arr[0]);

    sub_seq (arr, len, 10);
    
    return 0;
}

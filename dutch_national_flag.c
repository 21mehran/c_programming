// Segregate 0's 1's and 2's using Dutch National flag algorithm. 

#include <stdio.h>

void dutch_flag (int arr[], int len) 
{
    int start = 0;
    int mid = 0;
    int end = len - 1;
    
    while (mid <= end) {   

        if (arr[mid] == 0) {
            
            int temp = arr[start];
            arr[start] = arr[mid];
            arr[mid] = temp;
            start++;
            mid++;
            
        } else if (arr[mid] == 1) {
            mid++;
        } else { 
            
            int temp = arr[mid];
            arr[mid] = arr[end];
            arr[end] = temp;
            end--;
        }
    }
}

int main () 
{
    int arr[] = {0, 1, 2, 0, 2, 1};
    int len = sizeof (arr) / sizeof (arr[0]);
    
    printf ("\nBefore Segregation\n");
    for (int i = 0; i < 6; i++)
        printf ("%d ", arr[i]);
    
    dutch_flag (arr, len);
    
    printf ("\n\nAfter Segregation\n");
    for (int i = 0; i < 6; i++)
        printf ("%d ", arr[i]);
    
    return 0; 
}

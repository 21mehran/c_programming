// Find the element in the array which is repeated most number of times.

#include <stdio.h>

int main ()
{
    int arr[] = {1, 2, 3, 3, 4, 1, 2, 5, 2, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    int freq[10] = {0};
    int count = 0;
    int max_count = 0;
    int max_number = 0;
    
    for (int i = 0; i < len; i++) {
        
        count = 1;
        
        if (freq[i] == -1)    // Check if element is Repeated.
            continue;
        else {   
            for (int j = i + 1; j < len; j++) {
            
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = -1; 
                }
            }
        }
        
        freq[i] = count;
        
        if (freq[i] > max_count) {
            max_count = freq[i];
            max_number = arr[i];
        }    
    }
    
    printf ("%d is repeated Maximum Number of times (%d).", max_number, max_count);
}

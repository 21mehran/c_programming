// PRINT THE ELEMENT OF AN ARRAY WITH HIGHEST FREQUENCY.


#include <stdio.h>
#include <limits.h>

#define MAX 100

int main ()
{
    int arr[] = {1,3,2,3,4,1,3,2,2,3};
    int len = sizeof(arr) / sizeof (arr[0]);
    
    // Assuming array elements are within the range of 0 - 100
    int hashTable[MAX] = {0};

    // Populate the hashTable;
    for (int i = 0; i < len; i++)
        hashTable[arr[i]]++;
    
    // Find Max repeated Number.
    int max_count = 0;
    int max_number = arr[0];
    
    for (int i = 0; i < MAX; i++) {
        
        if (hashTable[i] > max_count) {
            
            max_count = hashTable[i];
            max_number = i;
        }
    }
    
    printf ("Number : %d\nFreq : %d", max_number, max_count);
    
    return 0;
}


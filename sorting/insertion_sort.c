// IMPLEMENTING INSERTION SORT ALGORITHM. 

#include <stdio.h>

void insertion_sort (int arr[], int len) 
{
    for (int i = 1; i < len; i++) {

        int temp = arr[i];
        int j = i - 1;
        
        while (j >= 0 && temp < arr[j]) { 
    
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = temp;
    } 
}

int main() {
    
    int arr[] = {12, 11, 13, 5, 6};
    int len = sizeof(arr)/sizeof(arr[0]);

    insertion_sort (arr, len);
        
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    return 0;
}

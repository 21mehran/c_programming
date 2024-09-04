// Print array elements backwards using Recursion.

#include <stdio.h>

void printer (int arr[], int len)
{
    if (len <= 0)
        return;
    else {
         printf ("%d ", arr[len - 1]);             // Print arr in reverse order. 
         printer (arr, len - 1);            
         printf ("%d ", arr[len - 1]);             // Print arr in normal order.
    }
}

void printer (int *arr, int len) 
{
    if (len) {

        printf ("%d ", *arr);           // Prints array normal.
        printer (arr + 1, len - 1);
        printf ("%d ", *arr);           // Prints array backwards.
    }
}

int main () 
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int len = sizeof (arr)/sizeof (arr[0]);
    
    printer (arr,len);
    return 0;
}

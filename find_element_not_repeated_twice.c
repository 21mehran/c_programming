// Detect the number in an array which is not repeated twice.

#include <stdio.h>

int find_non_repeating_element (int* arr, int size) 
{
    int result = 0;
    for (int i = 0; i < size; i++) 
        result = result ^ arr[i];
    
    return result;
}

int main ()
{
    int arr[] = {1,2,3,4,5,3,5,4,1};
    int size = sizeof (arr)/ sizeof (arr[0]);
    
    printf ("%d",  find_non_repeating_element (arr, size));
    return 0;
}

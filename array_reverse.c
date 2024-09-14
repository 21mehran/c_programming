// Reverse a array using Recursion.

#include <stdio.h>

int *array (int *arr, int len, int *rev)
{
    if (len <= 0) 
        return rev;
    else {
        rev = array (arr + 1, len - 1, rev);
        *rev = *arr;
        return rev + 1;
    }
}

int main () 
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof (arr) / sizeof (arr[0]);
    int rev[len];
    
    array (arr, len, rev);

    for (int i = 0; i < len; i++)
        printf ("%d ", rev[i]);

    return 0;
}

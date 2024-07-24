// REVERSING AN ARRAY USING A SINGLE LOOP.

#include <stdio.h>

int main() 
{
    int arr[] = {1,2,3,4,5,6};
    int len = (sizeof (arr)) / (sizeof (int));

    for (int start = 0, end = len - 1 ; start < end; start++, end--) {

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }

    for (int i = 0; i < len ; i++)
        printf ("%d ", arr[i]);

}

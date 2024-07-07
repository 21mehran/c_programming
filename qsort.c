// Sorting half array into ascending and the rest into descending.
// Note - Using Inbuilt quick_sort <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int ascending (const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int descending (const void *a, const void *b)
{
    return *(int *)b - *(int *)a;    
}

int main ()
{
    int arr[] = { 5, 2, 9, 1, 5, 6, 3, 8, 4, 7, 99};
    int len = sizeof(arr) / sizeof(arr[0]);
    int half_len = len / 2;

    printf("Original array: \n");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");

    // void qsort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));

    qsort (arr, half_len, sizeof (int), ascending);
    qsort (arr + half_len, len - half_len, sizeof (int), descending);
    
    printf("Sorted array in ascending order: \n");
    for (int i = 0; i < len; i++) 
        printf("%d ", arr[i]);
    
    printf("\n");
}

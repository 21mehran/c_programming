// Find repeated and non repeated elements in an array.

#include <stdio.h>
#define MAX 10

void print_duplicates (int arr[], int n) 
{
    int count[MAX] = {0}; 

    for (int i = 0; i < n; i++) 
        count[arr[i]]++;

    printf("Duplicate elements are:\n");
    for (int i = 0; i < MAX; i++) {
        if (count[i] > 1) 
            printf("%d ", i);
    }
    
    printf("\n\nNon Duplicate elements are:\n");
    for (int i = 0; i < MAX; i++) {
        if (count[i] == 1) 
            printf("%d ", i);
    }
    
    printf("\n");
}

int main ()
{
    int arr[] = {1, 2, 3, 2, 4, 1, 4, 5, 6, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    print_duplicates (arr, n);

    return 0;
}


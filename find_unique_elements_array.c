// Print all the Non repeatative or unique elements in the array.

#include <stdio.h>
#define HASH_SIZE 10

void find_unique_elements (int arr[], int len)
{
    int hash[HASH_SIZE] = {0};

    for (int i = 0; i < len; i++)
        hash [arr[i]]++;

    for (int i = 0; i < HASH_SIZE; i++) {

        if (hash[i] == 1)
            printf ("%d ", i);
    }

}

int main (void)
{
    int arr[] = {1, 2, 1, 3, 2, 4, 5, 5, 6, 7, 8, 7};
    int len = sizeof (arr) / sizeof (arr[0]);

    find_unique_elements (arr, len);

}

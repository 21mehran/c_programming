// Counting sort - Implementation.

#include <stdio.h>
#include <string.h>

int find_max (int arr[], int len)
{
    int max = 0;

    for (int i = 0; i < len; i++) {

        if (max > arr[i])
            max = arr[i];
    }

    return max;
}

void counting_sort (int arr[], int len)
{
    int count_len = find_max (arr, len)];

    int count[count_len];
    int output[len];

    memset (count_len, 0, sizeof (count));

    for (int i = 0; i < len; i++)
        count[arr[i]]++;

    // 2nd element is sum of 1st and 2nd element.
    for (int i = 1; i < len; i++)
        count[i] = count[i] + count[i - 1];

    for (int i = len - 1; i >= 0; i--) {

        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copying the array.
    for (int i = 0; i < len; i++)
        arr[i] = output[i];
}

void print_array (int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf ("%d ", arr[i]);
}

int main (void)
{
    int arr[] = {10, 8, 1, 3, 12, 14, 31, 8, 1, 4, 5, 3};
    int len = sizeof (arr) / sizeof (arr[0]);

    counting_sort (arr, len); 
    print_array (arr, len);

    return 0;
}


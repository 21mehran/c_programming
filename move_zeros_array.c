// Move zeros to end of the array.
// Move zeros to start of the array.

#include <stdio.h>

void print_array (int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf ("%d ", arr[i]);

    printf("\n");
}

void move_zeros_to_start (int arr[], int len) 
{
    int j = len - 1;

    for (int i = len - 1; i >= 0; i--) {

        if (arr[i] != 0) 
            arr[j--] = arr[i];
    }

    // Fill the remaining part of the array with zeros
    while (j >= 0) {
        arr[j--] = 0;
    }
}

void move_zeros_to_end (int arr[], int len) 
{
    int j = 0;

    for (int i = 0; i < len; i++) {

        if (arr[i] != 0)
            arr[j++] = arr[i];
    }

    // Fill the remaining part of the array with zeros
    while (j < len) {
        arr[j++] = 0;
    }
}

int main ()
{
    int arr[] = {1, 2, 0, 3, 0, 0, 4, 5};
    int len = sizeof (arr) / sizeof (arr[0]);

    print_array (arr, len);

    move_zeros_to_end (arr, len);
    print_array (arr, len);

    move_zeros_to_start (arr, len);
    print_array (arr, len);

    return 0;
}


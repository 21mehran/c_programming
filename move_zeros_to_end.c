// Move zeros to end of the array.

#include <stdio.h>

// To messy method 
void move_zeros_to_end (int arr[], int len)
{
    for (int i = 0; i < len - 1; i++) 
    {
        if (arr[i] == 0 && arr[i + 1] != 0) {

            if (flag == 1) {
                k = i;
                flag = 0;
            }

            // Swap the elements
            int temp = arr[i + 1];
            arr[i + 1] = arr[k];
            arr[k] = temp;
            k = k + 1;
        }
    }
}

// Cool method

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

    move_zeros_to_end (arr, len);
    print_array (arr, len);

    return 0;
}


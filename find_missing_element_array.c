// In a array of natural numbers from 1 - 6
// Find the missing element.

#include <stdio.h>

int find_missing_number (int arr[], int size) 
{
    int xor_full = 0;  // XOR of all numbers from 1 to N
    int xor_array = 0; // XOR of all elements in the array

    // Using Bitwise operations.
    for (int i = 1; i <= size + 1; i++)  // Size + 1 because you have to consider the missing element as well. 
        xor_full = xor_full ^ i;

    for (int i = 0; i < size; i++) 
        xor_array = xor_array ^ arr[i];
    
    // Using simple loop.
    for (int i = 0; i < size; i++) {
        if ((arr[i + 1] - arr[i]) > 1)
            return arr[i] + 1;
    }

    return xor_full ^ xor_array;
}

// For non consecutive array.

int find_missing_number (int arr[], int size)
{
  int n = size + 1;
  int expected_sum = (n * (n + 1)) / 2;
  int actual_sum = 0;

  for (int i = 0; i < size; i++)
      actual_sum = actual_sum + arr[i];

  return expected_sum - actual_sum;
}


int main () 
{
    int arr[] = {1, 2, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int missing_number = find_missing_number(arr, size);
    printf("The missing number is: %d\n", missing_number);
    return 0;
}


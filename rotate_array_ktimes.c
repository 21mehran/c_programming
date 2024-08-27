// Rotate an array k times.

#include <stdio.h>
#include <stdint.h>

uint8_t rotate_array (uint8_t arr[], uint8_t len, uint8_t k)
{
    for (uint8_t i = 0; i < k; i++) {
        
    uint8_t temp = arr[len - 1];
    
    for (uint8_t i = len - 1; i > 0; i--)
        arr[i] = arr[i - 1];
        
    arr[0] = temp;
    
    }
}

void print_array (uint8_t arr[], uint8_t len)
{
    for (uint8_t i = 0; i < len; i++)
        printf ("%d ", arr[i]);
}

int main() {
    
    uint8_t arr[] = {1,2,3,4,5};
    uint8_t len = sizeof (arr) / sizeof (arr[0]);
    uint8_t rotations = 2;
    
    rotate_array (arr, len, rotations);
    print_array (arr, len);

    return 0;
}

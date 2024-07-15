// Rotate a number using bitwise.

// ex 0000 1010 -> 0101 0000
// 10 -> 80

#include <stdio.h>

int main () 
{
    int num = 1; 
    int rev = 0;
    int position = 0;
    int total_bits = sizeof(num) * 8; 

    while (position < total_bits) {
        
        rev = rev | (((num >> position) & 1) << (total_bits - 1 - position));
        position++;
    }

    // for (int i = 0; i < total_bits; i++)
    //    rev = rev | ((num >> i) & 1) << (total_bits - 1 - i);

    printf("Rotated bits result: %u\n", rev);
    
    return 0;
}



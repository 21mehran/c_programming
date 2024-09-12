// Swap adjacent bits.

#include <stdio.h>

int swap_adjacent_bits (int num) 
{
    for (int i = 0; i < 8; i = i + 2) {
        int bit = (num >> i) & 3;
        
        if ((bit & 1) != (bit >> 1) & 1) 
            num = num ^ (3 << i);
    }
    return num;
}

int swap_adjacent_bits (int num) 
{
    int even = num & 0xAA;
    int odd  = num & 0x55;
    
    num = (even >> 1) | (odd << 1);
    return num;
}

int main () 
{
    int num = 45;
    int rev = 0;
    
    num = swap_adjacent_bits (num);
    printf ("%d ", num);

    return 0;
}

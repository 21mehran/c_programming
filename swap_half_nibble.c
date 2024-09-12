// Swap half nibble.

#include <stdio.h>

int swap_half_nibble (int num) 
{
    for (int i = 0; i < 16; i = i + 4) {

        int bit = (num >> i) & 0xF;        

        int mask = (bit & ~0xC) ^ (bit >> 2);  
        mask = (mask << 2) | mask;

        num = num ^ (mask << i);       
    }

    return num;
}

int swap_half_nibble (int num) 
{
    int even = num & 0x3333;
    int odd  = num & 0xCCCC;

    num = (even << 2) | (odd >> 2);
    return num;
}

int main () 
{
    int num = 0b1100110010111011; 
    int res = 0;

    res = swap_half_nibble (num);
    printf ("%x ", res);

    return 0;
}

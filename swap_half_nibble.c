// Swap half nibble.

#include <stdio.h>

int swap_half_nibble (int num, int rev) 
{
    for (int i = 0; i < 8; i = i + 4) {
        
        int bit1 = (num) & 0b11;
        int bit2 = (num >> i + 2) & 0b11;
        
        int mask = (bit1 << 2) | bit2;
        rev = (rev << 4) | (mask);
    }
    
    return rev;
}

int swap_half_nibble (int num, int rev) 
{
    int even = num & 0x33;
    int odd  = num & 0xCC;
    
    num = (even << 2) | (odd >> 2);
    return num;
}

int main () 
{
    int num = 0b10111011;
    int rev = 0;
    
    rev = swap_half_nibble (num, rev);
    printf ("%x ", rev);
    
    return 0;
}

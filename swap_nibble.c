// Nibble swap : 0x12345678 - 0x21436587
// Each number here represents a nibble - 4 bits

#include <stdio.h>

int swap_nibble (int num) 
{
    for (int i = 0; i < 32; i = i + 8) {
        
        int bit = (num >> i) & 0xFF;
        
        int mask = (bit & ~0xF0) ^ (bit >> 4);
        mask = mask | (mask << 4);
        
        num = num ^ (mask << i);
    }
    
    return num;

    /*
        for (int i = 0, j = 3; i < 4; i++, j--) {
        
            int bit = (num >> (8 * i)) & 0xFF;
            result = result | (bit << (8 * j));
        }
    */
}

int main () 
{
    int num = 0x12345678;
    int res = 0;
    
    printf("Original num : %x\n", num);
    
    // Using Loop
    swap_nibble (&num, &res);
    
    // Using Hardcoding.
    int even = num & 0xF0F0F0F0;
    int odd  = num & 0x0F0F0F0F;
    res = (even >> 4) | (odd << 4);
    
    printf("Swapped num  : %x", res);
    return 0;
}

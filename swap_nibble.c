// Nibble swap : 0x12345678 - 0x21436587
// Each number here represents a nibble - 4 bits

#include <stdio.h>

void swap_nibble (int *num, int *res)
{
    // Using loop
    for (int i = 0; *num; i++, *num = *num >> 8) {
        
        int nibble_1 = *num & 0xF;
        int nibble_2 = (*num >> 4) & 0xF;
        
        int swap = nibble_2 | (nibble_1 << 4);
        *res = *res | (swap << (8 * i));
    }
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

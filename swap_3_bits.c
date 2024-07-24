// Swap 3 bits from 4 - 6 with bits from 9 - 11.

#include <stdio.h>
#include <stdint.h>

int main ()
{
    uint16_t num = 0b1001111101101101;
    
    uint8_t bit1 = (num >> 4) & 7;
    uint8_t bit2 = (num >> 9) & 7;
    
    // Obvious Method.
    num = num & ~((7 << 4) | (7 << 9));
    num =  num | ((bit1 << 9) | (bit2 << 4)); 
    
    // Cool Method.
    uint8_t xoro = bit1 ^ bit2;
    num = num ^ ((xoro << 9) | (xoro << 4));
    
    printf ("%d", num);
}

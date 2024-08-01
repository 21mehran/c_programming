// Calculate the number of bits to be flipped to convert num1 -> num2.

#include <stdio.h>
#include <stdint.h>

struct bitfield {
    
    uint8_t num_1 : 5;
    uint8_t num_2 : 5;
    uint8_t count : 5;

} flip;

int count_set (int num, int count) 
{
    if (!num)
        return count;
    else 
        count_set (num & (num - 1), count + 1);
}

int main () 
{
    flip.num_1 = 29;
    flip.num_2 = 20;
    flip.count = 0;
    
    uint8_t xoro = flip.num_1 ^ flip.num_2;
    flip.count   = count_set (xoro, flip.count);
    
    printf ("Number of Bits to be flipped to convert 29 to 20 : %d ", flip.count);

    return 0;
}

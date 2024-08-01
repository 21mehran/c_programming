// Print a list of number whose 1 bit if fliped equals target

#include <stdio.h>
#include <stdint.h>

/* This method works only for 1 flip check */

void flip_one (int num) 
{
    for (uint8_t i = 0; i < 31; i++) {
        
        uint32_t flipped_num = num ^ (1 << i);
        printf ("%d\n", flipped_num);
    }
}

void flip_n (int num)
{
    uint8_t count = 0;
    uint8_t xoro = 0;
    uint8_t limit = 30;
    
    for (uint8_t i = 0; i < limit; i++) {
        
        xoro = num ^ i;
        count = 0;
        
        while (xoro) {
            
            xoro = xoro & (xoro - 1);
            count++;
        }
        
        count == 1 ? printf ("%d ", i) : 0;
    }
}

int main () 
{
    int target = 29;
    
    // Flipping one bit equals target
    flip_one (target);
    // Flipping n bits equals target
    flip_n (target);

    return 0;
}

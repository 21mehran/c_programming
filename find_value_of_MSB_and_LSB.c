// Find the value of the right most bit.
// Find the value of the left most bit.

#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main ()
{
    uint8_t num   = 20;          // 10100
    uint8_t right = 0;
    uint8_t left  = 0;
    
    right = num & (-num);        // returns 00100
    left  = num & (num - 1);     // returns 10000
   
    // left fails for numbers like 10 100 1000 10000

    printf ("Value of right most bit : %d\nValue of left most bit : %d\n", right, left);
    return 0;
}

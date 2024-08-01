// Find the value of the right most bit.
// Find the value of the left most bit.

#include <stdio.h>
#include <math.h>

int main ()
{
    int num   = 20;              // 10100
    int right = 0;
    int left  = 0;
    
    right = num & (-num);        // returns 00100
    left  = num & (num - 1);     // returns 10000
    
    printf ("Value of right most bit : %d\nValue of left most bit : %d\n", right, left);
    return 0;
}



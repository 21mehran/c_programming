// Multiple and divide a number using bitwise.
// Constraint : You can * and / by just multiples of 2 - 2,4..32,64..

#include <stdio.h>

int main () 
{
    int num = 12;
    
    // multiply 12 by 8 -> (2 ^ 3);
    printf ("%d ", num << 3);
    
    // Divide 12 by 4 --> (2 ^ 2);
    printf ("%d ", num >> 2);
    
    return 0;
}
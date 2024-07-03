// Reverse an 8 bit integer.

#include <stdio.h>

int main () 
{
    int num = 0b110101;
    int rev = 0;
    
    // Using the cool method I found on net.
    
    for (int i = 0; num != 0; i++) {
        
        rev = (rev << 1);
        rev = rev | num & 1;
        num = (num >> 1);
    
    }
    
    // Using the bit variable.

    int len = 6;
    
    for (int i = 0; num != 0; i++) {
        
        int bit = num & 1;
        rev = rev | (bit << ((len - 1) - i));
        num = num >> 1;
    }
    
    printf ("%d ", rev);

    return 0;
}

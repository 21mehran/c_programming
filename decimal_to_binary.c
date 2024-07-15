// Convert decimal to binary.

#include <stdio.h>
#include <math.h>

int main ()
{
    int num = 13;
    int bin = 0;
    
    // Using bitwise operations.
    
    for (int i = 0; i < 4; i++) {
        int bit = (num >> i) & 1;
        bin = bin + (bit * (pow (10, i)));
    }
    
    // Using normal operations.
    
    int i = 0;
    while (num) {
        
        int rem = num % 2;
        num = num / 2;
        bin = bin + (rem * pow (10, i));
        i++;
    }

    printf ("Binary Representation : %d", bin);
	return 0;
}

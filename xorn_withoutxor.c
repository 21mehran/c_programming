// Find XOR of n number without using xor operator.

#include <stdio.h>

int main () 
{
    
    for (int i = 0; i <= 10; i++) {
        
        if (i % 4 == 0) printf ("%d ", i);
        if (i % 4 == 1) printf ("%d ", 1);
        if (i % 4 == 2) printf ("%d ", i + 1);
    }

    return 0;
}

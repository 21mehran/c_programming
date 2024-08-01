// Find the position of the most significant bit.

#include <stdio.h>
#include <math.h>

int find_MSB (int);

int main ()
{
    int num = 512;
    int pos = 0;
    
    pos = find_MSB (num);
        
    // Using logarithm.   
    pos = log2 (num);
    
    printf ("%d ", pos);
    return 0;
}

// Find the position of the most Significant bit.

int find_MSB (int num)
{
    int pos = 0;
    
    while (num = num >> 1)
        pos++;
        
    return pos;
}

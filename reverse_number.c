// Reverse a number using Recursion.

#include <stdio.h>

int reverse (int num, int rev)
{
    if (!num)
        return rev;
    else
        reverse (num >> 1, (rev << 1) | (num & 1));
}

int main() 
{
    int num = 0b1011;
    int rev = 0;
    
    printf ("%d ", reverse (num, rev));
    return 0;
}

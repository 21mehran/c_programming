// Clear bits from MSB to position.

#include <stdio.h>

int clear (int num, int i) 
{
    int mask = (1 << i) - 1;
    return num & mask;
}

int main ()
{
    printf("%d ", clear (0b11111010, 4));
    return 0;
}

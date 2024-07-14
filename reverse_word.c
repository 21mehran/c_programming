// Reverse word using short.

#include <stdio.h>

int main ()
{
    int num = 0xABCDCDAB;
    unsigned short *ptr = (short *)&num;  // Short is signed by default (important);
    
    int temp = ptr[0];
    ptr[0] = ptr[1];
    ptr[1] = temp;
    
    printf ("%X", num);
}

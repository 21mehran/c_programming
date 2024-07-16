// Detect if two integers have opposite signs.

#include <stdio.h>

int main ()
{
    int num1 = -3;
    int num2 = 1;
    
    if ((num1 ^ num2) < 0)
        printf ("The two integers have opposite signs.");
    else
        printf ("The two integers have same signs.");
        
}

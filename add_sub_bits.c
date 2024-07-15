// Bitwise Addition and substraction.

#include <stdio.h>

int add (int a, int b)
{
    if (!b)
        return a;
    else
        add (a ^ b, (a & b) << 1);
}

int sub (int a, int b)
{
    return add (a, ~b + 1);
}

int main () 
{
    int num_1 = 20;
    int num_2 = 10;
    
    int (*fptr[]) (int, int) = {add, sub};
    
    printf ("Add = %d \nSub = %d\n", fptr[0] (num_1, num_2), fptr[1] (num_1, num_2));
    
    return 0;
}

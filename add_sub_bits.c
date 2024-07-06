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
    
    printf ("Add = %d \nSub = %d\n", add (num_1, num_2), sub (num_1, num_2));
    
    return 0;
}

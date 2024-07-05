// Count no. of set bits using Recurssion.
// Brian Kernigans Algorithm.

#include <stdio.h>

int set_bits (int num, int count) 
{
    if (!num)
        return count;
    else 
        set_bits (num & (num - 1), count + 1);
}

// Using 1 argument and static variable. 

int set_bits (int num)
{
    int static count = 0;

    if (!num)
        return count;
    else {
        count++;
        set_bits (num & (num - 1));
    }
}

int main()
{
    printf ("%d ", set_bits (15, 0));
    return 0;
}

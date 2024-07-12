// Check if the number is power of 2 and 4.

#include <stdio.h>

int power_of_two (int num)
{
    return ((num & (num - 1)) == 0);
}

int power_of_four (int num)
{
    return ((num - 1) % 3 == 0);
}

int main ()
{
    int num = 16;

    if (power_of_two (num)  && power_of_four (num))
        printf ("The number is power of 4");
}

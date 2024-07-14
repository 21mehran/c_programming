// Convert binary to decimal.

#include <stdio.h>

int power (int base, int expo)
{
    if (!expo)
        return 1;
    else
        return base * power (base, expo - 1);
}

int main ()
{
    int num = 10101;
    int dec = 0;
    int i = 0;
    
    while (num) {
        int rem = num % 10;
        num = num / 10;
        dec = dec + (rem * power (2, i++));
    }
    
    printf ("%d ", dec);
}

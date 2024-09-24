// ROMAN_TO_INTEGER

#include <stdio.h>

int roman_to_int (char* s) 
{
    int prev = 0;
    int dec = 0;

    while (*s) {

        int value = 0;
        switch (*s) {
            case 'I': value = 1; break;
            case 'V': value = 5; break;
            case 'X': value = 10; break;
            case 'L': value = 50; break;
            case 'C': value = 100; break;
            case 'D': value = 500; break;
            case 'M': value = 1000; break;
            default: -1;
        }
        
        dec = value > prev ? dec + (value - (2 *prev)) : dec + value;
            
        prev = value;
        s++;
    }
    return dec;
}

int main () 
{
    printf ("%d ", romanToInt ("MCMXCIV"));
    return 0;
}

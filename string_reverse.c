// String Reverse.

#include <stdio.h>
#include <string.h>

void string_reverse (char *src, char *dst) 
{
    while (*src++);
    src--;
    src--;
    while (*dst++ = *src--);
}

// Single array reversal.
void string_reverse (char src[], char dst[])
{
    printf ("\nOriginal : %s", src);
    
    for (int start = 0, end = strlen (src) - 1; start < end; start++, end--) {
        
        char temp  = src[start];
        src[start] = src[end];
        src[end] = temp;
    }
    
    printf ("\nReverse  : %s", src);
}

int main () 
{
    char string[] = "mehran";
    char reverse[10];
    
    printf ("Original : %s", string);
    string_reverse (string, reverse);
    printf ("\nReverse  : %s", reverse);
    
    return 0;
}

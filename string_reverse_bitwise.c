// Reverse a string using bitwise XOR.

#include <stdio.h>
#include <string.h>

void reverse (char *str) 
{
    int start = 0;
    int end = strlen (str) - 1;
    
    while (start < end) {
        str[start] = str[start] ^ str[end];
        str[end] = str[start] ^ str[end];
        str[start] = str[start] ^ str[end];
        
        start++;
        end--;
    }
}

int main () 
{
    char str[] = "mehran";

    reverse (str);
    
    printf ("%s ", str);
    return 0;
}

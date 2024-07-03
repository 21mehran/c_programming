// Reverse a 32 bit number without using bit manipulation.

#include <stdio.h>

int main () 
{
    int num = 0x12345678;
    char *ptr = (char *)&num;
    
    for (int start = 0, end = 3; start < end; start++, end--) {
        
        int temp = ptr[start];
        ptr[start] = ptr[end];
        ptr[end] = temp;
    }
    
    printf ("%x", num);

    return 0;
}

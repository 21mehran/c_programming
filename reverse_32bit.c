// Reverse a 32 bit number without using bit manipulation.

#include <stdio.h>

int main () 
{
    int num = 0x12345678;
    char *ptr = (char *)&num;
    
    // Reverse without using bit manipulation.
    
    for (int start = 0, end = 3; start < end; start++, end--) {
        
        int temp = ptr[start];
        ptr[start] = ptr[end];
        ptr[end] = temp;
    }
    
    int rev = 0;
    
    // Reverse using bit manipulation.
    
    for (int start = 24, end = 0; start > end; start = start - 8, end = end + 8) {
        
        int bit_start = (num >> start) & 0xFF;
        int bit_end = (num >> end) & 0xFF;

        rev = rev | (bit_end << start);
        rev = rev | (bit_start << end);
        
        printf ("%X %X %x\n", bit_start, bit_end, rev);
    }

    // Reverse without using a loop

    rev = (num & 0x000000FF) << 24 | 
	  (num & 0x0000FF00) << 8  |
	  (num & 0x00FF0000) >> 8  |
	  (num & 0xFF000000) >> 24; 

    printf ("\n%x", rev);

    return 0;
}

// Toggle odd bits in a number.

#include <stdio.h>

int main() 
{
   int num = 0b10101010;
   
   printf ("%d ", (num ^ 0x55));  // Toggle Odd bits.
   printf ("%d ", (num ^ 0xAA));  // Toggle Even bits.

   for (int i = 0; i < 8; i = i + 2)
        num = num ^ (1 << i);
        
   printf ("%d ", num);    
   
   return 0;
}

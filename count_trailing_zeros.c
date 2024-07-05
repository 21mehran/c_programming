// Count no. trailing zeros in a number.

#include <stdio.h>

// Using 2 arguments and recurssion.

int set_bits (int num, int count) 
{
   if ((num & 1) == 0) 
        return set_bits (num >> 1, count + 1); 
   else
        return count;
}

// Using recurssion and static variable;

int set_bits (int num) 
{
  static int count = 0;
    
  if ((num & 1) == 0) {
        count++;
        return set_bits (num >> 1); 
  } 
   
  return count;
}

int main()
{
    printf ("%d ", set_bits (10, 0));
    return 0;
}

// Count no. trailing zeros in a number.

#include <stdio.h>

// Using 2 arguments and recurssion.

int trailing_zeros (int num, int count) 
{
  if ((num & 1) == 0) 
        trailing_zeros (num >> 1, count + 1); 
  else
        return count;
}

// Using recurssion and static variable;

int trailing_zeros (int num) 
{
  static int count = 0;
    
  if ((num & 1) == 0) {
        count++;
        trailing_zeros (num >> 1); 
  } 
   
  return count;
}

int main()
{
    printf ("%d : Trailing zeros", trailing_zeros (8));
    return 0;
}
#include <stdio.h>
#include <math.h>

// Using Recursion 

int Most_sign_bit (int num, int pos) 
{
    if (!num)
        return pos;
    else
        Most_sign_bit (num >> 1, pos + 1);
}

// Without Recursion

int Most_sign_bit (int num, int pos) 
{
    while (num) {

        pos++;
        num = num >> 1;
    }
    
    return pos;
}

// Using logarithm - math.h

int Most_sign_bit (int num, int pos) 
{
    if (!num)
        return pos;
    else
        return (int) log2 (num);
}

int main ()
{

  int num = 128;
  int position = -1;  // Use position -1 for recursion else use 0; 
  
  printf ("Most significant bit is at position : %d", Most_sign_bit (num, position));
     
}

// Find the position of LSB and MSB

#include <stdio.h>
#include <math.h>

int main () 
{
    int num = 27;
    
    int lsb = num & (-num); // Here -num = ~num + 1;
    int msb = num;
    
    printf ("LSB is at posiiton : %d and value is %d \n", 
    (int) log2 (lsb), 1 << (int) log2 (lsb));
    printf ("MSB is at position : %d and value is %d \n",
    (int) log2 (msb), 1 << (int) log2 (msb));
    
    return 0;
}

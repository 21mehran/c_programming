// Iterative addition and substraction using bitwise.
// ~ of a positive num gives negative (num + 1);
// ~ of a negative num gives positive (num - 1);

#include <stdio.h>

int add (int a, int b)
{
    while (b) {
        a = -(~a);
        b--;
    }
    
    return a;
}

int sub (int a, int b)
{
    while (b) {
        
        a = ~(-a);
        b--;
    }
    return a;
}

int main () 
{
    int num1 = 20;
    int num2 = 12;

    // Using array of function pointers.
    int (*fptr[]) (int, int) = {add, sub};
    
    printf ("Sum = %d \n", fptr[0] (num1, num2));
    printf ("Sum = %d \n", fptr[1] (num1, num2));
    
    return 0;
}

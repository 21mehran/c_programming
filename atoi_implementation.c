// ATOI IMPLEMENTATION - CONVERTS STRING TO INT.

#include <stdio.h>

int atoi_implementation (char *num)
{
    int sign = 1;
    int result = 0;
    
    if (*num == '-' || *num == '+') {
        
        if (*num == '-')
            sign = -1;
            
        num++;    
    }
        
    while (*num && *num >= '0' && *num <= '9')  // ctype.h - isdigit () also can be used.
    {
        result = result * 10 + (*num - '0');
        num++;
    }
    
    return (result * sign);
}

int main ()
{
    char *str = "-122.23";
    printf ("%d ", atoi_implementation (str));
    
    return 0;
}


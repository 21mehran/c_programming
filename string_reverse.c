// Reverse a string recursivly.

#include <stdio.h>

// Reverse a string and store it into another array.

char *reverse (char *str, char *rev) 
{
    if (*str) {
        rev = reverse (str + 1, rev);  
        *rev = *str;             
        return rev + 1;                   
    } else 
        *rev = '\0';
}

// Print the string in reverse order.

void reverse_print (char *str) 
{
    if (*str) {
        reverse_print (str + 1);  
        printf ("%c", *str);                
    } 
}

int main () 
{
    char str[] = "Hello, World!";
    char rev[50];

    reverse (str, rev);    
    reverse_print (str);                    

    printf("\nOriginal string: %s\n", str);
    printf("Reversed string: %s\n", rev);

    return 0;
}


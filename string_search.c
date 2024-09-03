// strchr - Search a first occurance of a character in a string.

#include <stdio.h>

char *char_search (char *str, char ch) // It returns a pointer to the element.
{

    // int len = 0;
    // while (*str++ != ch && ++len);

    while (*str) {
        
        if (*str == ch)
            return str;
            
        str++;
    }    
}

int main ()
{
    char *str = "mehran_ahemad";
    char ch = 'h';
    
    char *position = char_search (str, ch);
    
    printf ("Character found at position : %d ", position - str);
    return 0;
}

// strrchr - Search for the last occurance of a character in a string.

#include <stdio.h>

char *char_search (char *str, char ch)    // It returns a pointer to the element.
{
    char *last_occurance = NULL;
    
    while (*str) {
        
        if (*str == ch)
           last_occurance = str;
            
        str++;
    }    

    return last_occurance;
}

int main ()
{
    char *str = "mehran_ahemad";
    char ch = 'h';
    
    char *position = char_search (str, ch);
    
    printf ("Character found at position : %d ", position - str);
    return 0;
}



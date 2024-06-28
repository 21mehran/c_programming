// strchr - Search a first occurance of a character in a string.

#include <stdio.h>

char *char_search (char *str, char ch) // It returns a pointer to the element.
{
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
    while (*str) {
        str++;
    }
    
    str--;
    
    while (*str) {
        
        if (*str == ch)
            return str;
            
        str--;
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



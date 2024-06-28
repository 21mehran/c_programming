// SEARCH FOR STRING WITHIN THE STRING.

#include <stdio.h>

char *string_string (char *haystack, char *needle)
{
    int needle_len = 0;
    char *start_pointer = needle;
    
    while (*needle) {		   // Calcualte the string length of needle.
        needle_len++;
        needle++;
    }
    
    while (*haystack) {
        
        needle = start_pointer;    // Bring back the pointer if the complete string is not matching.
        
        while (*needle && (*haystack == *needle)) {
            haystack++;
            needle++;
        }
        
        if (!*needle)             // If needle is \0 then return the location.
            return (haystack - needle_len);
            
        haystack++;    
    }
}

int main ()
{
   char *str1 = "mehranahemad";
   char *str2 = "ran";
   
   char *position = string_string (str1, str2);
   printf ("%c", position[0]);
}

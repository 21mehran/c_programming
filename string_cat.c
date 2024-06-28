// STRING CAT IMPLEMENTATION.

#include <stdio.h>

void string_cat (char *str1, char *str2)
{
    while (*str1) {
        str1++;
    }
    
    while (*str2) {
        *str1 = *str2;
        str1++;
        str2++;
    }
    
    *str1 = '\0';
}

int main ()
{
    char str1[20] = "mehran";  // Using arr[] because cannot modify string literal.
    char *str2 = "_ahemad";
    
    string_cat (str1, str2);
    printf ("%s", str1);
}

// STRING CAT (strncat)

#include <stdio.h>

void string_cat (char *str1, char *str2, int limit)
{
    while (*str1) {
        str1++;
    }
    
    int i = 0;
    while (*str2 && i < limit) {
        *str1 = *str2;
        str1++;
        str2++;
        i++;
    }
}

int main ()
{
    char str1[20] = "mehran";  // Using arr[] because cannot modify string literal.
    char *str2 = "_ahemad";
    int limit = 6;
    
    string_cat (str1, str2, limit);
    printf ("%s - custom function\n", str1);
}


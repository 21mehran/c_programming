// Implement string copy recursively.

#include <stdio.h>

void string_copy (char *src, char *dest)
{
    if (!*src)
        return;
    else {    
        *dest = *src;
        string_copy (src + 1, dest + 1);
    }
}

int main () 
{
    char *src = "Hello, World!";
    char dest[50];  

    string_copy (src, dest);

    printf("\nOriginal string: %s\n", src);
    printf("Copied string: %s\n", dest);

    return 0;
}


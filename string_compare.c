// STRING COMPARE (strcmp)

#include <stdio.h>

int string_compare (char *str1, char *str2)
{ 
    /* while (*str1++ == *str2++);
     
     * return (*(--str1) - *(--str2));
     */

    while (*str1) {
        
        if (*str1 != *str2)
            return (*str1 - *str2);
            
        str1++;
        str2++;
    }
}

int main ()
{
    char *str1 = "mehran";
    char *str2 = "mehrab";
    
    printf ("%d %d", string_compare (str1, str2), 'n' - 'b');
}

// STRING COMPARE (strncmp)

#include <stdio.h>

int string_compare (char *str1, char *str2, int limit)
{
    /*  while ((*str1++ == *str2++) && i++ < num - 1 );
     * 
     * return (*(--str1) - *(--str2));
     */

    int i = 0;
    while (*str1 && i < limit) {
        
        if (*str1 != *str2)
            return (*str1 - *str2);
            
        str1++;
        str2++;
        i++;
    }
    
    return 0;
}

int main ()
{
    char *str1 = "mehran";
    char *str2 = "mehrab";
    
    int limit = 6;
    
    printf ("%d ", string_compare (str1, str2, limit));
}

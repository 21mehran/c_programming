// Find the longest common prefix.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix (char** strs, int strsSize) 
{
    int prefix_count = 0;
    char res[10];
    
    if (strsSize == 1)
        res[0] = strs[0][0];
    
    for (int i = 1; i < strsSize; i++) {
        
        prefix_count = 0;
        
        for (int j = 0; j < strlen(strs[0]) && j < strlen(strs[i]); j++) {
            
            if (strs[0][j] == strs[i][j]) 
                prefix_count++;
        }
    }

    for (int i = 0; i < prefix_count; i++)
        res[i] = strs[0][i];
    
    return strdup (res);
}

int main ()
{
    char *str[] = { "flower", "flow", "flowight" };
    int size = sizeof (str) / sizeof (str[0]);
    
    char *result = longestCommonPrefix (str, size);
    printf ("%s ", result);
    
    free (result);
    return 0;
}

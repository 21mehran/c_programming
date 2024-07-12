// Find the longest palindromic substring using brute force.
// Substring should be contagious.
// Subsequence is not necessarily contagious.

#include <stdio.h>
#include <string.h>

void reverse_string(char *str, char *rev)
{
    int i, j;
    int len = strlen(str);
    
    for (i = 0, j = len - 1; i < len; i++, j--)
        rev[i] = str[j];

    rev[len] = '\0';
}

int check_palindrome(char *str, char *rev)
{
    reverse_string(str, rev);

    if (strcmp(str, rev) == 0)
        return strlen(rev);
    
    return 0;
}

int create_substrings(char *main_str, char *rev)
{
    int start = 0;
    int end = strlen (main_str);
    int largest = 0;
    char largest_palindrome[100] = {0};
   
    for (int i = start; i < end; i++) {
        for (int j = i, k = 1; j < end; j++, k++) {
            
            char str[10] = {0};
            strncpy(str, main_str + i, k);

            int len = check_palindrome(str, rev);
            if (len > largest) {
                largest = len;
                strcpy(largest_palindrome, str);
            }
        }
    }
   
    printf("Largest palindrome: %s of length %d\n", largest_palindrome, largest);
}

int main()
{
    char name[] = "asdkabbak";
    char rev[100] = {0};
    create_substrings(name, rev);

    return 0;
}


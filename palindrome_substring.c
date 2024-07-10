// Find the longest palindromic substring.
// Substring should be contagious.
// Subsequence is not necessarily contagious.

#include <stdio.h>
#include <string.h>

int check_palindrome (char *str)
{
    char rev[10];
    int i = 0;
    int j = strlen (str) - 1;
    
    while (str[i]) {
        rev[i] = str[j];
        i++;
        j--;
    }
    
    rev[i] = '\0';
    
    if (strcmp (str, rev) == 0)
        return strlen (rev) - 1;
}

int main () 
{
   char name[] = "abcbab";
   char largest_palindrome[10];

   int start = 0;
   int end = strlen (name);
   int largest = 0;
   
   for (int i = start; i < end; i++) {
       
      int len = 0; 
      char str[10] = {0};
      
      for (int j = start; j < end; j++) {
          str[j] = name[j];
      }
      
      len = check_palindrome (str);
      if (len > largest) {
        largest = len; 
        strcpy (largest_palindrome, str);
      }
      
      end--;
   }
    
   printf ("%s is the largest palindrome of length %d", largest_palindrome, largest);
    
   return 0;
}

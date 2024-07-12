// Print the longest palindromic substring using dynamic programming.

#include <stdio.h>
#include <string.h>

void longest_palindromic_substring (char *str) 
{
    int n = strlen (str);
    int matrix[n][n];
    memset (matrix, 0, sizeof(matrix));

    int maxLength = 1;
    int start = 0;

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) 
        matrix[i][i] = 1;

    // Check for substring of length 2
    for (int i = 0; i < n - 1; i++) {
        
        if (str[i] == str[i + 1]) {
            matrix[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    for (int len = 2; len < n; len++) {
        for (int j = len, i = 0; j < n; j++, i++) {
            
            if (matrix[i + 1][j - 1] && str[i] == str[j]) {
                matrix[i][j] = 1;
    
                if (len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }
        }
    }

    printf("Longest palindromic substring is: ");
    for (int i = start; i <= start + maxLength; i++) 
        printf("%c", str[i]);
}

int main() 
{
    char str[] = "nabacaba";
    longest_palindromic_substring (str);

    return 0;
}


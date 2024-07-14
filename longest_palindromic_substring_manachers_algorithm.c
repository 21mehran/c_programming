#include <stdio.h>
#include <string.h>

void longest_palindrome (char *str, char *result) 
{
    int len = strlen(str);

    // Preprocess the string
    char str_hash[2 * len + 3];
    int arr[2 * len + 3];
    memset(str_hash, 0, sizeof(str_hash));
    memset(arr, 0, sizeof(arr));

    int center = 0, right = 0;  // center and right edge of the current palindrome
    int i_mirror, maxLen = 0, centerIndex = 0;

    // Processing the string
    str_hash[0] = '^';
    for (int i = 0; i < len; i++) {
        str_hash[2 * i + 1] = '#';
        str_hash[2 * i + 2] = str[i];
    }
    str_hash[2 * len + 1] = '#';
    str_hash[2 * len + 2] = '$';

    for (int i = 1; i < 2 * len + 2; i++) {
        i_mirror = 2 * center - i;

        // When right boundary exceeds i
        if (right > i)
            arr[i] = (right - i < arr[i_mirror]) ? (right - i) : arr[i_mirror];
        
        // Comparing elements around the center
        while (str_hash[i + 1 + arr[i]] == str_hash[i - 1 - arr[i]])
            arr[i]++;
    
        // Move the center    
        if (i + arr[i] > right) {
            center = i;
            right = i + arr[i];
        }
        
        if (arr[i] > maxLen) {
            maxLen = arr[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;
    strncpy(result, str + start, maxLen);
    result[maxLen] = '\0';
}

int main () 
{
    char s[] = "aaaababcbaba";
    char result[20];
    
    longest_palindrome(s, result);
    printf("Longest palindromic substring is: %s\n", result);
    return 0;
}


// Reverse the order of the words in a string.

#include <stdio.h>

int main () 
{
    char *text = "How are you";
    char sentence[10][10];  
    int word = 0, i = 0;

    while (*text) {
        if (*text != ' ') {
            sentence[word][i++] = *text;
        } else {
            sentence[word][i] = '\0';      // Null-terminate the word
            word++;                        // Move to the next word
            i = 0;                         // Reset character index for the next word
        }
        text++;
    }
    
    sentence[word][i] = '\0';             // Null-terminate the last word
    
    while (word >= 0) 
        printf("%s ", sentence[word--]);

    return 0;
}

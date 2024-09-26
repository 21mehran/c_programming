// Find the longest common prefix in the array of strings.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABETS 26

struct node 
{
    struct node *child[ALPHABETS];      // Each child will have a 26 pointer.
    bool end;
};

struct node *create ()
{
    struct node *ptr = malloc (sizeof (struct node));
    ptr->end = true;

    for (int i = 0; i < ALPHABETS; i++)
        ptr->child[i] = NULL;

    return ptr;
}

void insert (struct node *root, char *word) 
{
    struct node *ptr = root;

    while (*word) {
        int index = *word - 'a';

        if (ptr->child[index] == NULL)        // Create a node at that particular index.
            ptr->child[index] = create ();

        ptr = ptr->child[index];
        word++;
    }

    ptr->end = true;
}

void print (struct node* root, char* buffer, int length) 
{
    struct node* current = root;
    int index = 0;

    while (current) {

        int count = 0;  
        int prefix_found = 0;

        for (int i = 0; i < ALPHABETS; i++) {

            if (current->child[i] != NULL) {
                count++;
                index = i;
                buffer[length++] = 'a' + i;     // Insert the char in buffer.

                if (count > 1) {                // Checking a node with more than 1 child.
                    prefix_found = 1;           // More than 1 child then the string differs here.
                    break;  
                }    
            }
        }

        if (prefix_found)                       // If we found a child with multiple childs then break;
            break;

        current = current->child[index];         
    }

    buffer[length - 2] = '\0';                  // Since we already one step ahead we need to do -2
}


int main () 
{
    struct node *root = create ();

    char *words[] = {"flower", "flow", "flight"};
    int size = sizeof (words) / sizeof (words[0]);

    for (int i = 0; i < size; i++)
        insert (root, words[i]);

    char result[100];
    int length = 0;
    print (root, result, length);

    printf ("%s ", result);

    return 0;
}

// Binary tree - Find common prefix between two strings.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
};

struct node* create_node (char data) 
{
    struct node* ptr = malloc (sizeof (struct node));

    ptr->data = data;
    ptr->left = ptr->right = NULL;
    return ptr;
}

struct node* insert (struct node* root, char data)
{
    if (root == NULL) {
        root = create_node (data);
        return root;
    }

    struct node *current = root;
    struct node *trail = NULL;

    while (current != NULL) {
        trail = current;
        current = current->left;
    }

    trail->left = create_node (data);
    return root;
}

void find_string (struct node* root, char data[]) 
{
    int i = 0;
    
    while (root) {
        
        if (data[i++] == root->data)
            printf("%c ", root->data);   
            
        root = root->left;    
    }
}

int main ()
{
    struct node* root = NULL;
    
    char name_1[] = "mehran";
    char name_2[] = "mehrein";
    
    int i = 0;
    while (name_1[i]) 
        root = insert (root, name_1[i++]);
    
    printf("Common prefix between two strings\n");
    find_string (root, name_2);

    return 0;
}


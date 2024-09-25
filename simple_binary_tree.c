// Binary tree - insertion nad traversel

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create_node (int data) 
{
    struct node* ptr = malloc (sizeof (struct node));

    ptr->data = data;
    ptr->left = ptr->right = NULL;
    return ptr;
}

struct node* insert (struct node* root, int data)
{
    if (root == NULL) {
        root = create_node (data);
        return root;
    }

    struct node *current = root;
    struct node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (data < parent->data)
        parent->left = create_node (data);
    else
        parent->right = create_node (data);

    return root;
}

void traversal (struct node* root) {
    if (root == NULL)
        return;
        
    traversal (root->left);
    printf("%d ", root->data);
    traversal (root->right);
}

int main ()
{
    struct node* root = NULL;

    root = insert(root, 50);
    insert (root, 30);
    insert (root, 20);
    insert (root, 40);
    insert (root, 70);
    insert (root, 60);
    insert (root, 80);

    printf("Inorder traversal of the binary tree: ");
    traversal (root);

    return 0;
}


// Given a pointer to a node how do you delete it.
// Recursively printing the list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void free_list (struct node *head) 
{
    struct node *ptr = head;
    
    while (ptr != NULL) {
        head = head->link;
        free (ptr);
        ptr = head;
    }
}

void print_list (struct node *head) 
{
    struct node *ptr = head;

    if (ptr == NULL)
        return;
    else {
        printf ("%p %d\n", ptr, ptr->data);
        return print_list (ptr->link);
    }
}

void delete_node (struct node *delete_pointer)
{
    struct node *ptr = delete_pointer->link;
    delete_pointer->data = ptr->data;
    delete_pointer->link = ptr->link;
    free (ptr);
}

struct node *insert_start (struct node *head, int data)
{
    struct node *ptr = malloc (sizeof (struct node));
    
    if (head == NULL) {
        head = ptr;
        head->data = data;
        head->link = NULL;
    } else {
        ptr->link = head;
        ptr->data = data;
        head = ptr;
    }
    return head;
}

int main ()
{
    struct node *head = NULL;
    
    for (int i = 1; i < 10; i++)
        head = insert_start (head, i * 10);
        
    printf ("Original Linked list:\n");
    print_list (head);
    
    struct node *ptr = head;
    delete_node (ptr->link->link->link);
    
    printf ("\nAfter deleting Linked list:\n");
    print_list (head);
    free_list (head);
}

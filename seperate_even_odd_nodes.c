// Seperate even odd nodes.
// 1. Insert even nodes in seperate linkedlist.
// 2. Delete even nodes from the original linkedlist.
// 3. What remains in original linkedlist is Odd nodes.

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
        ptr = head->link;
        free (head);
        head = ptr;
    }
}

void print_list (struct node *head) 
{
    struct node *ptr = head;
    
    while (ptr != NULL) {
        printf ("%p %d\n", ptr, ptr->data);
        ptr = ptr->link;
    }
}

struct node *delete_even (struct node *head, struct node *even) 
{
    struct node *ptr = head;
    struct node *temp = head;
    struct node *hold_even = NULL;
    
    while (ptr && ptr->link) {
        
        even = malloc (sizeof (struct node));
        temp = ptr->link;
        ptr->link = temp->link;
        
        // Storing and iterating the even linkedlist.
        even->data = temp->data;
        even->link = hold_even;
        hold_even = even;
        
        // Deleting the even nodes after copying then in even.
        free (temp);
        ptr = ptr->link;
    }
    
    return even;
}

struct node *insert_start (struct node *head, int data)
{
    struct node *ptr = malloc (sizeof (struct node));
    
    ptr->data = data;
    ptr->link = head;
    head = ptr;
    
    return head;
}

int main ()
{
    struct node *head = NULL;
    struct node *even = NULL;
    
    for (int i = 1; i < 10; i++)
        head = insert_start (head, i * 10);
        
    printf ("Original linked list:\n");
    print_list (head);
    
    printf ("\nOriginal linked list after deleteing even nodes:\n");
    even = delete_even (head, even);
    print_list (head);
    
    printf ("\nSeperate linked list with even nodes:\n");
    print_list (even);
    
    free_list (head);
    free_list (even);
}

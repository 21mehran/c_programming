// Delete the middle of the linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *link;
};

void print_list (struct node *head)
{
    struct node *ptr = head;
    
    while (ptr) {
        
        printf ("%p %d\n", ptr, ptr->data);
        ptr = ptr->link;
    }
}

void free_list (struct node *head)
{
    struct node *temp = head;
    
    while (head) {
        
        head = head->link;
        free (temp);
        temp = head;
    }
}

struct node *delete_mid (struct node *head)
{ 
    struct node *slow  = head;
    struct node *fast = head->link->link;
    struct node *temp = NULL;
    // Inorder to delete the mid node I need to be 1 node behind it.
    
    while (fast && fast->link) {
        
        fast = fast->link->link;
        slow = slow->link;
    }

    // This method does not free the deleted node.
    // slow->link = slow->link->link; 
    
    temp = slow->link;
    slow->link = temp->link;
    free (temp);
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
    
    for (int i = 10; i <= 110; i = i + 10)
        head = insert_start (head, i);
        
    printf ("Original Linked list:\n");
    print_list (head);
    
    printf ("\nAfter deleting middle of Linked list:\n");
    head = delete_mid (head);
    print_list (head);
    
    free_list (head);
    return 0;
}

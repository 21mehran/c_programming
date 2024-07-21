// Delete the kth element from the starting of the linked list.
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

void delete_kth_start (struct node *head, int k)
{
    int count = 1;
    struct node *ptr = head;
    struct node *trail_ptr = NULL;
    
    while (ptr && count != k) {
        
        trail_ptr = ptr;
        ptr = ptr->link;
        count++;
    }
    
    trail_ptr->link = ptr->link;
    free (ptr);    
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
    
    for (int i = 1; i < 10; i++)
        head = insert_start (head, i * 10);
        
    printf ("Original Linked list:\n");
    print_list (head);
    
    struct node *ptr = head;
    delete_kth_start (ptr, 3);
    
    printf ("\nAfter deleting the Kth element:\n");
    print_list (head);
    free_list (head);
}

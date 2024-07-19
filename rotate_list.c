// Rotate the linked list.

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
    
    printf ("\n");
}

struct node *rotate_list (struct node *head) 
{
    struct node *ptr = head;
    struct node *temp = NULL;
    
    while (ptr && ptr->link) {
        
        temp = ptr;
        ptr = ptr->link;
    }
    
    ptr->link = head;
    temp->link = NULL;
    
    return ptr;
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
    
    printf ("Original list \n");
    print_list (head);
    
    printf ("Rotated list\n");
    head = rotate_list (head);
        
    print_list (head);
    free_list (head);
}

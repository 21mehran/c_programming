// Circular | Linear linked list - Find Middle Node.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void free_list (struct node *head) 
{
    struct node *ptr = head;
    
    do {
        ptr = head->link;
        free (head);
        head = ptr;
    } while (ptr != NULL && ptr != head);
}

void print_list (struct node *head) 
{
    struct node *ptr = head;
    
    do {
        printf ("%p %d\n", ptr, ptr->data);
        ptr = ptr->link;
    }  while (ptr != NULL && ptr != head);
}

struct node *mid_list (struct node *head) 
{
    struct node *fast = head;
    struct node *slow = head;
    
    do {
        slow = slow->link;
        fast = fast->link->link;
    } while ((fast != NULL && fast->link != NULL) &&
             (fast != head && fast->link != head));
    
    return slow;
}

struct node *insert_end (struct node *head, int data)
{
    struct node *ptr = malloc (sizeof (struct node));
    
    ptr->data = data;
    ptr->link = NULL;
    if (head)
        head->link = ptr;
    head = ptr;
    
    return head;
}

void check_linklist_type (struct node *head) {
    
    struct node *ptr = head;

    while (ptr->link != NULL && ptr->link != head) 
        ptr = ptr->link;
        
    if (ptr->link == head)
        printf ("Circular linked list!\n\n");
    else
        printf ("Linear linked list!\n\n");
}

int main ()
{
    struct node *head = NULL;
    struct node *start = NULL;
    
    head = insert_end (head, 10);
    start = head;
    
    for (int i = 2; i < 10; i++)
        head = insert_end (head, i * 10);
       
    head->link = start;    
        
    check_linklist_type (start);
        
    printf ("Middle of the linked list:\n");
    struct node *mid = mid_list (start);
    printf ("%p %d\n\n", mid, mid->data);
    
    printf ("Original Linked list:\n");
    print_list (start);
    free_list (start);
}

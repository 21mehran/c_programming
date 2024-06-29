// Reverse the Linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void free_list (struct node *head) 
{
    struct node *ptr = head;
    
    while (ptr) {
        ptr = head->link;
        free (head);
        head = ptr;
    }
}

void print_list (struct node *head) 
{
    struct node *ptr = head;
    
    while (ptr) {
        printf ("%p %d\n", ptr, ptr->data);
        ptr = ptr->link;
    }
    
    printf ("\n");
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

struct node *reverse_list (struct node *head)
{
    struct node *prev = NULL;
    struct node *next = NULL;
    
    while (head) {
        next = head->link;
        head->link = prev;
        
        prev = head;
        head = next;
    }
    
    return prev;
}

int main ()
{
    struct node *head = NULL;
    
    for (int i = 1; i < 10; i++)
        head = insert_start (head, i * 10);
        
    printf ("Original Linked list\n");    
    print_list (head);
    
    printf ("Reversed Linked list\n");    
    struct node *reverse = reverse_list (head);
    print_list (reverse);
    
    free_list (head);
}

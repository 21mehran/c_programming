// Reverse a single linked list.

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

struct node* reverse (struct node *head)
{
    struct node *prev = NULL;
    struct node *next = NULL;

    while (head) {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

struct node* reverse (struct node* head) {
    
    if (head == NULL || head->link == NULL) 
        return head;
    
    struct node* new_head = reverse(head->link);

    head->link->link = head;  
    head->link = NULL;        

    return new_head;         
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
    
    printf ("Reversed list\n");
    head = reverse (head);
        
    print_list (head);
    free_list (head);
}

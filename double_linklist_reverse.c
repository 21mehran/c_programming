// Reverse a double linked list.
// 1. Pointer Manipulation. 
// 2. Data Manipulation.

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *prev;
  struct node *next;
};

void free_list (struct node *head) 
{
    struct node *ptr = head;
    
    while (ptr) {
        ptr = ptr->next;
        free (head);
        head = ptr;
    }
}

void print_list (struct node *head) 
{
    struct node *ptr = head;
    
    while (ptr) {
        printf ("%p %d\n", ptr, ptr->data);
        ptr = ptr->next;
    }
    printf ("\n");
}

void print_reverse (struct node *head) 
{
    struct node *ptr = head;
    
    while (ptr->next) {
        ptr = ptr->next;
    }

    while (ptr) {
        printf ("%p %d\n", ptr, ptr->data);
        ptr = ptr->prev;
    }
    
    printf ("\n");
}

// Reverse list using pointer manipulation.
struct node *actually_reverse (struct node *head) 
{
    struct node *ptr = head;
    
    while (ptr) {

        struct node *temp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = temp;

        if (ptr->prev == NULL)
            break;
            
        ptr = temp;
    }

    return ptr;
}

// Reverse list using data manipulation.
struct node *actually_reverse (struct node *head)
{
    struct node *start = head;
    struct node *end = NULL;

    while (start->next) {
        start = start->next;
    }

    end = start; 
    start = head;
    
    while (start && end && start > end)
    {
        int temp = start->data;
        start->data = end->data;
        end->data = temp;

        start = start->next;
        end = end->prev;
    }
    
    return head;    
}

struct node *insert_start (struct node *head, int data)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    
    if (head != NULL) {
        head->prev = ptr;
    }
    
    head = ptr;
    return head;
}

int main ()
{
    struct node *head = NULL;
    
    for (int i = 1; i < 10; i++)
        head = insert_start (head, i * 10);
        
    printf ("Original linked list\n");
    print_list (head);
    
    printf ("Original linked list in reverse order\n");
    print_reverse (head);
    
    printf ("Actually reverse a linked list\n");
    struct node *rev_pointer = actually_reverse (head);
    print_list (rev_pointer);
    
    free_list (head);
    return 0;
}

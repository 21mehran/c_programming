// Reverse a double linked list.

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

struct node *insert_start (struct node *head, int data)
{
    struct node *ptr = malloc (sizeof (struct node ));
    
    if (head == NULL) {
        head = ptr;
        head->data = data;
        head->prev = NULL;
        head->next = NULL;
    } else {
        ptr->data = data;
        ptr->prev = NULL;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
    
    return ptr;
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

// Implement Queue using Stack (linked list).

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

void pop (struct node *delete_pointer)
{
    struct node *ptr = delete_pointer->link;
    delete_pointer->data = ptr->data;
    delete_pointer->link = ptr->link;
    free (ptr);
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

struct node *insert_into_stack (struct node *head, int data)
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
    struct node *stack_1 = NULL;
    struct node *stack_2 = NULL;
    
    for (int i = 1; i < 10; i++) 
        stack_1 = insert_into_stack (stack_1, i * 10);
    
    struct node *ptr = stack_1;
    
    while (ptr) {
        stack_2 = insert_into_stack (stack_2, ptr->data);
        ptr = ptr->link;
    }
    
    printf ("Original Linked list:\n");
    print_list (stack_1);
        
    printf ("Restacked Linked list:\n");
    print_list (stack_2);
    
    pop (stack_2);
    pop (stack_2);
    
    printf ("After deletion Linked list:\n");
    print_list (stack_2);
    
    free_list (stack_1);
    free_list (stack_2);
}

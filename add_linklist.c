// Add two linked list and store the result in the third list.

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

struct node *resulting_list (struct node *stack_1, struct node *stack_2, struct node *result)
{
    struct node *ptr = NULL;
    
    while (stack_1 && stack_2) {
        
        result = malloc (sizeof (struct node));
        result->data = stack_1->data + stack_2->data;
        result->link = ptr;
        
        ptr = result;
        
        stack_1 = stack_1->link;
        stack_2 = stack_2->link;
    }
    
    return result;
}

int main ()
{
    struct node *stack_1 = NULL;
    struct node *stack_2 = NULL;
    struct node *result = NULL;
    
    for (int i = 1; i < 10; i++) 
        stack_1 = insert_into_stack (stack_1, i * 10);
        
    printf ("Linked list 1:\n");
    print_list (stack_1);
        
    for (int i = 1; i < 10; i++) 
        stack_2 = insert_into_stack (stack_2, i * 10);    
        
    printf ("Linked list 2:\n");
    print_list (stack_2);
    
    result = resulting_list (stack_1, stack_2, result);
    
    printf ("Result = Linked list 1 + Linked list 2:\n");
    print_list (result);
    
    free_list (stack_1);
    free_list (stack_2);
    free_list (result);
}

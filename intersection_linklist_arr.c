// Find the intersection or common node between 2 linked lists using array of struct pointer.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

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
    
    printf ("\n");
}


struct node *find_intersection_node (struct node *struct_array[], struct node *stack_1, struct node *stack_2)
{
    struct node *ptr = stack_1;
    
    for (int i = 0; ptr && i < SIZE; i++) {
        struct_array[i] = malloc (sizeof (struct node));
        struct_array[i] = ptr;
        ptr = ptr->link;
    }
    
    ptr = stack_2;
    
    
    while (ptr) {
        
        for (int i = 0; i < SIZE; i++) {
            
            if (ptr == struct_array[i]) 
                return ptr;
        } 
        ptr = ptr->link;    
    }
    
    for (int i = 0; i < SIZE;)
        free_list (struct_array[i]);
    
    return NULL;
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
    struct node *stack_1 = NULL;
    struct node *stack_2 = NULL;
    struct node *intersection = NULL;
    struct node *struct_array[SIZE];
    
    for (int i = 1; i < 10; i++)
        stack_1 = insert_start (stack_1, i * 10);
        
    for (int i = 5; i < 10; i++)
        stack_2 = insert_start (stack_2, i * 5);
        
    printf ("First Linked list:\n");
    print_list (stack_1);
    
    printf ("\nSecond Linked list:\n");
    print_list (stack_2);
    
    // Make the intersection at 4 so that we can detect it.
    
    intersection = stack_1->link->link->link;
    stack_2->link->link = intersection;
    
    printf ("\nFirst Linked list : After intersection\n");
    print_list (stack_1);
    
    printf ("\nSecond Linked list : After intersection\n");
    print_list (stack_2);
    
    intersection = find_intersection_node (struct_array, stack_1, stack_2);
    
    if (intersection) 
        printf("\nIntersection is at node: %p\n", intersection);
    else
        printf ("No intersection\n");
    
    free_list (stack_1);
    // free_list (stack_2);
}

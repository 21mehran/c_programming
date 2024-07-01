// Find the intersection or common node between 2 linked lists.

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

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

void insert_hashtable (struct node *hashtable[], struct node *this_node)
{
    int index = (unsigned long) this_node % TABLE_SIZE;
    /* Linear Probing: This is a simple collision resolution technique where if a collision occurs (i.e., the calculated index is already occupied), the function linearly searches for the next available slot in the hash table until an empty slot is found. */
    
    while (hashtable[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
    }
   
    hashtable[index] = this_node;
}

int search_hashtable (struct node *hashtable[], struct node *this_node)
{
    int index = (unsigned long) this_node % TABLE_SIZE;
    while (hashtable [index] != NULL) {
        if (hashtable [index] == this_node)
            return 1;
            
        index = (index + 1) % TABLE_SIZE;
    }
    
    return 0;
}

struct node *find_intersection_node (struct node *stack_1, struct node *stack_2)
{
    struct node *hashtable[TABLE_SIZE] = { NULL };
    struct node *ptr = stack_1;
    
    while (ptr) {
        insert_hashtable (hashtable, ptr);
        ptr = ptr->link;
    }
    
    ptr = stack_2;
    while (ptr) {
        if (search_hashtable (hashtable, ptr)) 
            return ptr;
            
        ptr = ptr->link;    
    }
    
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
    
    intersection = find_intersection_node (stack_1, stack_2);
    
    if (intersection)
        printf("\nIntersection is at node: %p\n", intersection);
    else
        printf ("No intersection\n");
    
    free_list (stack_1);
    // free_list (stack_2);
}

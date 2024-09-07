// Resolving and Detecting a loop in a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

void print_list (struct node *head)
{
    struct node *ptr = head;
    
    while (ptr) {
        printf ("%p %d\n", ptr, ptr->data);
        ptr = ptr->link;
    }
}

void free_list (struct node *head)
{
    struct node *temp = head;
    
    while (temp) {
        temp = temp->link;
        free (head);
        head = temp;
    }
}

struct node *insert_start (struct node *head, int data)
{
    struct node *ptr = malloc (sizeof (struct node));
    ptr->data = data;
    ptr->link = head;
    head = ptr;
    
    return head;
}

// Find loop start.

struct node *loop_start (struct node *fast, struct node *head)
{
    struct node *slow = head;

    while (slow->link != fast->link) {
        slow = slow->link;
        fast = fast->link;
    }

    return fast;
}

// Floyd Cycle detection algorithm.

struct node *detect_loop (struct node *head)
{
    struct node *fast = head;
    struct node *slow = head;
    
    while (fast->link) {
        
        slow = slow->link;
        fast = fast->link->link;
        
        if (fast == slow)
            return slow;
    }
    
    return NULL;
}

// Resolving the loop.

void resolve_loop (struct node *start_node, struct node *head)
{
    start_node->link = NULL;
}

int main ()
{
    struct node *head = NULL;
    struct node *loop = NULL;
    struct node *start_node = NULL;
    
    for (int i = 10; i < 110; i = i + 10)
        head = insert_start (head, i);
        
    // Creating node at 70    
        
    head->link->link->link->link->link->link->link->link->link->link = head->link->link->link;
        
    if (loop = detect_loop (head))
        printf ("\nLoop detected!\n");
    else
        printf ("No loop found\n");
        
    // Printing the start of the loop.    
        
    start_node = loop_start (loop, head);
    printf ("Start point of the loop = %d\n\n", start_node->link->data);

    // Resolving the loop.   
    
    resolve_loop (start_node, head);
        
    printf ("List After resolving the loop/cycle.\n");    
    print_list (head);    
    free_list (head);
}

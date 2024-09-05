// Insert the element in correct order.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void free_list (struct node *head)
{
    struct node *temp = head;
    
    while (head) {
        temp = head->link;
        free (head);
        head = temp;
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

void delete_node (struct node *target) 
{
   struct node *temp = target->link;
   target->data = temp->data;
   target->link = temp->link;
   
   free (temp);
}

struct node *insert_start (struct node *head, int data) 
{
    struct node *ptr = malloc (sizeof (struct node));
    ptr->data = data;
    ptr->link = head;
    head = ptr;
    
    return head;
}

struct node *insert_end (struct node *head, int data)
{
    struct node *ptr = malloc (sizeof (struct node));
    ptr->data = data;
    ptr->link = NULL;
    head->link = ptr;
    
    head = ptr;
    return head;
}

struct node *insert_in_order (struct node *head, int target)
{
    struct node *new_node = malloc(sizeof(struct node));
    struct node *ptr = head;
    struct node *prev = NULL;
    
    new_node->data = target;

    if (head == NULL || target <= head->data) {
    
        new_node->link = head;
        head = new_node;
        return head; 
    }

    while (ptr && target >= ptr->data) {
        
        prev = ptr;
        ptr = ptr->link;
    }
    
    new_node->link = ptr;
    prev->link = new_node;
    
    return head;
}

int main () 
{
    struct node *head = NULL;
    
    for (int i = 100; i >= 10; i = i - 10)
        head = insert_start (head, i);
    
    head = insert_in_order (head, 115);
    print_list (head);
    
    free_list (head);
    return 0;
}

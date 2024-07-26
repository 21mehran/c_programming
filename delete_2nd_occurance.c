// Delete the second occurance of a given numbe in a linked list.
// 1. Check if the given number exists 
// 2. Check if the given number occurs twice.
// 3. The second occurance can be anywhere even last node.
// Alternate way of solving this would be to reverse the list and delete first occurance.

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
}

struct node *find_second_occurance (struct node *head, int num) 
{
    struct node *ptr = head;
    struct node *target = NULL;
    
    while (ptr) {
        
        if (ptr->data == num) 
                target = ptr;
            
        ptr = ptr->link;
    }
    
    return target;
}

void delete_node (struct node *delete_pointer, struct node *head)
{
    // Delete the last node.
    
    if (delete_pointer->link == NULL) {
        struct node *ptr = head;
        
        while (ptr->link != delete_pointer) 
            ptr = ptr->link;
        
        ptr->link = NULL;
        free (delete_pointer);
        return;
    }    
 
    struct node *ptr = delete_pointer->link;   
    delete_pointer->data = ptr->data;
    delete_pointer->link = ptr->link;
    free (ptr);
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
    
    head = insert_start (head, 10);
    head = insert_start (head, 20);
    head = insert_start (head, 30);
    head = insert_start (head, 40);
    head = insert_start (head, 50);
    head = insert_start (head, 30);
    head = insert_start (head, 60);
    head = insert_start (head, 70);
        
    printf ("Original Linked list:\n");
    print_list (head);

    struct node *target = find_second_occurance (head, 30);    
    delete_node (target, head);

    printf ("\nAfter deleting Linked list:\n");
    print_list (head);
    free_list (head);
}

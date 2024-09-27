// Merge two sorted linked list.

#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int data;
  struct node *link;
};

void print_list (struct node *head) 
{
    if (head) {
        printf ("%d %p\n", head->data, head);
        print_list (head->link);
    }
}

struct node *insert_end (struct node *head, int data)
{
    struct node *ptr = malloc (sizeof (struct node));
    ptr->data = data;
    ptr->link = NULL;
    
    if (head)
        head->link = ptr;
        
    return ptr;
}

struct node *create_list_1 ()
{
    struct node *head = NULL;
    struct node *start = NULL;
    head = insert_end (head, 1);
    start = head;
    
    head = insert_end (head, 2);
    head = insert_end (head, 4);
    
    return start;
}

struct node *create_list_2 ()
{
    struct node *head = NULL;
    struct node *start = NULL;
    head = insert_end (head, 0);
    start = head;
    
    head = insert_end (head, 3);
    head = insert_end (head, 4);
    
    return start;
}

struct node *merge (struct node *first, struct node *second)
{
    struct node *ptr = malloc (sizeof (struct node));
    struct node *head = NULL;
    
    if (first->data <= second->data) {  // Head changing
        ptr->data = first->data;
        ptr->link = second;
        second = head = ptr;
        second = second->link;
        first = first->link;
    } else
        head = second;
    
    while (second && first) {
        
        if (first->data <= second->link->data) {
            struct node *ptr = malloc (sizeof (struct node));
            ptr->data = first->data;
            ptr->link = second->link;
            second->link = ptr;
            first = first->link;
        }
        
        second = second->link;
    }
    
    return head;
}

int main ()
{
    struct node *start_1 = create_list_1 ();
    struct node *start_2 = create_list_2 ();
    
    printf ("List one :\n");
    print_list (start_1);
    printf ("\n");
    printf ("List two :\n");
    print_list (start_2);
    
    printf ("\nResulting list :");
    struct node *result = merge (start_1, start_2);
    printf ("\n");
    print_list (result);
}


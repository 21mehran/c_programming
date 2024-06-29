// Find Middle of a Linked List.

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
}

struct node *mid_list (struct node *head) 
{
    struct node *fast = head;
    struct node *slow = head;
    
    while (fast && fast->link) {
        
        slow = slow->link;
        fast = fast->link->link;
    }
    
    return slow;
}

struct node *insert_start (struct node *head, int data)
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
    struct node *head = NULL;
    
    for (int i = 1; i < 10; i++)
        head = insert_start (head, i * 10);
        
    struct node *mid = mid_list (head);
    printf ("%p %d\n\n", mid, mid->data);
    
    print_list (head);
    free_list (head);
}

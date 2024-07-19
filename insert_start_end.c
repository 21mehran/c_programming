// Insert at the start and end alternatvly.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *insert_head (struct node *head, int data)
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
    
    if (head)
        head->link = ptr;
        
    head = ptr;
    return head;
}

void print_list (struct node *head) 
{
    struct node *ptr = head;
    
    while (ptr) {
        printf ("%p %d\n", ptr, ptr->data);
        ptr = ptr->link;
    }
}

int main ()
{
    struct node *start = NULL;
    struct node *end = NULL;
    
    for (int i = 1; i < 10; i = i + 2) {
        
        int data = i * 10;
        start = insert_head (start, data);    
        end = insert_end (end, data + 10);
        
        if (i == 1) 
            start->link = end;		// Link the start and end list.
    }
    
    print_list (start);
    return 0;    
}

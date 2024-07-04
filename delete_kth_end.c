// Delete kth element from the end of the linked list.

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

struct node *delete_kth_end (struct node *head, int k)
{
    struct node *ptr1 = head;
    struct node *ptr2 = head;
    int count = 0;
    
    // k + 1 because we need to delete the node.
    // k if you want to return the kth element.
    
    while (ptr1) {
        
        if (count >= k + 1) 
            ptr2 = ptr2->link;
        
        ptr1 = ptr1->link;
        
        if (ptr1 == NULL)
            ptr2->link = ptr2->link->link;
        
        count++;
    }
    
    return ptr2;
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
    
    for (int i = 1; i < 10; i++)
        head = insert_start (head, i * 10);
        
    printf ("Original Linked list : \n   start\n");
    print_list (head);
    printf ("    end  \n");
    
    struct node *kth = delete_kth_end (head, 5);
    
    printf ("\nLinked list after deletion.\n   start\n");
    print_list (head);
    printf ("    end  \n");
    
    free_list (head);
}

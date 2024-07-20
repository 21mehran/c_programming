// Delete Odd nodes from a linked list.

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

struct node *delete_odd (struct node *head) 
{
    struct node *ptr = head;
    struct node *temp = head;
    int flag = 1;

    while (ptr && ptr->link) {
        
        ptr = temp->link;
        free (temp);
        
        if (flag == 1) {
            head = ptr;
            flag = 0;
        }
        
        temp = ptr->link;
        ptr->link = temp->link;
    }
    
    return head;
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
        
    printf ("Original linked list:\n");
    print_list (head);    

    printf ("\nAfter deleting even nodes: \n");
    head = delete_odd (head);
    
    print_list (head);
    free_list (head);
}

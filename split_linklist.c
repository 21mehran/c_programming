// Split the linked list into two list.
// 1. List with Even nodes.
// 2. List with Odd nodes.
// 3. Merge the two lists.

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

struct node *split_list (struct node *head, struct node *split) 
{
    struct node *ptr = head;
    struct node *temp = NULL;

    while (ptr) {

        split = malloc (sizeof (struct node));
        split->data = ptr->data;
        
        if (ptr->link) {
            ptr = ptr->link->link;
        } else {
            ptr = ptr->link;
        }
        
        split->link = temp;
        temp = split;
    }
    return split;
}

struct node *merge_list (struct node *result, struct node *even, struct node *odd)
{
    int count = 2;
    
    struct node *temp = NULL;
    struct node *even_ptr = even;
    struct node *odd_ptr = odd;
    
    while (odd_ptr) {
        
        result = malloc (sizeof (struct node));
        
        if (count % 2 == 0 && even_ptr) {
            result->data = even_ptr->data;
            even_ptr = even_ptr->link;
        }    
        else {
            result->data = odd_ptr->data;
            odd_ptr = odd_ptr->link;
        }
          
        count++;    
        result->link = temp;
        temp = result;
    }
    
    return result;
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
    struct node *even = NULL;
    struct node *odd = NULL;
    struct node *result = NULL;
    
    for (int i = 1; i < 10; i++)
        head = insert_start (head, i * 10);
        
    printf ("Original Linked list:\n");
    print_list (head);
    
    //  head - 1th pointer for odd;
    printf ("\nEven Split Linked list:\n");
    odd = split_list (head, odd);
    print_list (odd);
    
    // head - 2st pointer for even;
    printf ("\nOdd Split Linked list:\n");
    even = split_list (head->link, even);
    print_list (even);
    
    // Merged list;
    printf ("\nMerge Split Linked list:\n");
    result = merge_list (result, even, odd);
    print_list (result);
    
    free_list (result);
    free_list (even);
    free_list (odd);
    free_list (head);
}

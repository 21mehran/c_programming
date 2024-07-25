//  Add two numbers represented by a linked list

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
        printf ("%d ", ptr->data);
        ptr = ptr->link;
    }
    
    printf ("\n");
}

//  Preceding zeros to the smaller linked list.

void pre_process (struct node *first, struct node *second) 
{
    struct node *one = first;
    struct node *two = second;
    
    while (one || two) {
        
        if (two->link == NULL && one->link != NULL) {
            
            struct node *ptr = malloc (sizeof (struct node));
            ptr->data = 0;
            ptr->link = NULL;
            two->link = ptr;
        }
        
        if (one->link == NULL && two->link != NULL) {
            
            struct node *ptr = malloc (sizeof (struct node));
            ptr->data = 0;
            ptr->link = NULL;
            one->link = ptr;
        }
        
        one != NULL ? one = one->link : 0;
        two != NULL ? two = two->link : 0;
    }
}

struct node* process (struct node *first, struct node *second, struct node *result)
{
    struct node *ptr = NULL;
    int carry = 0;
    
    while (first) {
        
        result = malloc (sizeof (struct node));
        result->data = first->data + second->data + carry;
        
        carry = (result->data) > 9 ? 1 : 0;
        
        if (first->link)
            result->data = (carry == 1) ? result->data = result->data % 10 : result->data;
        else    
            result->data = first->data + second->data + carry;
         
        result->link = ptr;
        ptr = result;
        
        first = first->link;
        second = second->link;
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
    struct node *num_1 = NULL;
    struct node *num_2 = NULL;
    struct node *result = NULL;
    
    num_1 = insert_start (num_1, 9);
    num_1 = insert_start (num_1, 9);
    num_1 = insert_start (num_1, 9);
    num_1 = insert_start (num_1, 9);
    
    num_2 = insert_start (num_2, 8);
    num_2 = insert_start (num_2, 8);
    num_2 = insert_start (num_2, 8);
    num_2 = insert_start (num_2, 8);
    
    printf ("First number : \n");
    print_list (num_1);
    printf ("Second number : \n");
    print_list (num_2);
    
    pre_process (num_1, num_2);     //  Adding zeros to a smaller linked list.
    // print_list (num_1);
    // print_list (num_2);
    
    printf ("Result number : \n");
    result = process (num_1, num_2, result);
    print_list (result);
    
    free_list (num_1);
    free_list (num_2);
    free_list (result);
}

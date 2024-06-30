// Implementation of Queue using Linkedlist.

#include <stdio.h>
#include <stdlib.h>

struct node *start = NULL;
struct node *end = NULL;

struct node {
  int data;
  struct node *link;
};

void enq (int data) 
{
    struct node *ptr = malloc (sizeof (struct node));
    
    if (start == NULL) {
        ptr->data = data;
        ptr->link = NULL;
        start = end = ptr;
    } else {
        ptr->data = data;
        ptr->link = NULL;
        end->link = ptr;
    }
    printf ("%d --> <Queue>\n", ptr->data);
}

void deq ()
{
    struct node *temp = start;
   
    if (start == NULL) 
        printf ("Stack empty\n");
    else {
        printf ("<queue> --> %d\n", start->data);
        start = start->link;
        free (temp);
        temp = start;
    }    
}

void display ()
{
    struct node *ptr = start;
    
    while (ptr) {
        printf (" [ %d ]\n", ptr->data);
        ptr = ptr->link;
    }
}

int main ()
{
    enq (10);
    enq (20);
    display ();
    deq ();
    display ();
    deq ();
    deq ();
}


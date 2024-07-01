// Implement a Stack using Linklist.

#include <stdio.h>
#include <stdlib.h>

struct node *top = NULL;

struct node {
  int data;
  struct node *link;
};

void push (int data)
{
    struct node *ptr = malloc(sizeof(struct node));
    
    ptr->data = data;
    ptr->link = top;
    top = ptr;
    
    printf("%d --> stack\n", top->data);
}

void pop ()
{
    struct node *ptr = top;
    
    if (top == NULL)
        printf ("Stack underflow");
    else {
        top = top->link;
        printf ("stack --> %d\n", ptr->data);
        free (ptr);
    }
}

void peek ()
{
    if (top == NULL)
        printf ("Stack empty.\n");
    else
        printf ("peep = %d \n", top->data);
}

int main ()
{
    push (10);
    push (20);
    peek ();
    pop ();
    peek ();
    pop ();
    peek ();
}

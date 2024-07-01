// Stack implementation using array.

#include <stdio.h>
#define MAX 4

int stack[MAX];
int top = -1;

void push (int data) 
{
    if (top == MAX - 1) 
        printf ("Stack Overflow\n");
    else {    
        stack[++top] = data;
        printf ("%d --> stack.\n", stack[top]);
    }
}

void pop ()
{
    if (top == -1)
        printf ("Stack Underflow.\n");
    else {    
        printf ("stack --> %d\n", stack[top--]);
    }
}

void peek ()
{
    if (top == -1)  
        printf ("Stack empty\n");
    else {
        printf ("-- %d -- \n", stack[top]);
    }
}

int main()
{
    push (10);
    push (20);
    push (30);
    pop ();
    peek ();
    pop ();
    pop ();
    pop ();
    peek ();
    return 0;
}

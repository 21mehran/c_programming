// Implement Queue using array.

#include <stdio.h>
#define MAX 10

int queue [MAX];
int start = -1;
int end = -1;

int is_empty () 
{
     return (start == -1 && end  == -1 || start > end ? 1 : 0);
}

void enque (int data) 
{
    if (end == MAX) 
        printf ("Queue overflow\n");
    else if (is_empty ()) {
        start = end = 0;
    }    
    else {
        end++;
    }
    
    queue[end] = data;
    printf ("%d --> queue\n", queue[end]);
}

void deque ()
{
    if (is_empty ())
        printf ("Queue underflow\n");
    else if (start > end)    
        start = end = -1;
    else {
        printf ("queue --> %d\n", queue[start]);
        start++;
    }    
}

void peek ()
{
    if (is_empty ())
        printf ("Queue Empty\n");
    else
        printf ("-- %d --\n", queue[start]);
}

int main() 
{
    enque (10);
    enque (20);
    deque ();
    peek ();
    deque ();
    deque ();
    peek ();

    return 0;
}

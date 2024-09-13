// Find the offset of struct elements.

#include <stdio.h>

#define OFFSET(a,b) ((char *)(b) - (char *)(a))

struct test {
  double a;
  char b;
  int c;
  short d;
};

int struct_offset (struct test *ptr1, void *ptr2)
{
    return (char *)ptr2 - (char *)ptr1;
}

int main ()
{
    struct test p1;

    /*      struct node *ptr;
     *      SIZE(ptr, &(ptr->data));
     */


    printf ("Offset a : using function - %d\n", struct_offset (&p1, &p1.a));     // Using function call.
    printf ("Offset b : using function - %d\n", struct_offset (&p1, &p1.b));
    printf ("Offset c : using MACRO - %d\n", OFFSET (&p1, &p1.c));             // Using MACRO.
    printf ("Offset d : using MACRO - %d\n", OFFSET (&p1, &p1.d));
}


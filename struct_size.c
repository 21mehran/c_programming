// Find the size of the structure without using sizeof.

#include <stdio.h>

#define SIZE(a) ((char*)(a + 1) - (char*)a)

struct test {
  double a;
  char b;
  int c;
  short d;
};

int struct_size (struct test *ptr)
{
    return (char *)(ptr + 1) - (char *)ptr;
}

int main ()
{
    struct test p1;

    /*      struct node *ptr;
     *      SIZE(ptr) ((char*)ptr - (char*)ptr++);
     *      SIZE (ptr);
     */

    printf ("Size of struct using function - %d\n", struct_size (&p1));  // Using function call.
    printf ("Size of struct using MACRO - %d\n", SIZE (&p1));        // Using MACRO.
}

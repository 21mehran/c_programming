// Get set static number and function from a file other than where it is 
// declared using extern

// FILE1.C

#include <stdio.h>

extern int get_static_number ();
extern void set_static_number (int value);
extern void (*fptr)();
extern int *ptr;

int main ()
{
	printf ("%d \n", *ptr);
	printf ("%d \n", get_static_number());	   // Prints the value of static variable num.
	set_static_number(100);
	printf ("%d \n", get_static_number());	

	fptr ();    // Prints "This is a static function."
	return 0;
}

// FILE2.C

#include <stdio.h>

static int num = 21;
int *ptr = &num;

int get_static_number ()
{
	return num;
}

void set_static_number (int value)
{
	num = value;
}

static void static_function () { printf ("this is a static function\n"); }

void (*fptr)() = static_function;

// GCC FILE1.C FILE2.C

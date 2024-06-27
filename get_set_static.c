// Get and set a static variable and function from a file other
// then where it is declared.

// FILE1.C

#include <stdio.h>
#include "file2.h"  // This is where the static function and static variable is present.

int main ()
{
	printf ("%d \n", get_static_number());	// Prints the value of static variable num.
	printf ("%d \n", set_static_number(100));
	printf ("%d \n", get_static_number());	

	fptr ();    // Prints "This is a static function."
	return 0;
}

// FILE2.C

static int num = 21;

int get_static_number ()
{
	return num;
}

int set_static_number (int value)
{
	num = value;
	return num;
}

static void static_function () 
{
	printf ("this is a static function\n");
}

void (*fptr)() = static_function;

// GCC FILE1.C

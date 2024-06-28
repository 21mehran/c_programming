// CALCULATE THE LENGTH OF THE STRING.

#include <stdio.h>

int string_length (char *str)
{
	char *start = str;
	
	while (*str) {
		str++;		
	}

	return str - start;
}

int main ()
{
	char *str = "mehran";
	printf ("%d", string_length (str));
}

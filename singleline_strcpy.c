// Implement strcpy using a single line.

#include <stdio.h>

void string_copy (char *dest, char *src)
{
	while (*dest++ = *src++);
}

int main ()
{
	char *str1 = "mehran";
	char str2[10];

	string_copy (str2, str1);

	printf ("%s ", str2);

	return 0;
}

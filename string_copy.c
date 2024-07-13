// STRING COPY (strcpy)

#include <stdio.h>

void string_copy (char *str1, char *str2)
{
    // while (*str2++ = *str1);

    while (*str1) {
        *str2 = *str1;
        str1++;
        str2++;
    }
}

int main ()
{
  char *str1 = "mehran_ahemad";
  char str2[20];
   
  string_copy (str1, str2);
  printf ("str1 - %s\nstr2 - %s", str1, str2);
}

// STRING COPY (strncpy)

#include <stdio.h>

void string_copy (char *str1, char *str2, int num)
{
    int i = 0;
   
    // while ((*str2++ = *str1) && i++ < n - 1);

    while (*str1 && i < num) {
        
        *str2 = *str1;
        str1++;
        str2++;
        i++;
    }
    
    *str2 = '\0';
}

int main ()
{
  char *str1 = "mehran_ahemad";
  char str2[20];
   
  int limit = 10; 
  string_copy (str1, str2, limit);
  printf ("str1 - %s\nstr2 - %s", str1, str2);
}

// STRING COPY (strlcpy)

#include <stdio.h>

int string_copy (char *str1, char *str2, int dest_size)
{
    int i = 0;
    
    while (*str1 && i < dest_size) {
        
        *str2 = *str1;
        str1++;
        str2++;
        i++;
    }
    
    *str2 = '\0';
}

int main ()
{
  char *str1 = "mehran_ahemad";
  char str2[20];
   
  int dest_size = 20; 
  string_copy (str1, str2, dest_size);
  printf ("str1 - %s\nstr2 - %s", str1, str2);
}

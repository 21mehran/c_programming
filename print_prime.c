// Print Prime Number till a limit.

#include <stdio.h>
#include <stdbool.h>

void print_prime (int limit)
{
  for (int i = 1; i < limit; i++) {
  
    bool prime = true;

    for (int j = 2; j * j < i; j++) {     // j * j < i = Optimization
      
      if (i % j == 0) {
        prime = false;
        break;
      }
        
    }

    if (prime) 
      printf ("%d \n", i);
  }
}

int main (int argc, char *argv[])
{
  int limit = 20;
  print_prime (limit);

  return 0;
}


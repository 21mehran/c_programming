// Understanding the wait system call.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main () 
{
   pid_t pid = fork ();

   if (pid == 0) {
       printf ("Child process finished\n");
   } else {
      wait (NULL);
       printf ("Parent process finished\n");
   }

   return 0;
}

// Result - Using wait ()
// Child process finished
// Parent process finished

// Result - Without wait ()
// Parent process finished 
// Child process finished

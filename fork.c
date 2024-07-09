// Understanding fork system call.

#include <stdio.h>
#include <unistd.h>

int main ()
{
    fork ();
    // Creates 2 process which run simultaneously (Parent + child);
    fork ();
    // Already 2 process existing. These 2 process reproduce creating 4 process.

    printf ("child process - %d parent process - %d\n", getpid(), getppid ());

  return 0;
}


/*
 * child process - 31266 parent process - 22918
 * child process - 31268 parent process - 31266
 * child process - 31267 parent process - 31266
 * child process - 31269 parent process - 31267
 */



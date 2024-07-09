// Understanding the exec system call.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main ()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        char *args[] = {"fork.out", "-l", NULL};
        execv(args[0], args);
        exit(1); 	// If exec fails.
    } else {
        // Parent process
        wait(NULL);  // Wait for the child process to finish
        printf("Child process finished\n");
    }

    return 0;
}


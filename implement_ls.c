// Implement the linux command - ls.

#include <stdio.h>
#include <dirent.h>
#include <fnmatch.h>
#include <stdlib.h>

void list_directory (const char *path, const char *pattern)
{
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while (entry = readdir(dp)) {
        if (pattern == NULL || fnmatch(pattern, entry->d_name, 0) == 0) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dp);
}

int main (int argc, char *argv[])
{
    const char *path = "."; 
    const char *pattern = NULL;

    if (argc == 2) {
        path = argv[1];
    } else if (argc == 3) {
        path = argv[1];
        pattern = argv[2];
    } else if (argc > 3) {
        fprintf (stderr, "Usage: %s [directory] [pattern]\n", argv[0]);
        exit (EXIT_FAILURE);
    }

    list_directory (path, pattern);
    return 0;
}


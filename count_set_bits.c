
// Count Number of Setbits.

// Brute Force.

#include <stdio.h>

int main ()
{
    int num = 15;
    int count = 0;

    for (int i = 0; i < 4; i++) {
        if ((num >> i) & 1)
            count++;
    }

    printf ("%d ", count);
}

// Brian Kernighan's algorithm.

#include <stdio.h>

int main ()
{
    int num = 15;
    int count = 0;

    while (num != 0) {

        num = num & (num - 1);
        count++;
    }

    printf ("%d", count);
}

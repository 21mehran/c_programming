// Print all subsets whos sum works out to divisible by 3.

#include <stdio.h>

void print_subset (int arr[], int len) 
{
    int sum;
    
    for (int count = 0; count < (1 << len); count++) {

        sum = 0;
        // Calculate the sum of all the possible subsets.
        for (int i = 0; i < len; i++) {

            if (count & (1 << i)) 
                sum = sum + arr[i];
        }
        
        // Process which sum is divisible by 3 and print subset.
        for (int i = 0; i < len; i++) {
            
            if (count & (1 << i) && sum % 3 == 0)
                printf ("%d ", arr[i]);
        }
        
        printf("\n");
    }
}

int main () 
{
    int arr[] = {2, 3, 6, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf ("All subsets of the given set divisible by 3:\n");
    print_subset (arr, len);

    return 0;
}





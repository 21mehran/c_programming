
// Array contains of numbers starting from 0 - 50 such that each element is repeated thrice.
// Segregate each element in seperate arrays.
// {1,1,2,3,1,3,2,3,2} -> {1,1,1} {2,2,2} {3,3,3};

#include <stdio.h>

int main ()
{
    int arr[150] = { 5,25,26,44,12,50,18,36,31,25,38,28,6,21,8,28,24,39,14,20,44,40,15,36,16,45,29,4,22,7,48,40,45,2,38,45,10,20,23,17,34,27,9,11,32,20,47,7,39,19,10,11,8,13,37,42,10,46,46,50,15,4,35,34,2,23,29,24,5,49,48,9,1,18,37,16,12,32,36,3,39,12,41,14,14,29,47,9,18,15,49,5,16,50,28,26,6,33,1,44,19,33,6,27,3,1,33,31,25,35,32,11,30,8,30,27,21,23,42,37,43,19,35,3,26,22,46,17,49,48,22,42,40,13,43,17,43,13,21,47,24,41,34,2,38,30,31,7,4,41 };
    
    int count[51] = {0};        // Keep track of occurances of number.
    int table[50][3] = {0};     // Arrange in this array.
    
    for (int i = 0; i < 150; i++)
        table [arr[i]][count[arr[i]]++] = arr[i];
        
    // Printing the arrays.    
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 3; j++)
            printf ("%d ", table[i][j]);
        printf ("\n");
    }
}

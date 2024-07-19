
// CHANGE ENDIANESS USING UNION.

#include <stdio.h>

union person {
    int num;
    unsigned har arr[4]; 	// Char is signed by default. (Important)
};

int main()
{
    union person p1 = {0x12345678};

    int i = 0;
    int j = 3;
    
    p1.num = (p1.arr[i++] << (8 * j--)) | (p1.arr[i++] << (8 * j--)) | (p1.arr[i++] << (8 * j--)) | (p1.arr[i++] << (8 * j--));
    
    printf ("%X ", p1.num);
    
    return 0;
}


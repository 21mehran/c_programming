// Implementation of itoa function

#include <stdio.h>

// Function to convert integer to string
char* itoa (int num, char* str, int base) {
    int i = 0;
    int isNegative = 0;
    
    // Handle 0 explicitly, otherwise empty string is printed
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // Handle negative numbers
    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str[i++] = rem + '0';
        num = num / base;
    }
    
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Null terminate the string

    // Reverse the string
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
    
    return str;
}

int main() {
    int num = 12;
    char str[20]; 

    itoa(num, str, 8);
    printf("Integer: %d\nString: %s\n", num, str);

    return 0;
}


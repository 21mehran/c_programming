#include <stdio.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int left, int right) {
    
    int pivot = arr[left];  // Choosing the leftmost element as pivot
    int start = left;   // Start from left + 1
    int end = right;        // End at right

    while (start <= end) {
        // Find element greater than pivot from the left side
        while (arr[start] <= pivot) {
            start++;
        }
        // Find element less than pivot from the right side
        while (arr[end] > pivot) {
            end--;
        }
        // Swap elements if start and end have not crossed
        if (start < end) {
            swap(arr + start, arr + end);
        }
    }

    // Swap pivot with element at end (new pivot position)
    swap (arr + left, arr + end);

    // Return pivot index
    return end;
}

// Quicksort function
void qwick_sort(int arr[], int left, int right) {
    
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        qwick_sort(arr, left, pivotIndex - 1);
        qwick_sort(arr, pivotIndex + 1, right);
    }
}

void print(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {38, 27, 43, 3, 9, 82, 10};
    int length = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    print(array, length);

    qwick_sort(array, 0, length - 1);

    printf("Sorted array: ");
    print(array, length);

    return 0;
}


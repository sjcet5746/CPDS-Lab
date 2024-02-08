#include <stdio.h>
// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_index;
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in the unsorted part of the array
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap the found minimum element with the first element
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}
// Function to print the sorted array
void printArray(int arr[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Perform Selection Sort
    selectionSort(arr, n);
    // Print the sorted array
    printArray(arr, n);
    return 0;
}

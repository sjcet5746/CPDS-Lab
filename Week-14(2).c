#include <stdio.h>
// Recursive binary search function
int recursiveBinarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            return recursiveBinarySearch(arr, mid + 1, high, key);
        } else {
            return recursiveBinarySearch(arr, low, mid - 1, key);
        }
    }
    return -1; // Key not found
}
// Non-recursive binary search function
int nonRecursiveBinarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Key not found
}
int main() {
    int n, key;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the list in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search for: ");
    scanf("%d", &key);
    // Recursive binary search
    int recursiveResult = recursiveBinarySearch(arr, 0, n - 1, key);
    if (recursiveResult != -1) {
        printf("Key found at index (recursive): %d\n", recursiveResult);
    } else {
        printf("Key not found (recursive)\n");
    }
    // Non-recursive binary search
    int nonRecursiveResult = nonRecursiveBinarySearch(arr, n, key);
    if (nonRecursiveResult != -1) {
        printf("Key found at index (non-recursive): %d\n", nonRecursiveResult);
    } else {
        printf("Key not found (non-recursive)\n");
    }
    return 0;
}

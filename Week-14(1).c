#include <stdio.h>
// Recursive linear search function
int recursiveLinearSearch(int arr[], int n, int key, int index) {
    // Base case: if index exceeds array size, key is not found
    if (index >= n) {
        return -1;
    }
    // Base case: if current element equals key, return index
    if (arr[index] == key) {
        return index;
    }
    // Recursive case: search in the rest of the array
    return recursiveLinearSearch(arr, n, key, index + 1);
}
// Non-recursive linear search function
int nonRecursiveLinearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Key not found
}
int main() {
    int n, key;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search for: ");
    scanf("%d", &key);
    // Recursive linear search
    int recursiveResult = recursiveLinearSearch(arr, n, key, 0);
    if (recursiveResult != -1) {
        printf("Key found at index (recursive): %d\n", recursiveResult);
    } else {
        printf("Key not found (recursive)\n");
    }
    // Non-recursive linear search
    int nonRecursiveResult = nonRecursiveLinearSearch(arr, n, key);
    if (nonRecursiveResult != -1) {
        printf("Key found at index (non-recursive): %d\n", nonRecursiveResult);
    } else {
        printf("Key not found (non-recursive)\n");
    }
    return 0;
}

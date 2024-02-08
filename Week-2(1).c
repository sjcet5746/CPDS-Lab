#include <stdio.h>
int main() {
    int n, i;
    int arr[50]; // Assuming maximum number of elements in the list is 50
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    // Input elements of the list
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Initialize largest and smallest with the first element of the list
    int largest = arr[0];
    int smallest = arr[0];
    // Iterate through the list to find the largest and smallest numbers
    for (i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    // Output the largest and smallest numbers
    printf("The largest number in the list is: %d\n", largest);
    printf("The smallest number in the list is: %d\n", smallest);
    return 0;
}

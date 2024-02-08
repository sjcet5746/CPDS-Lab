#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Pointer to the first element of the array
    // Printing array elements using pointer arithmetic
    printf("Array elements using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));
    }
    // Pointer arithmetic: incrementing and decrementing pointers
    int *ptr2 = &arr[2]; // Pointer to the third element of the array
    printf("\nPointer arithmetic: incrementing and decrementing pointers\n");
    printf("Value at ptr2: %d\n", *ptr2); // Should print 30
    ptr2++; // Move pointer to the next element
    printf("Value at ptr2 after incrementing: %d\n", *ptr2); // Should print 40
    ptr2--; // Move pointer back to the previous element
    printf("Value at ptr2 after decrementing: %d\n", *ptr2); // Should print 30
    // Pointer arithmetic: adding an integer to a pointer
    printf("\nPointer arithmetic: adding an integer to a pointer\n");
    int *ptr3 = arr + 3; // Pointer to the fourth element of the array
    printf("Value at ptr3: %d\n", *ptr3); // Should print 40
    // Pointer arithmetic: subtracting an integer from a pointer
    printf("\nPointer arithmetic: subtracting an integer from a pointer\n");
    int *ptr4 = &arr[4]; // Pointer to the fifth element of the array
    int *ptr5 = ptr4 - 2; // Pointer to the third element of the array
    printf("Value at ptr5: %d\n", *ptr5); // Should print 30
    return 0;
}

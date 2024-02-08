#include <stdio.h>
// Function prototype for call-by-value
void callByValue(int num) {
    printf("Inside callByValue function before modification: num = %d\n", num);
    num = 100; // Modifying the local copy of num
    printf("Inside callByValue function after modification: num = %d\n", num);
}
// Function prototype for call-by-reference
void callByReference(int *ptr) {
    printf("Inside callByReference function before modification: *ptr = %d\n", *ptr);
    *ptr = 100; // Modifying the value at the address pointed to by ptr
    printf("Inside callByReference function after modification: *ptr = %d\n", *ptr);
}
int main() {
    int num = 10;
    // Demonstrate call-by-value
    printf("Demonstrating call-by-value:\n");
    printf("Before calling callByValue function: num = %d\n", num);
    callByValue(num); // Passing num by value
    printf("After calling callByValue function: num = %d\n\n", num);
    // Demonstrate call-by-reference
    printf("Demonstrating call-by-reference:\n");
    printf("Before calling callByReference function: num = %d\n", num);
    callByReference(&num); // Passing address of num by reference
    printf("After calling callByReference function: num = %d\n", num);
    return 0;
}

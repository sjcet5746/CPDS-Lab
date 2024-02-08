#include <stdio.h>
// Function to calculate GCD recursively
int gcdRecursive(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcdRecursive(b, a % b);
}
// Function to calculate GCD non-recursively
int gcdNonRecursive(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int num1, num2;
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);
    // Using recursive function to calculate GCD
    printf("GCD using recursive function: %d\n", gcdRecursive(num1, num2));
    // Using non-recursive function to calculate GCD
    printf("GCD using non-recursive function: %d\n", gcdNonRecursive(num1, num2));
    return 0;
}

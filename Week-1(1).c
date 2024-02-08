#include <stdio.h>
// Function to calculate factorial recursively
int factorialRecursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorialRecursive(n - 1);
}
// Function to calculate factorial non-recursively
int factorialNonRecursive(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    // Using recursive function to calculate factorial
    printf("Factorial using recursive function: %d\n", factorialRecursive(num));
    // Using non-recursive function to calculate factorial
    printf("Factorial using non-recursive function: %d\n", factorialNonRecursive(num));
    return 0;
}

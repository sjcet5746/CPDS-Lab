#include <stdio.h>
// Structure to represent a complex number
typedef struct {
    float real;
    float imag;
} Complex;
// Function to add two complex numbers
Complex addComplex(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}
// Function to multiply two complex numbers
Complex multiplyComplex(Complex num1, Complex num2) {
    Complex result;
    result.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    result.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
    return result;
}
// Function to read a complex number
void readComplex(Complex *num) {
    printf("Enter real part: ");
    scanf("%f", &(num->real));
    printf("Enter imaginary part: ");
    scanf("%f", &(num->imag));
}
// Function to write a complex number
void writeComplex(Complex num) {
    if (num.imag >= 0) {
        printf("%.2f + %.2fi\n", num.real, num.imag);
    } else {
        printf("%.2f - %.2fi\n", num.real, -num.imag);
    }
}
int main() {
    Complex num1, num2, sum, product;
    // Reading the first complex number
    printf("Enter the first complex number:\n");
    readComplex(&num1);
    // Reading the second complex number
    printf("Enter the second complex number:\n");
    readComplex(&num2);
    // Performing addition
    sum = addComplex(num1, num2);
    printf("Sum of the complex numbers: ");
    writeComplex(sum);
    // Performing multiplication
    product = multiplyComplex(num1, num2);
    printf("Product of the complex numbers: ");
    writeComplex(product);
    return 0;
}

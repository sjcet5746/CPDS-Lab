#include <stdio.h>
// Structure to represent a complex number
typedef struct {
    float real;
    float imag;
} Complex;
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
    Complex num;
    // Reading a complex number
    printf("Enter a complex number:\n");
    readComplex(&num);
    // Writing the complex number
    printf("The complex number you entered is: ");
    writeComplex(num);
    return 0;
}

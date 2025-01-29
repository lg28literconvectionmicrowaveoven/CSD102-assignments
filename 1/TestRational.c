#include "Rational.h" // Type and interface are declared here
#include <stdio.h>

// Helper function to print a rational number
void PrintRational(Rational r) {
    printf("%d / %d ", r.numerator, r.denominator);
}

// Helper function to read a rational number
Rational ReadRational() {
    Rational r;
    printf("\n Enter numerator: ");
    scanf("%d", &(r.numerator));
    do {
        printf("\n Enter denominator: ");
        scanf("%d", &(r.denominator));
    } while (r.denominator == 0);
    r = Rreduce(r);
    printf("\n Read the rational number ");
    PrintRational(r);
    printf("\n");
    return r;
}

// Driver function to test the implementation of rational numbers
int main() {
    Rational r1, r2, r3;
    r1 = ReadRational();
    r2 = ReadRational();
    r3 = ReadRational();

    printf("\n r1 + r2 = ");
    PrintRational(Radd(r1, r2));
    printf("\n r2 - r3 = ");
    PrintRational(Rsub(r2, r3));
    printf("\n r1 * r3 = ");
    PrintRational(Rmult(r1, r3));
    printf("\n r3 / r2 = ");
    PrintRational(Rdiv(r3, r2));
    printf("\n Inverse of r1 = ");
    PrintRational(Rinverse(r1));
    printf("\n");
    return 0;
}

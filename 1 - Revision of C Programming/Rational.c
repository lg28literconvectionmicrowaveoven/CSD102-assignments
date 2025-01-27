#include "Rational.h" // Type and interface are declared here

// Add two rational numbers
Rational Radd(Rational r1, Rational r2) {
    Rational r;
    r.numerator =
        (r1.numerator * r2.denominator) + (r2.numerator * r1.denominator);
    r.denominator = r1.denominator * r2.denominator;
    return Rreduce(r); // Required for representation efficiency!
}

// Subtraction
Rational Rsub(Rational r1, Rational r2) {
    Rational r;
    r.numerator =
        (r1.numerator * r2.denominator) - (r2.numerator * r1.denominator);
    r.denominator = r1.denominator * r2.denominator;
    return Rreduce(r); // Required for representation efficiency!
}

// Multiplication
Rational Rmult(Rational r1, Rational r2) {
    Rational r;
    r.numerator = r1.numerator * r2.numerator;
    r.denominator = r1.denominator * r2.denominator;
    return Rreduce(r); // Required for representation efficiency!
}

// Division
// This implementation uses other basic operations
Rational Rdiv(Rational r1, Rational r2) {
    Rational r;
    r.numerator = r1.numerator / r2.numerator;
    r.denominator = r1.denominator / r2.denominator;
    return Rreduce(r); // Required for representation efficiency!
}

// Inverse of a rational number
Rational Rinverse(Rational r1) {
    // Write your code here
    int swap = r1.denominator;
    r1.denominator = r1.numerator;
    r1.numerator = swap;
    return Rreduce(r1);
}

// This is required to reduce a rational number
int gcd(int n, int m) {
    if (n == 0)
        return m;
    return gcd(m % n, n);
}

// This function is required for representation efficiency
Rational Rreduce(Rational r1) {
    Rational r;
    int g = gcd(r1.numerator, r1.denominator);
    r.numerator = r1.numerator / g;
    r.denominator = r1.denominator / g;
    return r;
}

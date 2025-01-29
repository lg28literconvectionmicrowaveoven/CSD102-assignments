/* Rational ADT Header file */

/* Defines the structure and declares the operations */

typedef struct {
    int numerator;
    int denominator;
} Rational;

/* Interface is declared below */
/* The operations are self-explanatory */

/* NOTE: Each operation CREATES a NEW rational number */

Rational Radd(Rational r1, Rational r2);
Rational Rsub(Rational r1, Rational r2);
Rational Rmult(Rational r1, Rational r2);
Rational Rdiv(Rational r1, Rational r2);
Rational Rinverse(Rational r1);
Rational Rreduce(Rational r1);

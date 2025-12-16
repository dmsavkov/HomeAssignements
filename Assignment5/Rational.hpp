// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Rational number value type for exact arithmetic. Supports +, *, and ==.
//              Note: fraction normalization/reduction is intentionally omitted for assignment scope.

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

// TODO: quotient is not normalized.
class Rational {
private:
    int m;
    int n;

public:
    // best practice for compatibility issues such as using sum{} in the matrix
    Rational() : m(0), n(1) {}

    Rational(int m, int n) : m(m), n(n) {}

    int getNumerator() const { return m; }
    int getDenumerator() const { return n; }

    Rational operator*(const Rational& other) const {
        return Rational(m * other.getNumerator(), n * other.getDenumerator());
    }

    Rational operator+(const Rational& other) const {
        return Rational(
            m * other.getDenumerator() + other.getNumerator() * n,
            n * other.getDenumerator()
        );
    }

    bool operator==(const Rational& other) const {
        return m == other.m && n == other.n; // no normalization in this assignment scope
    }
};

#endif
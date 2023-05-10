#include <iostream>
#include <stdexcept>
#include "Fraction.hpp"
using namespace std;
using namespace ariel;

//----------------------------------------------------------------------------------//
//                                   Constructors
//----------------------------------------------------------------------------------//

Fraction ::Fraction(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Denominator can't be 0");
    }
    if (denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }

    int gcd = findGCD(abs(numerator), abs(denominator));
    this->numerator = numerator / gcd;
    this->denominator = denominator / gcd;
}

Fraction ::Fraction(float num) : numerator(1000 * num), denominator(1000)
{
    int gcd = findGCD(abs(numerator), abs(denominator));
    this->numerator = numerator / gcd;
    this->denominator = denominator / gcd;
}

Fraction ::Fraction()
{
    this->numerator = 0;
    this->denominator = 1;
}

//----------------------------------------------------------------------------------//
//                                Getters and Setters
//----------------------------------------------------------------------------------//

int Fraction ::getNumerator() const
{
    return this->numerator;
}

int Fraction ::getDenominator() const
{
    return this->denominator;
}

void Fraction ::setNumerator(int numerator)
{
    this->numerator = numerator;
}

void Fraction ::setDenominator(int denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Denominator can't be 0");
    }
    this->denominator = denominator;
}

//----------------------------------------------------------------------------------//
//         Operators:        +        -        *        /       ++        --
//----------------------------------------------------------------------------------//

// +
Fraction Fraction::operator+(const Fraction &other)
{
    int num = 0, den = 0;

    if (__builtin_smul_overflow(numerator, other.denominator, &num))
        throw overflow_error("Overflow");
    if (__builtin_smul_overflow(other.numerator, denominator, &den))
        throw overflow_error("Overflow");
    if (__builtin_sadd_overflow(num, den, &num))
        throw overflow_error("Overflow");
    if (__builtin_smul_overflow(denominator, other.denominator, &den))
        throw overflow_error("Overflow");

    return Fraction(num, den);
}




// -

Fraction Fraction::operator-(const Fraction &other)
{
    int num = 0, den = 0;

    // Calculate the numerator and denominator using cross-multiplication
    if (__builtin_smul_overflow(numerator, other.denominator, &num))
        throw overflow_error("Overflow");
    if (__builtin_smul_overflow(other.numerator, denominator, &den))
        throw overflow_error("Overflow");
    if (__builtin_ssub_overflow(num, den, &num))
        throw overflow_error("Overflow");
    if (__builtin_smul_overflow(denominator, other.denominator, &den))
        throw overflow_error("Overflow");

    return Fraction(num, den);
}


// *
Fraction Fraction::operator*(const Fraction &other)
{
    int num = 0, den = 0;

    // Calculate the numerator and denominator using multiplication
    if (__builtin_smul_overflow(numerator, other.getNumerator(), &num))
        throw overflow_error("Overflow");
    if (__builtin_smul_overflow(denominator, other.getDenominator(), &den))
        throw overflow_error("Overflow");

    return Fraction(num, den);
}


// /
Fraction Fraction ::operator/(const Fraction &other)
{
    if (other.numerator == 0)
        throw runtime_error("Can't divide by zero!");

    int num = 0, den = 0;

    // Calculate the numerator and denominator using multiplication
    if (__builtin_smul_overflow(numerator, other.denominator, &num))
        throw overflow_error("Overflow");
    if (__builtin_smul_overflow(denominator, other.numerator, &den))
        throw overflow_error("Overflow");

    return Fraction(num, den);
}

// ++
Fraction Fraction ::operator++(int)
{
    Fraction temp(this->numerator, this->denominator);
    this->numerator += abs(this->denominator);
    return temp;
}

// ++
Fraction &Fraction ::operator++()
{
    this->numerator += abs(this->denominator);
    return *this;
}

// --
Fraction Fraction ::operator--(int)
{
    Fraction temp(this->numerator, this->denominator);
    this->numerator -= abs(this->denominator);
    return temp;
}

// --
Fraction &Fraction ::operator--()
{
    this->numerator -= abs(this->denominator);
    return *this;
}

//----------------------------------------------------------------------------------//
//             Operator:        ==        >        <        >=        <=
//----------------------------------------------------------------------------------//

// ==
bool Fraction ::operator==(const Fraction &other) const
{
    return (this->numerator * other.getDenominator()) == (other.getNumerator() * this->denominator);
}

// >
bool Fraction ::operator>(const Fraction &other) const
{
    return (this->numerator * other.getDenominator()) > (other.getNumerator() * this->denominator);
}

// <
bool Fraction ::operator<(const Fraction &other) const
{
    return (this->numerator * other.getDenominator()) < (other.getNumerator() * this->denominator);
}

// >=
bool Fraction ::operator>=(const Fraction &other) const
{
    return (this->numerator * other.getDenominator()) >= (other.getNumerator() * this->denominator);
}

// <=
bool Fraction ::operator<=(const Fraction &other) const
{
    return (this->numerator * other.getDenominator()) <= (other.getNumerator() * this->denominator);
}

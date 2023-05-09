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

Fraction ::Fraction(int numerator)
{
    this->numerator = numerator;
    this->denominator = 1;
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
Fraction Fraction ::operator+(const Fraction &other)
{
    if (__builtin_smul_overflow(this->numerator, other.getDenominator(), &this->numerator) || __builtin_smul_overflow(other.getNumerator(), this->denominator, &this->denominator))
    {
        throw std::overflow_error("Overflow error");
    }
    if (__builtin_sadd_overflow(this->numerator, this->denominator, &this->numerator) || __builtin_sadd_overflow(other.getNumerator(), other.getDenominator(), &this->denominator))
    {
        throw std::overflow_error("Overflow error");
    }
    return Fraction(numerator, denominator);
}

// -
Fraction Fraction ::operator-(const Fraction &other)
{
    if (__builtin_smul_overflow(this->numerator, other.getDenominator(), &this->numerator) || __builtin_smul_overflow(other.getNumerator(), this->denominator, &this->denominator))
    {
        throw std::overflow_error("Overflow error");
    }
    if (__builtin_ssub_overflow(this->numerator, this->denominator, &this->numerator) || __builtin_ssub_overflow(other.getNumerator(), other.getDenominator(), &this->denominator))
    {
        throw std::overflow_error("Overflow error");
    }
    return Fraction(numerator, denominator);
}

// *
Fraction Fraction ::operator*(const Fraction &other)
{
    if (__builtin_smul_overflow(this->numerator, other.getNumerator(), &this->numerator) || __builtin_smul_overflow(other.getDenominator(), this->denominator, &this->denominator))
    {
        throw std::overflow_error("Overflow error");
    }
    return Fraction(numerator, denominator);
}

// /
Fraction Fraction ::operator/(const Fraction &other)
{
    if (__builtin_smul_overflow(this->numerator, other.getDenominator(), &this->numerator) || __builtin_smul_overflow(other.getNumerator(), this->denominator, &this->denominator))
    {
        throw std::overflow_error("Overflow error");
    }
    if (other.getNumerator() == 0)
    {
        throw std::runtime_error("Can't divide by 0");
    }
    return Fraction(numerator, denominator);
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

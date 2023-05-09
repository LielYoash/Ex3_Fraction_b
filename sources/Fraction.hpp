#ifndef Fraction_HPP
#define Fraction_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int numerator, int denominator);
        Fraction(int numerator);
        Fraction();
        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int numerator);
        void setDenominator(int denominator);
        friend ostream &operator<<(ostream &os, const Fraction &f)
        {
            os << f.getNumerator() << "/" << f.getDenominator();
            return os;
        }
        friend istream &operator>>(istream &is, Fraction &f)
        {
            int numerator;
            int denominator;
            char c;
            is >> numerator >> c >> denominator;
            if (c != '/')
            {
                throw std::invalid_argument("Invalid input");
            }
            f.setNumerator(numerator);
            f.setDenominator(denominator);
            return is;
        }
        int findGCD(int a, int b)
        {
            if (b == 0)
            {
                return a;
            }
            return findGCD(b, a % b);
        }
        Fraction operator+(const Fraction &f);
        friend Fraction operator+(int num, const Fraction &f)
        {
            Fraction temp(num);
            return temp + f;
        }
        Fraction operator-(const Fraction &f);
        friend Fraction operator-(int num, const Fraction &f)
        {
            Fraction temp(num);
            return temp - f;
        }
        Fraction operator++(int);
        Fraction &operator++();
        Fraction operator--(int);
        Fraction &operator--();

    };
}

#endif /* Fraction_HPP */
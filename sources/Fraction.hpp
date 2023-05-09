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
        int findGCD(int a, int b)
        {
            if (b == 0)
            {
                return a;
            }
            return findGCD(b, a % b);
        }

    public:
        // constructors
        Fraction(int numerator, int denominator);
        Fraction(float num);
        Fraction(int numerator);
        Fraction();
        // Getters and Setters
        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int numerator);
        void setDenominator(int denominator);
        // operators
        Fraction operator+(const Fraction &f);
        Fraction operator-(const Fraction &f);
        Fraction operator*(const Fraction &f);
        Fraction operator/(const Fraction &f);
        Fraction operator++(int);
        Fraction &operator++();
        Fraction operator--(int);
        Fraction &operator--();
        bool operator==(const Fraction &f) const;
        bool operator>(const Fraction &f) const;
        bool operator<(const Fraction &f) const;
        bool operator>=(const Fraction &f) const;
        bool operator<=(const Fraction &f) const;

        // output and input operators
        friend ostream &operator<<(ostream &os, const Fraction &f)
        {
            os << f.getNumerator() << "/" << f.getDenominator();
            return os;
        }

        friend istream &operator>>(istream &is, Fraction &f)
        {
            int numerator = 1;
            int denominator = 1;

            if (is.peek() == EOF)
            {
                throw runtime_error("EOF Error");
            }
            is >> numerator;
            if (is.peek() == EOF)
            {
                throw runtime_error("EOF Error");
            }
            is >> denominator;
            if (denominator == 0)
            {
                throw runtime_error("Denominator is zero");
            }
            f = Fraction(numerator, denominator);
            return is;
        }

        // friend operators
        friend Fraction operator+(float num, const Fraction &f)
        {
            Fraction temp(num);
            return temp + f;
        }

        friend Fraction operator-(float num, const Fraction &f)
        {
            Fraction temp(num);
            return temp - f;
        }

        friend Fraction operator*(float num, const Fraction &f)
        {
            Fraction temp(num);
            return temp * f;
        }

        friend Fraction operator/(float num, const Fraction &f)
        {
            Fraction temp(num);
            return temp / f;
        }

        friend bool operator==(float num, const Fraction &f)
        {
            Fraction temp(num);
            return temp == f;
        }

        friend bool operator>(float num, const Fraction &f)
        {
            Fraction temp(num);
            return temp > f;
        }

        friend bool operator<(float num, const Fraction &f)
        {
            Fraction temp(num);
            return temp < f;
        }

        friend bool operator>=(float num, const Fraction &f)
        {
            Fraction temp(num);
            return temp >= f;
        }

        friend bool operator<=(float num, const Fraction &f)
        {
            Fraction temp(num);
            return temp <= f;
        }

        // floating point operators
        Fraction operator+(float num)
        {
            return *this + Fraction(num);
        }

        Fraction operator-(float num)
        {
            return *this - Fraction(num);
        }

        Fraction operator*(float num)
        {
            return *this * Fraction(num);
        }

        Fraction operator/(float num)
        {
            return *this / Fraction(num);
        }

        bool operator==(float num) const
        {
            return *this == Fraction(num);
        }

        bool operator>(float num) const
        {
            return *this > Fraction(num);
        }

        bool operator<(float num) const
        {
            return *this < Fraction(num);
        }

        bool operator>=(float num) const
        {
            return *this >= Fraction(num);
        }

        bool operator<=(float num) const
        {
            return *this <= Fraction(num);
        }
    };
}

#endif /* Fraction_HPP */
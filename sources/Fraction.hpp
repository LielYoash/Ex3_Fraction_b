#ifndef Fraction_HPP
#define Fraction_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits.h>
using namespace std;

namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;
        int findGCD(int num1, int num2)
        {
            if (num2 == 0)
            {
                return num1;
            }
            return findGCD(num2, num1 % num2);
        }


    public:
        // constructors
        Fraction(int numerator, int denominator);
        Fraction(float num);
        Fraction();
        // Getters and Setters
        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int numerator);
        void setDenominator(int denominator);
        // operators
        Fraction operator+(const Fraction &frac);
        Fraction operator-(const Fraction &frac);
        Fraction operator*(const Fraction &frac);
        Fraction operator/(const Fraction &frac);
        Fraction operator++(int);
        Fraction &operator++();
        Fraction operator--(int);
        Fraction &operator--();
        bool operator==(const Fraction &frac) const;
        bool operator>(const Fraction &frac) const;
        bool operator<(const Fraction &frac) const;
        bool operator>=(const Fraction &frac) const;
        bool operator<=(const Fraction &frac) const;

        // output and input operators
        friend ostream &operator<<(ostream &ost, const Fraction &frac)
        {
            ost << frac.getNumerator() << "/" << frac.getDenominator();
            return ost;
        }

        friend istream &operator>>(istream &ist, Fraction &frac)
        {
            int numerator = 1;
            int denominator = 1;

            if (ist.peek() == EOF)
            {
                throw runtime_error("EOF Error");
            }
            ist >> numerator;
            if (ist.peek() == EOF)
            {
                throw runtime_error("EOF Error");
            }
            ist >> denominator;
            if (denominator == 0)
            {
                throw runtime_error("Denominator is zero");
            }
            frac = Fraction(numerator, denominator);
            return ist;
        }

        // friend operators
        friend Fraction operator+(float num, const Fraction &frac)
        {
            Fraction temp(num);
            return temp + frac;
        }

        friend Fraction operator-(float num, const Fraction &frac)
        {
            Fraction temp(num);
            return temp - frac;
        }

        friend Fraction operator*(float num, const Fraction &frac)
        {
            Fraction temp(num);
            return temp * frac;
        }

        friend Fraction operator/(float num, const Fraction &frac)
        {
            Fraction temp(num);
            return temp / frac;
        }

        friend bool operator==(float num, const Fraction &frac)
        {
            Fraction temp(num);
            return temp == frac;
        }

        friend bool operator>(float num, const Fraction &frac)
        {
            Fraction temp(num);
            return temp > frac;
        }

        friend bool operator<(float num, const Fraction &frac)
        {
            Fraction temp(num);
            return temp < frac;
        }

        friend bool operator>=(float num, const Fraction &frac)
        {
            Fraction temp(num);
            return temp >= frac;
        }

        friend bool operator<=(float num, const Fraction &frac)
        {
            Fraction temp(num);
            return temp <= frac;
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
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
    this->numerator = numerator;
    this->denominator = denominator;
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
//                                      Methods                                      
//----------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------//
//                 Operators:        +         -        ++        --                 
//----------------------------------------------------------------------------------//
Fraction Fraction ::operator+(const Fraction &other)
{
    int newNumerator = (this->numerator * other.getDenominator()) + (other.getNumerator() * this->denominator);
    int newDenominator = this->denominator * other.getDenominator();
    int gcd = findGCD(newNumerator,newDenominator);
    return Fraction(newNumerator/gcd, newDenominator/gcd);
}

Fraction Fraction ::operator-(const Fraction &other)
{
    int newNumerator = (this->numerator * other.getDenominator()) - (other.getNumerator() * this->denominator);
    int newDenominator = this->denominator * other.getDenominator();
    int gcd = abs(findGCD(newNumerator,newDenominator));
    return Fraction(newNumerator/gcd, newDenominator/gcd);
}

Fraction Fraction ::operator++(int num){
    Fraction temp(this->numerator, this->denominator);
    this->numerator += this->denominator;
    return temp;
}

Fraction& Fraction ::operator++(){
    this->numerator += this->denominator;
    return *this;
}

Fraction Fraction ::operator--(int num){
    Fraction temp(this->numerator, this->denominator);
    this->numerator -= this->denominator;
    return temp;
}

Fraction& Fraction ::operator--(){
    this->numerator -= this->denominator;
    return *this;
}

//----------------------------------------------------------------------------------//
//                                Operator:        ==                                
//----------------------------------------------------------------------------------//

Fraction Fraction ::operator==(const Fraction &other)




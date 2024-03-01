/**
 * Creates a complex number of the form a + bi, where a is a real integer and b is the
 * imaginary portion.
 */

#include <cmath>
#include <iostream>

namespace jlr
{


    class ComplexNumber
{

        // public functions and variables
    public:

        /*
         * Constructor that can be used explicitly or implicitly
         *
         * PreCondition: none
         * PostCondition: The equivalency of two ComplexNumbers
         */
        ComplexNumber(double real = 2, double imaginary = 3)
        {
            a = real;
            b = imaginary;
        }

        /*
         * Overrides the + operator to add two ComplexNumbers
         *
         * PreCondition: none;
         * PostCondition: The sum of two ComplexNumbers
         */
        ComplexNumber operator+(ComplexNumber num)
        {
            double d = a + num.a;
            double e = b + num.b;

            return ComplexNumber(d, e);
        }

        /*
         * Overrides the - operator to subtract ComplexNumbers
         *
         * PreCondition: none
         * PostCondition: The difference of two ComplexNumbers
         */
        ComplexNumber operator-(ComplexNumber num)
        {
            double d = a - num.a;
            double e = b - num.b;

            return ComplexNumber(d, e);
        }

        /*
         * Overrides the * operator to multiply ComplexNumbers
         *
         * PreCondition: none
         * PostCondition: The product of two ComplexNumbers
         */
        ComplexNumber operator*(ComplexNumber num)
        {
            double d = (a * num.a) - (b * num.b);
            double e = (a * num.b) + (b * num.a);

            return ComplexNumber(d, e);
        }

        /*
         * Overrides the / operator to divide ComplexNumbers
         *
         * PreCondition: none
         * PostCondition: The quotient of two ComplexNumbers
         */
        ComplexNumber operator/(ComplexNumber num)
        {
            double rNum = (a * num.a) + (b * num.b);
            double iNum = (b * num.a) - (a * num.b);
            double denominator = pow(num.a, 2) + pow(num.b, 2);

            return ComplexNumber(rNum / denominator, iNum / denominator);
        }

        /*
         * Overrides the == operator to determine if two ComplexNumbers are equal
         */
        bool operator==(ComplexNumber num)
        {
            // if the real and imaginary numbers are equal, return true
            if (a == num.a && b == num.b)
            {
                return true;
            }
            // return false if not equivalent
            return false;
        }

        /*
         * Determines the magnitude of a complex number
         */
        double magnitude()
        {
            double d = pow(a, 2);
            double e = pow(b, 2);

            return sqrt(d + e);
        }

        /*
         * Overloads the << operator to print a complex number in the form a + bi
         *
         * PreCondition: none
         * PostCondition: Complex number is printed
         */
        friend std::ostream &operator<<(std::ostream &out, ComplexNumber num)
        {
            out << num.a;
            out << " + ";
            out << num.b << "i";
            return out;
        }

        /*
         * Overloads the >> operator to retrieve a complex number from the console
         *
         * PreCondition: Complex number must be in the form of a + bi or a+bi
         * PostCondition: Complex number is extracted
         */
        friend std::istream &operator>>(std::istream &in, ComplexNumber &num)
        {
            in >> num.a;
            in.ignore(1, '+');
            in >> num.b;
            in.ignore(1, 'i');
            return in;
        }

        // private functions and variables
    private:
        double a; // real part
        double b; // imaginary part
    };
}
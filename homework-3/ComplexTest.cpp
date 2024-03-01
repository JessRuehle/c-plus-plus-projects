/**
 * Driver program to test the functionality of the ComplexNumber class and its functions.
 */
#include "ComplexNumber.cpp"
#include <iostream>

using namespace std;
using namespace jlr;

int main() {
    cout << "Demonstration of The ComplexNumbers Class" << endl;
    cout << endl;

    // Demonstrating three ways to create a ComplexNumber
    ComplexNumber num1;
    ComplexNumber num2(4, 5);
    ComplexNumber num3;
    ComplexNumber num4(4, 5);

    cout << "Please enter a complex number in the form of a + bi:" << endl;
    cin >> num3;
    cout << "Your complex number: " << num3 << endl;
    cout << "Using the default constructor parameters: " << num1 << endl;
    cout << "Assigning 4 and 5 to the complex number through arguments: " << num2 << endl;
    cout << endl;

    // Adding ComplexNumbers
    cout << "Adding together ComplexNumbers:" << endl;
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout << endl;

    // Subtracting ComplexNumbers
    cout << "Subtracting the first complex number from the second:" << endl;
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    cout << "Subtracting the second complex number from the first:" << endl;
    cout << num2 << " - " << num1 << " = " << num2 - num1 << endl;
    cout << endl;

    // Multiplying ComplexNumbers
    cout << "Multiplying ComplexNumbers:" << endl;
    cout << num3 << " * " << num2 << " = " << num3 * num2 << endl;
    cout << endl;

    // Dividing ComlexNumbers
    cout << "Diving ComplexNumbers:" << endl;
    cout << num3 << " / " << num2 << " = " << num3 / num2 << endl;
    cout << endl;

    // Magnitude of ComplexNumbers
    cout << "The magnitude of ComplexNumbers:" << endl;
    cout << num1 << "- Magnitude = " << num1.magnitude() << endl;
    cout << num2 << "- Magnitude = " << num2.magnitude() << endl;
    cout << num3 << "- Magnitude = " << num3.magnitude() << endl;
    cout << endl;

    // Equivalency of ComplexNumbers
    cout << "Comparing equivalency of ComplexNumbers:" << endl;
    cout << "Are " << num1 << " and " << num2 << " equal? ";
    if (num1 == num2)
    {
        cout << "Yes!" << endl;
    } else
    {
        cout << "No." << endl;
    }

    cout << "Are " << num2 << " and " << num4 << " equal? ";
    if (num2 == num4)
    {
        cout << "Yes!" << endl;
    } else
    {
        cout << "No." << endl;
    }
    cout << endl;

    cout << "All functions have successfully been tested." << endl;

    return 0;
}
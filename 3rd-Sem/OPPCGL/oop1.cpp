#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    // Overloaded + operator to add two complex numbers
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloaded * operator to multiply two complex numbers
    Complex operator*(const Complex &other) const
    {
        double newReal = real * other.real - imag * other.imag;
        double newImag = real * other.imag + imag * other.real;
        return Complex(newReal, newImag);
    }

    // Overloaded << operator to print a complex number
    friend ostream &operator<<(ostream &os, const Complex &num)
    {
        os << num.real;
        if (num.imag >= 0)
        {
            os << " + " << num.imag << "i";
        }
        else
        {
            os << " - " << -num.imag << "i";
        }
        return os;
    }

    // Overloaded >> operator to read a complex number
    friend istream &operator>>(istream &is, Complex &num)
    {
        cout << "Enter real part: ";
        is >> num.real;
        cout << "Enter imaginary part: ";
        is >> num.imag;
        return is;
    }
};


int main()
{
    Complex num1, num2;

    cout << "Enter the first complex number:\n";
    cin >> num1;

    cout << "Enter the second complex number:\n";
    cin >> num2;

    Complex sum = num1 + num2;
    Complex product = num1 * num2;

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    return 0;
}
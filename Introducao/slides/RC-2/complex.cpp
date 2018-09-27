#include <cmath>
#include <complex.h>

using namespace std;

ostream& operator<<(ostream& os, const Complex& c)
{
    os << c.real();
    
    if (c.imag())
    {
        os << (c.imag() > 0 ? " + " : " - ");
        os << abs(c.imag()) << "i";
    }
    
    return os;
}

Complex::Complex(double r, double i) : _real(r), _imag(i)
{
}

double Complex::real() const {
    return _real;
}

double Complex::imag() const {
    return _imag;
}
    
void Complex::set_real(double real) {
    _real = real;
}

void Complex::set_imag(double imag) {
    _imag = imag;
}

Complex Complex::operator+(const Complex& c)
{
    return Complex(_real + c.real(), _imag + c.imag());
}

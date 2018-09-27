#ifndef COMPLEX_H
#define COMPLEX_H

#include <ostream>

class Complex {
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
public:
    Complex(double real = 0.0, double imag = 0.0);
    
    double real() const;
    double imag() const;
    void set_real(double real);
    void set_imag(double imag);
    
    Complex operator+(const Complex& c);
private:
    double _real, _imag;
};

#endif

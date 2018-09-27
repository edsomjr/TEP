#include <iostream>
#include <complex.h>

using namespace std;

int main()
{
    Complex a(1, -1), b(0, 2);
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    a.set_real(3);
    b.set_imag(4);

    cout << "a + b = " << a + b << endl;
    
    return 0;
}

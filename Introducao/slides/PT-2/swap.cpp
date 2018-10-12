#include <iostream>

using namespace std;

void swap_por_valor(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void swap_com_ponteiros(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap_por_referencia(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int x = 1, y = 2;
    
    cout << "Valores iniciais: x = " << x << ", y = " << y << endl;
    
    swap_por_valor(x, y);
    cout << "swap_por_valor(): x = " << x << ", y = " << y << endl;
    
    swap_por_referencia(x,y);
    cout << "swap_por_referencia(): x = " << x << ", y = " << y << endl;
    
    swap_com_ponteiros(&x, &y);
    cout << "swap_com_ponteiros(): x = " << x << ", y = " << y << endl;
    
    return 0;
}

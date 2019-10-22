#include <iostream>

int sinal(long int numero) {
    if (numero >= 0)
        return 1;
    else 
        return -1; 
}

int main() {
    long numero;
    
    std::cout << "Insira um número: ";
    std::cin >> numero;
    
    std::cout << "Sinal do numero: " << (sinal(numero) > 0 ? '+' : '-')
        << std::endl;
    
    return 0;
}

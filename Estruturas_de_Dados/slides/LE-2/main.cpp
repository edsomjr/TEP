#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List<int> list;

    cout << "Lista vazia? " << (list.empty() ? "Sim" : "Nao") << endl;

    for (int n = 1; n <= 10; ++n)
        list.push_back(n);

    list.pop_front();
    cout << "Tamanho da lista: " << list.size() << endl;
    cout << "Primeiro elemento: " << list.front() << endl;
    cout << "Último elemento: " << list.back() << endl;

    return 0;
}

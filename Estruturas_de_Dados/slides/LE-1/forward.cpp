#include <iostream>
#include <algorithm>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> list;

    cout << "Lista vazia? " << (list.empty() ? "Sim" : "Nao") << endl;

    for (int n = 1; n <= 10; ++n)
        list.push_front(n);

    list.pop_front();

    // Complexidade linear
    int size = distance(list.begin(), list.end());
    cout << "Tamanho da lista: " << size << endl;

    cout << "Primeiro elemento: " << list.front() << endl;

    // Complexidade linear
    int last = -1;

    for (auto it = list.begin(); it != list.end(); ++it)
        last = *it;

    cout << "Último elemento: " << last << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_set<int> xs { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };

    auto N = xs.size();         // N = 9, o elemento 1 é inserido
                                // uma única vez

    auto p = xs.insert(4);      // p.second = true, inserção bem
                                // sucedida

    p = xs.insert(8);           // p.second = false, 8 já pertence
                                // ao conjunto

    auto x = *p.first;          // x = 8, p.first aponta para o
                                // elemento inserido

    p = xs.emplace(10);         // p.second = true;
    
    N = xs.size();              // N = 11

    auto it = xs.find(5);       // Localiza o elemento 5

    it = xs.erase(it);          // remove o elemento 5
                                // it aponta para o próximo elemento

    x = xs.count(1);            // x = 1, apenas uma cópia de 1
                                // no contêiner

    x = xs.count(20);           // x = 0

    for (const auto& x : xs)
        cout << x << ' ';       // 10 1 34 2 13 3 8 21 55 4 
    cout << '\n';

    return 0;
}

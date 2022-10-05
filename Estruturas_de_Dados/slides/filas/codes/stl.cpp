#include <bits/stdc++.h>

int main()
{
    std::queue<std::string> q { "um", "dois", "tres" };

    std::cout << "Vazia? " << q.empty() << '\n';                 // Falso

    std::cout << "Primeiro elemento: " << q.front() << '\n';     // "um"
    std::cout << "Último elemento: " << q.back() << '\n';        // "tres"

    q.push("quatro");

    std::cout << "Tamanho da fila: " << q.size() << '\n';        // 4

    q.pop();
    std::cout << "Primeiro elemento: " << q.front() << '\n';     // "dois"

    return 0;
}

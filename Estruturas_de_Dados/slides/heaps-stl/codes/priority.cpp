#include <bits/stdc++.h>

using namespace std;

struct Paciente {
    string nome; int idade;

    Paciente(const string& n, int a) : nome(n), idade(a) {}

    bool operator<(const Paciente& p) const {
        // Idosos tem maior prioridade, mais velhos primeiro
        if (idade >= 65) return idade < p.idade;

        // Depois crianças, mais novas primeiro
        if (idade <= 6) return p.idade >= 65 or (p.idade <= 6 and idade > p.idade);

        // Os demais por idade
        return p.idade >= 65 or p.idade <= 6 or p.idade > idade;
    }
};

int main()
{
    priority_queue<Paciente> pq;

    pq.push(Paciente("Maria", 25));
    pq.push(Paciente("Carlos", 70));
    pq.push(Paciente("Neto", 4));
    pq.push(Paciente("Laura", 25));
    pq.push(Paciente("Beatriz", 32));
    pq.push(Paciente("Pedro", 5));
    pq.push(Paciente("Beto", 68));

    while (not pq.empty()) {
        auto p = pq.top(); pq.pop();
        cout << p.nome << ": " << p.idade << " anos\n";
    }

    return 0;
}

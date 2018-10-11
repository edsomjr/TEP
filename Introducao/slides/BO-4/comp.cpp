#include <iostream>
#include <algorithm>

using namespace std;

void print(const string as[], int N) {
    for (int i = 0; i < N; ++i)
        cout << as[i] << (i + 1 == N ? "\n" : ", ");
}

// Primeira forma: não diferencia maiúsculas de minúsculas
bool compare(const string& a, const string& b)
{
    string x, y;
    auto to_lower = [](char c) { return tolower(c); };

    transform(a.begin(), a.end(), back_inserter(x), to_lower);
    transform(b.begin(), b.end(), back_inserter(y), to_lower);

    return x < y;
}

// Terceira forma: primeiro por tamanho, depois lexicográfico
struct Compare
{
    bool operator()(const string& a, const string& b)
    {
        int N = a.size(), M = b.size();
        return N != M ? N < M : a < b;
    }
};

int main()
{
    string as[] { "verde", "amarelo", "Vermelho", "Branco", "Preto", 
        "azul" };
    int N = 6;

    // Ordenação lexicográfica
    sort(as, as + N);
    print(as, N);       // Branco, Preto, Vermelho, amarelo, azul, verde

    // Ordenação lexicográfica inversa
    sort(as, as + N, greater<string>());
    print(as, N);       // verde, azul, amarelo, Vermelho, Preto, Branco

    // Ordenação case-insensitive
    sort(as, as + N, compare);
    print(as, N);       // amarelo, azul, Branco, Preto, verde, Vermelho

    // Ordenação por tamanho, depois lexicográfica
    sort(as, as + N, Compare());
    print(as, N);       // azul, Preto, verde, Branco, amarelo, Vermelho
 
    // Segunda forma
    // Primeiro inicial minúscula, depois maiúscula, lexicográfica
    sort(as, as + N, [](const string& a, const string& b) {
        auto x = islower(a[0]), y = islower(b[0]);
        return x == y ? a < b : (x ? true : false); });
    print(as, N);       // amarelo, azul, verde, Branco, Preto, Vermelho

    return 0;
}

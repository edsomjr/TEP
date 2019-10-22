#include <functional>
#include <iostream>
#include <cctype>

using namespace std;

// O nome smap ('string map') foi utilizado para evitar
// confusão com a classe map da STL
string smap(const string& s, const function<char(char)>& f)
{
    string y;

    for (const auto& c : s)
        y.push_back(f(c));

    return y;
}

int main()
{
    string s = "Teste de mapeamento";
    auto y = smap(s, [](char c) { return (char) toupper(c); });

    cout << y << '\n';

    return 0;
}

#include <bits/stdc++.h>

std::string smap(const std::string& s, const std::function<char(char)>& f)
{
    std::string y;

    for (const auto& c : s)
        y.push_back(f(c));

    return y;
}

int main()
{
    std::string s = "Teste de mapeamento";
    std::cout << smap(s, [](char c) { return (char) toupper(c); }) << '\n';

    return 0;
}

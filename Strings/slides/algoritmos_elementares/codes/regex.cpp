#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Toda a string tem que casar com o padrão
    if (regex_match("123.456.789-10", regex("([0-9]{3}\\.){2}[0-9]{3}-[0-9]{2}")))
        cout << "CPF ok\n";

    string s { "# Cpp regex example 2" };
    regex r { "([aeiou][^aeiou ]){2}" };
    smatch sm;

    // Identifica a primeira substring que casa com o padrão
    if (regex_search(s, sm, r))
        cout << "Match: '" << sm[0] << "' on index " << sm.prefix().length() << '\n';
    
    return 0;
}

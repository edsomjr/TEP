#include <bits/stdc++.h>

using namespace std;

int main()
{
    const string vowels { "aeiou" };
    string message { "Exemplo de busca sequencial" }, res;

    auto P = [&vowels](char c) { return vowels.find(c) != string::npos; };

    copy_if(message.begin(), message.end(), back_inserter(res), P);
        
    if (res.empty())
        cout << "Nenhuma vogal encontrada\n";
    else
        cout << res.size() << " vogais encontradas: " << res << "\n";

    return 0;
}

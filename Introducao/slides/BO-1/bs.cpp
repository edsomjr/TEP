#include <iostream>
#include <algorithm>

using namespace std;

const string vowels { "aeiou" };

int main()
{
    string message { "Exemplo de busca sequencial" }, res;

    copy_if(message.begin(), message.end(), back_inserter(res), 
        [](char c) { return vowels.find(c) != string::npos; });

    if (res.empty())
        cout << "Nenhuma vogal encontrada\n";
    else
            cout << res.size() << " vogais encontradas: " << res << "\n";

    return 0;
}

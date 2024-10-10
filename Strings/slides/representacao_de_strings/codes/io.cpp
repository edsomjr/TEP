#include <iostream>

using namespace std;

// Assuma que será inserida em uma linha, via console, a mensagem
// "Teste de I/O em C++"
int main()
{
    string s, line;

    cin >> s;
    cout << "s = [" << s << "]\n";              // s = [Teste]

    getline(cin, line);
    cout << "line = [" << line << "]\n";        // line = [ de I/O em C++]

    return 0;
}

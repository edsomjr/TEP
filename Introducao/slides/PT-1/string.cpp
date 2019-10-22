#include <iostream>

using namespace std;

int main() {
    string s1 = "UnB - FGA";
    string s2 = "EDA";
    
    cout << s1 << " = " << s1.size() << " caracteres" << endl;

    cout << "Primeira string, na ordem alfabética: " 
        << (s1.compare(s2) > 0 ? s2 : s1) << endl;

    cout << "Localização do F: " << s1.find('F') << endl;

    cout << "Cópia: " << (s1 = s2) << endl;

    cout << "Concatenação: " << s1 + s2 << endl;

    return 0;
}

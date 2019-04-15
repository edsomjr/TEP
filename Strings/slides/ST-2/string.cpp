#include <iostream>

using namespace std;

int main()
{
    string a { "Test" }, b { "TEP" };

    // Tamanho da string
    int s = a.size();       // s = 4
    s = b.size();           // s = 3

    // Comparação
    bool r = (a == b);      // r = false, "Test" e "TEP" são distintas
    r = (a != b);           // r = true, "Test" e "TEP" são distintas
    r = (a < b);            // r = false, "Test" sucede "TEP" na ordem
                            // lexicográfica
    r = (a > b);            // r = true, "Test" sucede "TEP" na ordem
                            // lexicográfica

    s = a.compare(0, 1, b); // s = 0, as strings são iguais no 
                            // primeiro caractere
    s = a.compare(0, 2, b); // s > 0, "Te" sucede "TE" na ordem
                            // lexicográfica

    // Cópia
    a = b;                  // a = "TEP"

    // Acesso aos elementos individuais
    a[1] = 'A';             // a = "TAP"
    auto c = a.front();     // c = 'T', primeiro elemento
    c = a.back();           // c = 'P', último elemento

    // Conversão de string para valores numéricos
    a = "123.45";
    auto d = stod(a);       // d = 123.45;
    auto i = stoi(a);       // i = 123

    a = "10000000000000000000000000000000000000000";
    auto ll = stoll(a, NULL, 2);   // ll = 1099511627776, conversão de
                                   // base binária

    // Conversão de valores numéricos para strings
    a = to_string(999);     // a = "999"
    a = to_string(9.99);    // a = "9.99"

    // Concatenação
    b = "xyz";              // b = "xyz"
    a = "abcba";            // a = "abcba"

    a +=  b;                // a = "abcbaxyz"
    a += a.substr(0, 3);    // a = "abcbaxyzabc"

    // Busca de caracteres
    auto p = a.find('b');   // p = 1, índice da primeira
                            // ocorrência de 'b'
    p = a.rfind('b');       // p = 9, índice da última
                            // ocorrência de 'b'
    p = a.find("cba");      // p = 2, índice da primeira
                            // ocorrência de "cba"
    p = a.find("dd");       // p = string::npos, "dd" não é
                            // substring de a

    p = a.find_first_not_of("abc");     // i = 5, a[0..4] contém apenas
                                        // caracteres em "abc"
    p = a.find_first_of("z");           // i = 7, a[0..6] contém
                                        // caracteres diferentes de "z"

    // Exemplo de uso do método c_str()
    a = "Test";
    printf("%s\n", a.c_str());

    return 0;
}

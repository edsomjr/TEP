#include <set>
#include <string>

#include <iostream>

int main()
{
    std::set<int> s1;       // Conjunto de inteiros vazio

    std::string s { "Teste" };
    std::set<char> s2(s.begin() + 1, s.end());  // s2 = { 'e', 's', 't' }

    std::set<char> s3(s2);                      // s3 == s2     

    std::set<char> s4(std::move(s3));           // s4 == s2, s3 vazio

    std::set<double> s5 { 2.0, 1.5, 3.7 };      // s5 = { 1.5, 2.0, 3.7 }

    return 0;
}

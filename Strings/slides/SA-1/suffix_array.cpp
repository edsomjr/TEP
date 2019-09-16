#include <bits/stdc++.h>

using namespace std;

vector<int> counting_sort(const string& s)
{
    static const int A { 256 };     // Tamanho do alfabeto

    // Gera o histograma dos caracteres
    vector<int> hs(A, 0);

    for (auto c : s)
        ++hs[c];
    
vector<char> ls;
for (int i = 1; i < A; ++i)
{
    if (hs[i])
    {
        ls.push_back(i);
        cout << (char) i << ": " << hs[i] << '\n';
    }
}
    // Faz a soma prefixada para estabelecer a ordem
    for (int i = 1; i < A; ++i)
        hs[i] += hs[i - 1];

for (const auto& l : ls)
{
    cout << (char) l << ": " << hs[l] << '\n';
}
    // Preenche a permutação referente à ordenação
    vector<int> ps(s.size());

    for (size_t i = 0; i < s.size(); ++i)
    {
        cout << "hs[" << s[i] << "] = " << hs[s[i]] << ", i = " << i << '\n';
        ps[i] = --hs[s[i]];
        
cout << "ps = ";
for (size_t i = 0; i < ps.size(); ++i)
    cout << ps[i] << (i + 1 == ps.size() ? '\n' : ' ');
    }

    return ps;
}

vector<int> suffix_array(const string& s)
{
    auto ps = counting_sort(s);

    return ps;
}

int main()
{
    string s;
    cin >> s;

    int N = s.size();
    auto sa = suffix_array(s);

    for (int i = 0; i < N; ++i)
        cout << sa[i] << '\t' << s.substr(sa[i]) << '\n';

    return 0;
}

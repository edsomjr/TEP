#include <bits/stdc++.h>

using namespace std;

vector<int> counting_sort(const string& s)
{
    static const int A { 256 };     // Tamanho do alfabeto

    // Gera o histograma dos caracteres
    vector<int> hs(A, 0);

    for (auto c : s)
        ++hs[c];

    // Faz a soma prefixada para estabelecer a ordem
    for (int i = 1; i < A; ++i)
        hs[i] += hs[i - 1];

    // Preenche a permutação referente à ordenação
    vector<int> ps(s.size());

    for (size_t i = 0; i < s.size(); ++i)
        ps[--hs[s[i]]] = i;

    return ps;
}

vector<int> equivalence_classes(const string& s, const vector<int>& ps)
{
    int c = 0;
    vector<int> cs(ps.size());

    cs[ps[0]] = c;

    // Processa os elementos de s na ordem indicada pela permutação
    for (size_t i = 1; i < ps.size(); ++i)
    {
        // Elementos distintos pertencem a classes distintas
        if (s[ps[i]] != s[ps[i - 1]])
            ++c;    

        cs[ps[i]] = c;
    }

    return cs;
}

void update_equivalence_classes(vector<int>& cs, const vector<int>& ps)
{
}

vector<int> suffix_array(const string& s)
{
    auto ps = counting_sort(s);
    auto cs = equivalence_classes(s, ps);

cout << "ps = ";
for (auto c : ps)
    cout << c << ' ';
cout << '\n';

cout << "cs = ";
for (auto c : cs)
    cout << c << ' ';
cout << '\n';

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

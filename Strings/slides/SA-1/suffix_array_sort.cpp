#include <bits/stdc++.h>

using namespace std;
using iii = tuple<int, int, int>;   // (cs[i], cs[i + 2^k], i)

void update_permutations(vector<int>& ps, vector<iii>& pps)
{
    // Ordena os pares
    sort(pps.begin(), pps.end());

    // Atualiza as permutações e remove a referência
    for (size_t i = 0; i < ps.size(); ++i)
    {
        ps[i] = get<2>(pps[i]);
        get<2>(pps[i]) = 0;
    }
}

void update_equivalence_classes(vector<int>& cs,
    const vector<int>& ps, const vector<iii>& pps)
{
    int c = 0;
    cs[ps[0]] = c;

    // O vetor pps está ordenado
    for (size_t i = 1; i < ps.size(); ++i)
    {
        // Elementos distintos pertencem a classes distintas
        if (pps[i - 1] != pps[i])
            ++c;

        cs[ps[i]] = c;
    }
}

vector<int> suffix_array(const string& S)
{
    auto s = S + "$";
    auto N = s.size();

    vector<int> ps(N), cs(N);
    vector<iii> pps(N);

    // Caso base
    for (size_t i = 0; i < N; ++i)
        pps[i] = iii(s[i], s[i], i);

    update_permutations(ps, pps);
    update_equivalence_classes(cs, ps, pps);

    // Transições: mask = 2^(k - 1)
    for (size_t mask = 1; mask < N; mask <<= 1)
    {
        for (size_t i = 0; i < N; ++i)
            pps[i] = iii(cs[i], cs[(i + mask) % N], i);

        update_permutations(ps, pps);
        update_equivalence_classes(cs, ps, pps);
    }

    ps.erase(ps.begin());

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

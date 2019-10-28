#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;

template<typename T> void
counting_sort(vi& ps, const T& xs, size_t alphabet_size)
{
    // Gera o histograma dos elementos distintos
    vector<int> hs(alphabet_size, 0);

    for (auto x : xs)
        ++hs[x];

    // Faz a soma prefixada para estabelecer a ordem
    for (size_t i = 1; i < alphabet_size; ++i)
        hs[i] += hs[i - 1];

    // Preenche a permutação referente à ordenação
    for (int i = ps.size() - 1; i >= 0; --i)
        ps[--hs[xs[i]]] = i;
}

template<typename T> int
update_equivalence_classes(vi& cs, const vi& ps, const T& xs)
{
    int c = 0;
    cs[ps[0]] = c;

    // Processa os elementos de s na ordem indicada pela permutação
    for (size_t i = 1; i < ps.size(); ++i)
    {
        // Elementos distintos pertencem a classes distintas
        if (xs[ps[i - 1]] != xs[ps[i]])
            ++c;

        cs[ps[i]] = c;
    }

    // Retorna o número de classes distintas
    return c + 1;
}

vector<int> suffix_array(const string& S)
{
    auto s = S + "$";
    auto N = s.size();

    vector<int> ps(N), cs(N), rs(N), xs(N);
    vector<ii> ys(N);

    // Caso base
    counting_sort(ps, s, 256);
    int c = update_equivalence_classes(cs, ps, s);

    // Transições: mask = 2^(k - 1)
    for (size_t mask = 1; mask < N; mask <<= 1)
    {
        // Atualiza as permutações e gera os pares
        for (size_t i = 0; i < N; ++i)
        {
            rs[i] = (ps[i] + N - mask) % N;
            xs[i] = cs[rs[i]];
            ys[i] = ii(cs[i], cs[(i + mask) % N]);
        }

        // Gera a permutação que ordena rs, usando as classes xs
        counting_sort(ps, xs, c);

        // Atualiza ps a partir da ordenação de rs
        for (size_t i = 0; i < N; ++i)
            ps[i] = rs[ps[i]];

        // Atualiza cs a partir dos pares de classes de equivalência
        c = update_equivalence_classes(cs, ps, ys);
    }

    ps.erase(ps.begin());

    return ps;
}

vector<int> build_lcp(const string& S)
{
    auto sa = suffix_array(S);
    int N = S.size(), k = 0;

    vector<int> rank(N, 0);

    for (int i = 0; i < N; ++i)
        rank[sa[i]] = i;

    vector<int> lcp(N - 1, 0);

    for (int i = 0; i < N; ++i)
    {
        if (rank[i] == N - 1)
        {
            k = 0;
            continue;
        }

        auto j = sa[rank[i] + 1];

        while (i + k < N and j + k < N and S[i + k] == S[j + k])
            ++k;

        lcp[rank[i]] = k;

        if (k)
            --k; 
    }

    return lcp;
}

long long distinct_substrings(const string& S)
{
    auto lcp = build_lcp(S);
    long long N = S.size();
    long long ans = N*(N + 1)/2;

    for (auto x : lcp)
        ans -= x;

    return ans;
}

int main()
{
    //string s { "abababcabcacb" };
    string s;
    cin >> s;

    auto sa = suffix_array(s);
    auto lcp = build_lcp(s);
    int N = s.size();

    cout << "sa =\n";
    for (int i = 0; i < N; ++i)
        cout << i << '\t' << sa[i] << '\t' << s.substr(sa[i]) << '\n';

    cout << "lcp =\n";
    for (size_t i = 0; i < lcp.size(); ++i)
        cout << lcp[i] << (i + 1 == lcp.size() ? '\n' : ' ');

    cout << distinct_substrings(s) << '\n';

    return 0;
}

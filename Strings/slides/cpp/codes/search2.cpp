#include <bits/stdc++.h>

using namespace std;

double benchmark(const string& S, const string& P, const function<void(string,string)>& f)
{
    auto start = chrono::high_resolution_clock::now();
    f(S, P);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> d = end - start;

    return d.count();
}

int main()
{
    string S(1'000'000, 'a'), P { string(1'000, 'a') + 'b' };

    auto base = benchmark(S, P, [](auto s, auto p) 
        { for (size_t i = 0; i < s.size() + p.size(); ++i) {} });

    cout.precision(6);
    cout << "Empty loop: \t\t" << base << " s\t\t-\n";

    auto runtime = benchmark(S, P, [](auto s, auto p) { (void) s.find(p); });

    cout << "find(): \t\t" << runtime << " s\t\tx" << (int) round(runtime/base) << "\n";

    runtime = benchmark(S, P, [](auto s, auto p) 
    {
        search(s.begin(), s.end(), p.begin(), p.end());
    });

    cout << "search(): \t\t" << runtime << " s\t\tx" << (int) round(runtime/base) << "\n";

    runtime = benchmark(S, P, [](auto s, auto p) 
    {
        search(s.begin(), s.end(), boyer_moore_searcher(p.begin(), p.end()));
    });

    cout << "boyer_moore: \t\t" << runtime << " s\t\tx" << (int) round(runtime/base) << "\n";

    runtime = benchmark(S, P, [](auto s, auto p) 
    {
        search(s.begin(), s.end(), boyer_moore_horspool_searcher(p.begin(), p.end()));
    });

    cout << "boyer_moore_horspool: \t" << runtime << " s\t\tx"
        << (int) round(runtime/base) << "\n";

    // Possível saída:
    // Algoritmo                Runtime (em s)      runtime/empty
    // Empty loop:              0.00378854          -
    // find():                  0.0930658           x25
    // search():                4.07972             x1077
    // boyer_moore:             0.0121259           x3
    // boyer_moore_horspool:    0.00646972          x2

    return 0;
}

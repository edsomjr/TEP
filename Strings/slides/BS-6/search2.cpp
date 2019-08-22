#include <bits/stdc++.h>

using namespace std;

double benchmark(const string& S, const string& P,
                 const function<void(string,string)>& f)
{
    auto start = chrono::high_resolution_clock::now();
    f(S, P);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> d = end - start;

    return d.count();
}

int main()
{
    string S(1000000, 'a'), P { string(1000, 'a') + 'b' };

    auto base = benchmark(S, P, [](auto s, auto p) 
        { for (size_t i = 0; i < s.size() + p.size(); ++i) {} });

    cout.precision(6);
    cout << "Empty loop: \t\t" << base << " ms\t\t-\n";

    auto runtime = benchmark(S, P, [](auto s, auto p) { s.find(p); });

    cout << "find(): \t\t" << runtime << " ms\t\tx"
        << (int) round(runtime/base) << "\n";

    runtime = benchmark(S, P, [](auto s, auto p) 
    {
        search(s.begin(), s.end(), p.begin(), p.end());
    });

    cout << "search(): \t\t" << runtime << " ms\t\tx" 
        << (int) round(runtime/base) << "\n";

    runtime = benchmark(S, P, [](auto s, auto p) 
    {
        search(s.begin(), s.end(),
              boyer_moore_searcher(p.begin(), p.end()));
    });

    cout << "boyer_moore: \t\t" << runtime << " ms\t\tx" 
        << (int) round(runtime/base) << "\n";

    runtime = benchmark(S, P, [](auto s, auto p) 
    {
        search(s.begin(), s.end(),
               boyer_moore_horspool_searcher(p.begin(), p.end()));
    });

    cout << "boyer_moore_horspool: \t" << runtime << " ms\t\tx"
        << (int) round(runtime/base) << "\n";

    // Possível saída:
    // Algoritmo                Runtime (em ms)       runtime/empty
    // Empty loop:              0.000537077 ms        -
    // find():                  0.027087 ms           x50
    // search():                0.589431 ms           x1097
    // boyer_moore:             0.00420558 ms         x8
    // boyer_moore_horspool:    0.00327 ms            x6

    return 0;
}

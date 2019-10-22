#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<string, double> hs { 
        { "Maria", 1.68 },
        { "Lucas", 1.59 },
        { "Pedro", 1.72 },
        { "Joana", 1.81 },
        { "Alberto", 1.85 },
    };

    auto N = hs.size();             // N = 5
    auto p = hs.insert(make_pair("Carlos", 1.79));  // p.second = true, 
                                                    // inserção ok

    hs["Maria"] = 1.70;             // Altera o valor associado à Maria
    N = hs.size();                  // N = 6

    auto it = hs.find("Roberto");   // it = hs.end()
    it = hs.find("Lucas");          // it->second = 1.59

    auto x = hs.count("Pedro");     // x = 1
    it = hs.erase(it);              // remove Lucas

    x = hs.bucket_count();          // x = 7 buckets

    // Mostra a quantidade de elementos em cada bucket
    for (size_t i = 0; i < x; ++i)
        cout << hs.bucket_size(i) << ' ';
    cout << '\n';                   // 0 1 3 0 0 0 1 

    x = hs.max_bucket_count();      // x = 329406144173384850

    auto y = hs.load_factor();      // y = 0.714286, size()/bucket_count()
    y = hs.max_load_factor();       // y = 1

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int E(int n, int p)
{
    int k = 0, base = p;

    while (base <= n)
    {
        k += n / base;
        base *= p;
    }

    return k;
}

map<int, int> fact_factorization(int n)
{
    map<int, int> fs;

    for (auto p : { 2, 3, 5, 7 })
        fs[p] = E(n, p);

    return fs;
}

vector<int> histogram(long long n)
{
    vector<int> hs(10, 0);

    while (n)
    {
        ++hs[n % 10];
        n /= 10;
    }

    return hs;
}

string solve(long long a)
{
    auto hs = histogram(a);
    map<int, int> fs;

    for (int i = 2; i <= 9; ++i)
        for (auto [p, k] : fact_factorization(i))
            fs[p] += k*hs[i];

    string ans;

    for (auto p : { 7, 5, 3, 2 })
    {
        auto qs = fact_factorization(p);
        auto n = fs[p];

        for (auto q : { 2, 3, 5, 7 })
            if (q <= p)
                n = min(n, fs[q] / qs[q]);
        
       for (int i = 0; i < n; ++i)
           ans.push_back((char) ('0' + p));

       for (auto q : { 2, 3, 5, 7 })
           fs[q] -= (n*qs[q]);
    }

    return ans;
}

int main()
{
    long long n, a;
    cin >> n >> a;

    cout << solve(a) << '\n';

    return 0;
}

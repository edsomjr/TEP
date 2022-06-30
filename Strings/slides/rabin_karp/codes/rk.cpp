#include <bits/stdc++.h>

int f(char c)
{
    return c - 'a' + 1;
}

int h(const std::string& s)
{
    long long ans = 0, p = 31, q = 1000000007;

    for (auto it = s.rbegin(); it != s.rend(); ++it)
    {
        ans = (ans * p) % q;
        ans = (ans + f(*it)) % q;
    }

    return ans;
}

int rabin_karp(const std::string& s, const std::string& p)
{
    int n = s.size(), m = p.size(), occ = 0, hp = h(p); 

    for (int i = 0; i <= n - m; i++)
    {
        auto b = s.substr(i, m);
        occ += (h(b) == hp && b == p) ? 1 : 0;
    }

    return occ;
}

int main()
{
    auto s = "ababababababa", p = "aba";

    std::cout << rabin_karp(s, p) << '\n';

    return 0;
}

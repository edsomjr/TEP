#include <bits/stdc++.h>

using namespace std;

int lis(const vector<int>& as)
{
    vector<int> st(as.size(), -1);
    int n = 0;

    for (auto x : as)
    {
        if (x > st[n])  // Aumenta a LIS, quando possível
            st[++n] = x;
        else {          // Melhora os elementos já encontrados
            auto it = lower_bound(st.begin() + 1, st.begin() + n, x);
            *it = min(*it, x);
        }
    }

    return n;
}

int lcs(const string& S, const string& T)
{
    map<char, int> idx;

    for (size_t i = 0; i < T.size(); ++i)
        idx[T[i]] = i;

    vector<int> bs;

    for (const auto& c : S)
    {
        auto it = idx.find(c);

        if (it != idx.end())
            bs.push_back(it->second);
    }

    return lis(bs);
}

int main()
{
    string S { "trapezio" }, T { "reticulado" };

    cout << lcs(S, T) << '\n';

    return 0;
}

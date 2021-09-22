// CSES 1750 - Planets Queries I (https://cses.fi/problemset/task/1750)
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int Nmax { 200010 }, iMax { 30 };

int S[Nmax][iMax + 1];

void precomp(int N, int M, const vector<int>& s)
{
    for (int u = 1; u <= N; ++u)
        S[u][0] = s[u];

    for (int i = 1; i <= M; ++i)
        for (int u = 1; u <= N; ++u)
            S[u][i] = S[S[u][i - 1]][i - 1];
}

int succ(int u, int k)
{
    for (int i = 0; (1 << i) <= k; ++i)
        if (k & (1 << i))
            u = S[u][i];

    return u;
}

vector<int> solve(int N, const vector<int>& ts, const vector<ii>& qs)
{
    precomp(N, iMax, ts);

    vector<int> ans;

    for (auto [x, k] : qs)
        ans.emplace_back(succ(x, k));

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    vector<int> ts(N + 1);

    for (int u = 1; u <= N; ++u)
        cin >> ts[u];

    vector<ii> qs(Q);

    for (int i = 0; i < Q; ++i)
        cin >> qs[i].first >> qs[i].second;

    auto ans = solve(N, ts, qs);

    for (auto x : ans)
        cout << x << '\n';

    return 0;
}

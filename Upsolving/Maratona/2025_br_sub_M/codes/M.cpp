#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct VeniceSet
{
    multiset<pair<T, int>> s;
    T delta = 0;

    void add(T x, int i) { s.emplace(x + delta, i); }
    void update_all(T x) { delta -= x; }
    void pop() { s.erase(s.begin()); }   

    auto min() const
    {
        auto [m, i] = *s.begin();
        return make_pair(m - delta, i);
    }

    bool empty() const { return s.empty(); }
    int size() const { return static_cast<int>(s.size()); }
};

auto solve(int N, int K, const vector<int>& as)
{
    // Mínimos do prefixos de as
    vector<int> p(N);
    p[0] = as[0];

    for (int i = 1; i < N; ++i)
        p[i] = min(p[i - 1], as[i]);

    // Mínimos do sufixos de as
    vector<int> s(N);
    s[N - 1] = as[N - 1];

    for (int i = N - 2; i >= 0; --i)
        s[i] = min(s[i + 1], as[i]);

    VeniceSet<int> vs;
    int ans = 0;

    for (auto R = 0, L = R - K + 1; R < N; ++L, ++R) {
        vs.update_all(-1);
        vs.add(as[R] + K, R);

        while (not vs.empty() and vs.min().second < L)
            vs.pop();

        auto [m, _] = vs.min();

        if (L > 0)
            m = min(m, p[L - 1]);

        if (R < N - 1)
            m = min(m, s[R + 1]);

        ans = max(ans, m);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<int> as(N);

    for (auto& a : as)
        cin >> a;

    cout << solve(N, K, as) << '\n';

    return 0;
}

// The 2025 ICPC South America - Brazil First Phase - Problem M: Minas Gerais' walls (https://codeforces.com/gym/106073/problem/M)

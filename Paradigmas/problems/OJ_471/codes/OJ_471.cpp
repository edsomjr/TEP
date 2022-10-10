#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

int digits_count(ll x)
{
    int total = 0;

    do {
        x /= 10;

        ++total;
    } while (x);

    return total;
}

bool has_repeated_digits(ll x)
{
    bitset<10> used;
    used.reset();

    while (x)
    {
        int d = x % 10;
        x /= 10;

        if (used[d])
            return true;

        used[d] = true;
    }

    return false;
}

vector<ii> solve(ll N)
{
    vector<ii> ans;

    for (ll d = 1; digits_count(d*N) <= 10; ++d)
    {
        if (not has_repeated_digits(d) and not has_repeated_digits(d*N))
            ans.push_back(ii(d*N, d));
    }

    return ans;
} 

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test)
    {
        ll N;
        cin >> N;

        auto ans = solve(N);

        if (test > 1)
            cout << '\n';

        for (auto p : ans)
            cout << p.first << " / " << p.second << " = " << N << '\n';
    } 

    return 0;
}

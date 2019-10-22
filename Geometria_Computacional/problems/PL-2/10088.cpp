#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

#define x first
#define y second

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll area(int N, const vector<ii>& ps)
{
    ll A = 0;

    for (int i = 0; i < N; ++i)
    {
        A += ps[i].x * ps[i + 1].y;
        A -= ps[i].y * ps[i + 1].x;
    }

    return llabs(A);
}

// Teorema de Pick: A = I + B/2 - 1
ll solve(int N, vector<ii>& ps)
{
    ps.push_back(ps.front());

    ll B = 0;

    for (int i = 0; i < N; ++i)
    {
        auto b = llabs(ps[i].x - ps[i + 1].x);
        auto h = llabs(ps[i].y - ps[i + 1].y);
        auto d = gcd(b, h);

        B += (d + 1);        
    }

    // Desconta os vértices, contados em duplicidade
    B -= N;

    auto _2A = area(N, ps);
    auto I = (_2A - B + 2)/2;

    return I;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N, N)
    {
        vector<ii> ps(N);

        for (int i = 0; i < N; ++i)
            cin >> ps[i].x >> ps[i].y;

        auto ans = solve(N, ps);

        cout << ans << '\n';
    }

    return 0;
}

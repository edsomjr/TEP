#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point { ll x, y; };

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll area(int N, const vector<Point>& ps)
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
ll solve(int N, vector<Point>& ps)
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

    return I + B;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, test = 0;
    cin >> N;

    while (N--)
    {
        vector<Point> ps(4);

        for (int i = 0; i < 4; ++i)
            cin >> ps[i].x >> ps[i].y;

        auto ans = solve(4, ps);

        cout << "Case " << ++test << ": " << ans << '\n';
    }

    return 0;
}

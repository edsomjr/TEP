#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    ll x, y;

    bool operator<(const Point& P) const
    {
        return x == P.x ? y < P.y : x < P.x;
    }
};

struct Line {
    ll a, b, c;

    Line(const Point& p, const Point& q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p.x * q.y - p.y * q.x;
    }

    double distanceTo(const Point& P) const 
    {
        auto num = a*P.x + b*P.y + c;
        auto den = sqrt(a*a + b*b);

        return fabs(num/den);
    }
};

ll D(const Point& P, const Point& Q, const Point& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - 
           (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

// Andrew monotonic chain
vector<Point> convex_hull(vector<Point>& P)
{
    sort(P.begin(), P.end());

    vector<Point> L, U;

    for (auto p : P)
    {
        while (L.size() >= 2 and D(L[L.size() - 2], L[L.size() -1], p) < 0)
            L.pop_back();

        L.push_back(p);
    }

    reverse(P.begin(), P.end());

    for (auto p : P)
    {
        while (U.size() >= 2 and D(U[U.size() - 2], U[U.size() -1], p) < 0)
            U.pop_back();

        U.push_back(p);
    }

    L.pop_back();
    U.pop_back();

    L.reserve(L.size() + U.size());
    L.insert(L.end(), U.begin(), U.end()); 

    return L;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, test = 0;

    while (cin >> n, n)
    {
        vector<Point> ps(n);

        for (int i = 0; i < n; ++i)
            cin >> ps[i].x >> ps[i].y;

        auto ch = convex_hull(ps);
        ch.push_back(ch.front());
cout << "convex hull (size = " << ch.size() << ", n = " << n << ") = ";
for (const auto& v : ch)
    cout << "(" << v.x << ", " << v.y << ") ";
cout << '\n';
        auto min_dist = 1000000000.0;

        for (int i = 0; i < n; ++i)
        {
            auto A = ch[i];
            auto B = ch[i + 1];
            auto max_dist = 0.0;

            Line r(A, B);
cout << "A = (" << A.x << ", " << A.y << ")\n";
cout << "B = (" << B.x << ", " << B.y << ")\n";
            for (int j = 0; j < n; ++j)
            {
                auto d = r.distanceTo(ch[j]);
cout << "dist = " << d << "\n";
cout << "P = (" << ch[j].x << ", " << ch[j].y << ")\n";
                max_dist = max(max_dist, d);
            }
cout << "max dist = " << max_dist << '\n';
            min_dist = min(min_dist, max_dist);
cout << "\n";
        }

        cout << "Case " << ++test << ": ";
        cout.precision(2);
        cout << fixed << min_dist << '\n';
    }

    return 0;
}

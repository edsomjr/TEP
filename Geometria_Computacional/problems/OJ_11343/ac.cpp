#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point { ll x, y; };

ll D(const Point& P, const Point& Q, const Point& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

struct Segment
{
    Point A, B;

    bool contains(const Point& p) const
    {
        return (A.x == B.x) ? min(A.y, B.y) <= p.y && p.y <= max(A.y, B.y)
            : min(A.x, B.x) <= p.x && p.x <= max(A.x, B.x);
    }

    bool intersect(const Segment& s) const
    {
        auto d1 = D(A, B, s.A), d2 = D(A, B, s.B);

        if ((d1 == 0 && contains(s.A)) || (d2 == 0 && contains(s.B)))
            return true;

        auto d3 = D(s.A, s.B, A), d4 = D(s.A, s.B, B);

        if ((d3 == 0 && s.contains(A)) || (d4 == 0 && s.contains(B)))
            return true;

        return (d1 * d2 < 0) && (d3 * d4 < 0);
    }
};

int solve(const vector<Segment>& vs, int M)
{
    auto ans = 0;

    for (int i = 0; i < M; ++i)
    {
        int hits = 0;

        for (int j = 0; j < M; ++j)
        {
            if (i == j) continue;

            hits += vs[i].intersect(vs[j]) ? 1 : 0;
        }

        ans += (hits == 0) ? 1 : 0;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int M;
        cin >> M;

        vector<Segment> vs;

        for (int i = 0; i < M; ++i)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;

            vs.push_back(Segment { Point {a, b}, Point{c, d} });
        }

        auto ans = solve(vs, M);

        cout << ans << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ii = pair<double, double>;
using point = pair<double, double>;

#define x first
#define y second

double dist(const point& P, const point& Q)
{
    return hypot(P.x - Q.x, P.y - Q.y);
}

pair<point, point> closest_pair(int N, vector<point>& ps)
{
    sort(ps.begin(), ps.end());

    // Assume que N > 1
    auto d = dist(ps[0], ps[1]);
    auto closest = make_pair(ps[0], ps[1]);

    set<ii> S;
    S.insert(ii(ps[0].y, ps[0].x));
    S.insert(ii(ps[1].y, ps[1].x));

    for (int i = 2; i < N; ++i)
    {
        auto P = ps[i];
        auto it = S.lower_bound(point(P.y - d, 0));

        while (it != S.end())
        {
            auto Q = point(it->second, it->first);

            if (Q.x < P.x - d)
            {
                it = S.erase(it);
                continue;
            }

            if (Q.y > P.y + d)
                break;

            auto t = dist(P, Q);

            if (t < d)
            {
                d = t;
                closest = make_pair(P, Q);
            }

            ++it;
        }

        S.insert(ii(P.y, P.x));
    }

    return closest;
}

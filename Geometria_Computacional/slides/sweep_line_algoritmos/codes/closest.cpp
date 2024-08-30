#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;

    bool operator<(const Point& p) const { return x == p.x ? y < p.y : x < p.x; }
};

double dist(const Point& P, const Point& Q)
{
    return hypot(P.x - Q.x, P.y - Q.y);
}

// Este código assume que N > 1
auto closest_pair(int N, vector<Point>& ps)
{
    sort(ps.begin(), ps.end());

    auto d = dist(ps[0], ps[1]);
    auto closest = make_pair(ps[0], ps[1]);

    set<Point> S;
    S.emplace(ps[0].y, ps[0].x);
    S.emplace(ps[1].y, ps[1].x);

    for (int i = 2; i < N; ++i) {
        auto P = ps[i];
        auto it = S.lower_bound(Point(P.y - d, 0));

        while (it != S.end()) {
            auto Q = Point(it->y, it->x);

            if (Q.x < P.x - d) {
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

        S.emplace(P.y, P.x);
    }

    return closest;
}

int main()
{
    vector<Point> ps { { 2, 4 }, { 5, 3 }, { 8, 1 }, { 3, 6 }, { 1, 1 }, { 4, 4 }, { 8, 5 }, { 6, 2 }, { 1, 6 }, { 7, 4 }, { 8, 6 }, { 3, 2 }, { 6, 5 }, { -1, 4 } };

    auto [P, Q] = closest_pair((int) ps.size(), ps);

    cout << "(" << P.x << ", " << P.y << ") to (" << Q.x << ", " << Q.y << ") = " << dist(P, Q) << '\n';

    return 0;
}


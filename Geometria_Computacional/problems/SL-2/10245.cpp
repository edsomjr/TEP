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

double solve(int N, vector<point>& ps)
{
    sort(ps.begin(), ps.end());

    if (N == 1)
        return -1;

    auto d = dist(ps[0], ps[1]);

//cout << "d = " << d << '\n';
    set<ii> S;
    S.insert(ii(ps[0].y, ps[0].x));
    S.insert(ii(ps[1].y, ps[1].x));

    for (int i = 2; i < N; ++i)
    {
        auto P = ps[i];
//cout << "\nP = (" << P.x << ", " << P.y << ")\n";
        auto it = S.lower_bound(point(P.y - d, 0));

        while (it != S.end())
        {
            auto Q = point(it->second, it->first);

//cout << "Q = (" << Q.x << ", " << Q.y << "), d(P, Q) = " << dist(P, Q) << "\n";
            if (Q.x < P.x - d)
            {
//cout << "Caso #1: remoção\n";
//cout.flush();
                it = S.erase(it);
                continue;
            }

            if (Q.y > P.y + d)
            {
//cout << "Caso #2: encerramento\n";
                break;
            }

            auto t = dist(P, Q);

//cout << "t = " << t << '\n';

            if (t < d)
            {
//cout << "Caso #3: atualização d = " << d << ", t = " << t << "\n";
                d = t;
            }

            ++it;
        }

        S.insert(ii(P.y, P.x));
    }

    return d < 10000 ? d : -1;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N, N)
    {
        vector<point> ps(N);

        for (int i = 0; i < N; ++i)
            cin >> ps[i].x >> ps[i].y;

        auto ans = solve(N, ps);

        if (ans < 0)
            cout << "INFINITY\n";
        else
        {
            cout.precision(4);
            cout << fixed << ans << '\n';
        }
    }

    return 0;
}

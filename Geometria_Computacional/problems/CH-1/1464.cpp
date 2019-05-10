#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;

    bool operator<(const Point& P) const
    {
        return x == P.x ? y < P.y : x < P.x;
    }
};

int D(const Point& P, const Point& Q, const Point& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) -
           (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

vector<Point> monotone_chain(set<Point>& P)
{
    vector<Point> lower, upper;

    if (P.size() < 3)
        return lower;

    for (const auto& p : P)
    {
        auto size = lower.size();

        while (size >= 2 and D(lower[size - 2], lower[size - 1], p) < 0)
        {
            lower.pop_back();
            size = lower.size();
        }

        lower.push_back(p);
    }

    for (auto it = P.rbegin(); it != P.rend(); ++it)
    {
        auto p = *it;
        auto size = upper.size();

        while (size >= 2 and D(upper[size - 2], upper[size - 1], p) < 0)
        {
            upper.pop_back();
            size = upper.size();
        }

        upper.push_back(p);
    }

    lower.pop_back();
    upper.pop_back();

    lower.insert(lower.end(), upper.begin(), upper.end()); 

    for (const auto& p : lower)
        P.erase(p);

    return lower;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    
    while (cin >> N, N)
    {
        set<Point> P;
        int x, y;

        for (int i = 0; i < N; ++i)
        {
            cin >> x >> y;
            P.insert(Point { x, y });
        }

        int ans = 0;

        while (monotone_chain(P).size() > 2)
            ++ans;

        cout << (ans % 2 ? "Take this onion to the lab!\n" :
            "Do not take this onion to the lab!\n");
    }

    return 0;
}

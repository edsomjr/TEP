#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Point
{
    T x, y;

    bool operator<(const Point& P) const
    {
        return x == P.x ? y < P.y : x < P.x;
    }
};

template<typename T>
T D(const Point<T>& P, const Point<T>& Q, const Point<T>& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) -
           (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

template<typename T>
vector<Point<T>> make_hull(const vector<Point<T>>& points, vector<Point<T>>& hull)
{
    for (const auto& p : points)
    {
        auto size = hull.size();

        while (size >= 2 and D(hull[size - 2], hull[size - 1], p) <= 0)
        {
            hull.pop_back();
            size = hull.size();
        }

        hull.push_back(p);
    }

    return hull;
}

template<typename T>
vector<Point<T>> monotone_chain(const vector<Point<T>>& points)
{
    vector<Point<T>> P(points);

    sort(P.begin(), P.end());

    vector<Point<T>> lower, upper;
    
    lower = make_hull(P, lower);

    reverse(P.begin(), P.end());
    
    upper = make_hull(P, upper);

    lower.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end()); 

    return lower;
}

int main()
{
    vector<Point<int>> P { { 0, 0 }, { 5, 3 }, { 8, -2 }, { 4, 4 }, { 2, 1 }, { 2, 5 }, { 3, -1 },
        { 7, 2 }, { 5, 0 }, { 0, 4 }, { 1, -1 }, { 7, -2 }, { 6, 4 }, { 6, 0 }, { 1, 3 } };

    auto ch = monotone_chain<int>(P);

    cout << "convex hull: \n";
    for (size_t i = 0; i < ch.size(); ++i)
        cout << i + 1 << ": (" << ch[i].x << ", " << ch[i].y << ")\n";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T>
bool equals(T a, T b)
{
    if (std::is_floating_point<T>::value)
    {
        const double EPS { 1e-6 };

        return fabs(a - b) < EPS;
    } else
        return a == b;
}

template<typename T>
struct Point
{
    T x, y;

    bool operator<(const Point& P) const
    {
        return x != P.x ? x < P.x : y < P.y;
    }

    bool operator==(const Point& P) const
    {
        return x == P.x and y == P.y;
    }
};

template<typename T>
struct Segment
{
    T a, b, c;
    Point<T> A, B;

    Segment(const Point<T>& P, const Point<T>& Q)
        : a(P.y - Q.y), b (Q.x - P.x), c(P.x*Q.y - Q.x*P.y), A(P), B(Q)
    {
    }

    optional<Point<T>> intersection(const Segment& s)
    {
        auto det = a * s.b - b * s.a;

        if (not equals(det, 0.0))     // Concorrentes
        {
            auto x = (-c * s.b + s.c * b) / det;
            auto y = (-s.c * a + c * s.a) / det;

            if (min(A.x, B.x) <= x and x <= max(A.x, B.x) and
                min(s.A.x, s.B.x) <= x and x <= max(s.A.x, s.B.x))
            {
                return Point<T> { x, y };
            }
        }

        return { };
    }
};

template<typename T>
set<Point<T>> intersections(int N, const vector<Segment<T>>& segments)
{
    set<Point<T>> ans;

    for (int i = 0; i < N; ++i)
    {
        auto s = segments[i];

        for (int j = i + 1; j < N; ++j)
        {
            auto r = segments[j];
            auto P = s.intersection(r);

            if (P)
                ans.insert(P.value());
        }
    }

    return ans;
}

int main()
{
    vector<Segment<double>> segments {
        { { 1, 2 }, { 5, 4 } },
        { { 2, 3 }, { 6, 3 } },
        { { 2, 6 }, { 4, 0 } },
    };

    auto ans = intersections(segments.size(), segments);

    cout << ans.size() << '\n';
    for (const auto& P : ans)
        cout << "(" << P.x << ", " << P.y << ") ";
    cout << '\n';

    return 0;
}

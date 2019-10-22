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
T D(const Point<T>& P, const Point<T>& Q, const Point<T>& R)
{
    return (P.x*Q.y + P.y*R.x + Q.x*R.y) - (R.x*Q.y + R.y*P.x + Q.x*P.y);
}

template<typename T>
struct Segment
{
    T a, b, c;
    Point<T> A, B;

    Segment(const Point<T>& P, const Point<T>& Q)
        : a(P.y - Q.y), b (Q.x - P.x), c(P.x*Q.y - Q.x*P.y), A(P), B(Q)
    {
        sweep_x = -1;
    }

    bool operator<(const Segment& line) const
    {
        return (-a*sweep_x - c)*line.b < (-line.a*sweep_x -line.c)*b;
    }

    bool intersect(const Segment& s) const
    {
        auto d1 = D(A, B, s.A);
        auto d2 = D(A, B, s.B);

        if ((equals(d1, 0LL) && contains(s.A)) || 
           (equals(d2, 0LL) && contains(s.B)))
            return true;

        auto d3 = D(s.A, s.B, A);
        auto d4 = D(s.A, s.B, B);

        if ((equals(d3, 0LL) && s.contains(A)) ||
           (equals(d4, 0LL) && s.contains(B)))
            return true;

        return (d1 * d2 < 0) && (d3 * d4 < 0);
    }

    bool contains(const Point<T>& P) const
    {
        if (P == A || P == B)
            return true;

        auto xmin = min(A.x, B.x);
        auto xmax = max(A.x, B.x);
        auto ymin = min(A.y, B.y);
        auto ymax = max(A.y, B.y);

        if (P.x < xmin || P.x > xmax || P.y < ymin || P.y > ymax)
            return false;

        return equals((P.y - A.y)*(B.x - A.x), (P.x - A.x)*(B.y - A.y));
    }

    static T sweep_x;
};

template<typename T>
T Segment<T>::sweep_x;

template<typename T>
bool shamos_hoey(const vector<Segment<T>>& segments)
{
    struct Event
    {
        Point<T> P;
        size_t i;

        bool operator<(const Event& e) const { return P < e.P; }
    };

    vector<Event> events;

    for (size_t i = 0; i < segments.size(); ++i)
    {
        events.push_back({ segments[i].A, i });
        events.push_back({ segments[i].B, i });
    }

    sort(events.begin(), events.end());
    set<Segment<T>> sl;

    for (const auto& e : events)
    {
        auto s = segments[e.i];
        Segment<T>::sweep_x = e.P.x;

        if (e.P == s.A)
        {
            sl.insert(s);

            auto it = sl.find(s);

            if (it != sl.begin())
            {
                auto L = *prev(it);

                if (s.intersect(L)) return true;
            } 

            if (next(it) != sl.end())
            {
                auto U = *next(it);

                if (s.intersect(U)) return true;
            } 
        } else
        {
            auto it = sl.find(s);

            if (it != sl.begin() and it != sl.end())
            {
                auto L = *prev(it);
                auto U = *next(it);

                if (L.intersect(U)) return true;
            }

            sl.erase(it);
        }
    }

    return false;
}

int main()
{
    vector<Segment<ll>> segments {
        { { 1, 1 }, { 5, 4 } },
        { { 3, 6 }, { 7, 4 } },
        { { 2, 3 }, { 4, 4 } },
        { { 5, 2 }, { 9, 5 } },
        { { 5, 3 }, { 8, 2 } },
    };

    auto ans = shamos_hoey(segments);

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}

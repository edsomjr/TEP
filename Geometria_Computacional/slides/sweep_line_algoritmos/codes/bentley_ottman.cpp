#include <bits/stdc++.h>

using namespace std;

bool equals(double a, double b)
{
    const double EPS { 1e-6 };

    return fabs(a - b) < EPS;
}

struct Point
{
    double x, y;

    bool operator<(const Point& P) const
    {
        return x != P.x ? x < P.x : y < P.y;
    }

    bool operator==(const Point& P) const
    {
        return x == P.x and y == P.y;
    }

    bool operator!=(const Point& P) const
    {
        return not (*this == P);
    }
};

struct Segment
{
    double a, b, c;
    Point A, B;
    size_t idx;

    Segment(const Point& P, const Point& Q, size_t i)
        : a(P.y - Q.y), b (Q.x - P.x), c(P.x*Q.y - Q.x*P.y), A(P), B(Q), idx(i) { }

    bool operator<(const Segment& s) const
    {
        return (-a*sweep_x - c)*s.b < (-s.a*sweep_x -s.c)*b;
    }

    optional<Point> intersection(const Segment& s) const
    {
        auto det = a * s.b - b * s.a;

        if (not equals(det, 0.0))     // Concorrentes
        {
            auto x = (-c * s.b + s.c * b) / det;
            auto y = (-s.c * a + c * s.a) / det;

            if (min(A.x, B.x) <= x and x <= max(A.x, B.x) and
                min(s.A.x, s.B.x) <= x and x <= max(s.A.x, s.B.x))
            {
                return Point { x, y };
            }
        }

        return { };
    }

    static double sweep_x;
};

double Segment::sweep_x;

struct Event
{
    enum Type { OPEN, INTERSECTION, CLOSE };

    Point P;
    Type type;
    size_t i;

    bool operator<(const Event& e) const
    { 
        if (P != e.P)
            return e.P < P;

        if (type != e.type)
            return type > e.type;

        return i > e.i;
    }
};

void add_neighbor_intersections(const Segment& s, const set<Segment>& sl, 
    set<Point>& ans, priority_queue<Event>& events)
{
    // TODO: garantir que a busca identifique unicamente o elemento s,
    // através do ajuste fino da variável Segment::sweep_x
    auto it = sl.find(s);

    if (it != sl.begin())
    {
        auto L = *prev(it);
        auto P = s.intersection(L);
        
        if (P and ans.count(P.value()) == 0)
        {
            events.push(Event { P.value(), Event::INTERSECTION, s.idx } );
            ans.insert(P.value());
        }
    } 

    if (next(it) != sl.end())
    {
        auto U = *next(it);
        auto P = s.intersection(U);

        if (P and ans.count(P.value()) == 0)
        {
            events.push(Event { P.value(), Event::INTERSECTION, s.idx } );
            ans.insert(P.value());
        }
    }
} 

set<Point> bentley_ottman(vector<Segment>& segments)
{
    set<Point> ans;
    priority_queue<Event> events;

    for (size_t i = 0; i < segments.size(); ++i)
    {
        events.push(Event { segments[i].A, Event::OPEN, i });
        events.push(Event { segments[i].B, Event::CLOSE, i });
    }

    set<Segment> sl;

    while (not events.empty())
    {
        auto e = events.top();
        events.pop();

        Segment::sweep_x = e.P.x;

        switch (e.type) {
        case Event::OPEN:
        {
            auto s = segments[e.i];
            sl.insert(s);

            add_neighbor_intersections(s, sl, ans, events);
        } 
        break;

        case Event::CLOSE:
        {
            auto s = segments[e.i];
            auto it = sl.find(s);       // TODO: aqui também

            if (it != sl.begin() and it != sl.end())
            {
                auto L = *prev(it);
                auto U = *next(it);
                auto P = L.intersection(U);

                if (P and ans.count(P.value()) == 0)
                    events.push( Event { P.value(), Event::INTERSECTION, L.idx } );
            }

            sl.erase(it);
        }
        break;

        default:
            auto r = segments[e.i];
            auto p = sl.equal_range(r);

            vector<Segment> range(p.first, p.second);

            // Remove os segmentos que se interceptam
            sl.erase(p.first, p.second);

            // Reinsere os segmentos
            Segment::sweep_x += 0.1;

            sl.insert(range.begin(), range.end());

            // Procura interseções com os novos vizinhos
            for (const auto& s : range)
                add_neighbor_intersections(s, sl, ans, events);
        }
    }

    return ans;
}

int main()
{
    vector<Segment> segments {
        { { 1, 2 }, { 4, 5 }, 0 },
        { { 0, 3 }, { 6, 3 }, 1 },
        { { 1, 6 }, { 3, 0 }, 2 },
        { { 2, 5 }, { 5, 2 }, 3 },
    };

    auto ans = bentley_ottman(segments);

    cout << ans.size() << '\n';

    for (const auto& P : ans)
        cout << "(" << P.x << ", " << P.y << ") ";
    cout << '\n';

    return 0;
}

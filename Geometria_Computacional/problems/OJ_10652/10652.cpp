#include <bits/stdc++.h>

using namespace std;

const double EPS { 1e-5 }, PI { acos(-1.0) };

bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
}

struct Point {
public:
    double x, y;

    double distance(const Point& P) const
    {
        return hypot(x - P.x, y - P.y);
    }

    Point translate(double dx, double dy) const
    {
        return Point { x + dx, y + dy };
    }

    Point rotate(double angle) const
    {
        return Point { x*cos(angle) - y*sin(angle), x*sin(angle) + y*cos(angle) };
    }
};

double D(const Point& P, const Point& Q, const Point& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

struct Polygon {
    vector<Point> vs;
    int n;

    Polygon(const vector<Point>& vertices) : vs(vertices), n(vs.size()) { vs.push_back(vs[0]); }

    double area() const 
    {
        double a = 0;

        for (int i = 0; i < n; ++i)
        {
            a += vs[i].x * vs[i+1].y;
            a -= vs[i+1].x * vs[i].y;
        }

        return 0.5 * fabs(a);
    }
};

Point pivot(vector<Point>& P)
{
    size_t idx = 0;

    for (size_t i = 1; i < P.size(); ++i)
        if (P[i].y < P[idx].y or (equals(P[i].y, P[idx].y) and P[i].x > P[idx].x))
            idx = i;

    swap(P[0], P[idx]);

    return P[0];
}

void sort_by_angle(vector<Point>& P)
{
    auto P0 = pivot(P);

    sort(P.begin() + 1, P.end(), [&](const Point& A, const Point& B)
        {
            if (equals(D(P0, A, B), 0))
                return A.distance(P0) < B.distance(P0);

            auto alfa = atan2(A.y - P0.y, A.x - P0.x);
            auto beta = atan2(B.y - P0.y, B.x - P0.x);

            return alfa < beta;
        }
    );
}

Polygon convex_hull(const vector<Point>& points)
{
    vector<Point> P(points);
    auto n = P.size();

    if (n <= 3)
        return Polygon(P);

    sort_by_angle(P);

    vector<Point> s;
    s.push_back(P[n - 1]);
    s.push_back(P[0]);
    s.push_back(P[1]);

    size_t i = 2;

    while (i < n)
    {
        auto j = s.size() - 1;

        if (D(s[j - 1], s[j], P[i]) > 0)
            s.push_back(P[i++]);
        else
            s.pop_back();
    }

    s.pop_back();
    return Polygon(s);
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<Point> points;
        double boards_area = 0;

        while (n--)
        {
            double x, y, w, h, theta;
            cin >> x >> y >> w >> h >> theta;

            theta /= 180.0;
            theta *= PI;

            double xv = w / 2, yv = h / 2;

            vector<Point> ps { Point { xv, yv }, Point { -xv, yv }, 
                Point { -xv, -yv }, Point { xv, -yv } };

            for (auto p : ps)
            {
                auto q = p.rotate(-theta);
                points.push_back(q.translate(x, y));
            }

            boards_area += w * h;
        }

        auto ch = convex_hull(points);
        auto total = ch.area();
        auto percent = 100.0 * boards_area / total;

        printf("%.1f %%\n", percent);
    }

    return 0;
}

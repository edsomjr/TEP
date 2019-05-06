#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;

    Point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

    double distance(const Point& P) const
    {
        return hypot(x - P.x, y - P.y);
    }

    bool operator==(const Point& P) const
    {
        const double EPS { 1e-6 };
        return fabs(x - P.x) < EPS and fabs(y - P.y) < EPS;
    }
};

struct Polygon {
    vector<Point> vs;
    int n;

    Polygon(const vector<Point>& vs) : vs(vs), n(vs.size())
    {
        vs.push_back(vs[0]);
    }

    double area() const {
        double a = 0;

        for (int i = 0; i < n; ++i)
        {
            a += vs[i].x * vs[i+1].y;
            a -= vs[i+1].x * vs[i].y;
        }

        return 0.5 * fabs(a);
    }
};

Point intersection(const Point& P, const Point& Q,
    const Point& A, const Point& B)
{
    auto a = B.y - A.y;
    auto b = A.x - B.x;
    auto c = B.x * A.y - A.x * B.y;
    auto u = fabs(a * P.x + b * P.y + c);
    auto v = fabs(a * Q.x + b * Q.y + c);

    return Point((P.x*v + Q.x*u)/(u + v), (P.y*v + Q.y*u)/(u + v));
}

double D(const Point& P, const Point& Q, const Point& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y)
        - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

Polygon cut_polygon(const Polygon& P, const Point& A, const Point& B)
{
    vector<Point> points;

    for (int i = 0; i < P.n; ++i)
    {
        auto d1 = D(A, B, P.vs[i]);
        auto d2 = D(A, B, P.vs[i + 1]);

        if (d1 > -EPS)
            points.push_back(P.vs[i]);

        if (d1 * d2 < -EPS)
            points.push_back(intersection(P.vs[i], P.vs[i+1], A, B));
    }

    return Polygon(points);
}

int main() {
    int N, W, H, x, y, test = 0;

    while (cin >> N >> W >> x >> y) {
        Polygon p({ Point(0, 0), Point(W, 0), Point(W, H), Point(0, H) });
        Point F(x, y);

        while (N--) {
            Point Q, R;
            cin >> Q.x >> Q.y >> R.x >> R.y;

            if (D(Q, R, F) > 0)
                p = cut_polygon(p, Q, R);
            else
                p = cut_polygon(p, R, Q);
        }

        printf("Case #%d: %.3f\n", ++test, p.area());
    }
    return 0;
}

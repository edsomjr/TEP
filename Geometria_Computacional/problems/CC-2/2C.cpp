#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Point
{
    T x, y;

    double distance(const Point& P) const
    {
        return hypot(x - P.x, y - P.y);
    }
};

template<typename T>
struct Line
{
    T a, b, c;
};

template<typename T>
struct Circle
{
    Point<T> C;
    T r;
};

template<typename T> vector<Point<T>>
intersection(const Circle<T>& c1, const Circle<T>& c2)
{
    vector<Point<double>> ps;
    double d = hypot(c1.C.x - c2.C.x, c1.C.y - c2.C.y);

    if (d > c1.r + c2.r or d < fabs(c1.r - c2.r))
        return ps;

    // Caso d == 0 ignorado por conta das restrições da entrada
    auto a = (c1.r * c1.r - c2.r * c2.r + d * d)/(2 * d);
    auto h = sqrt(c1.r * c1.r - a * a);
    auto x = c1.C.x + (a/d)*(c2.C.x - c1.C.x);
    auto y = c1.C.y + (a/d)*(c2.C.y - c1.C.y);

    auto P = Point<double> { x, y };

    x = P.x + (h/d)*(c2.C.y - c1.C.y);
    y = P.y - (h/d)*(c2.C.x - c1.C.x);

    ps.push_back( { x, y } );

    x = P.x - (h/d)*(c2.C.y - c1.C.y);
    y = P.y + (h/d)*(c2.C.x - c1.C.x);

    ps.push_back( { x, y } );

    return ps;
}

Circle<double> best_circle(const Circle<int>& P, const Circle<int>& Q)
{
    auto rP2 = (double) P.r * P.r;
    auto rQ2 = (double) Q.r * Q.r;

    auto x = (rQ2*P.C.x - rP2*Q.C.x)/(rQ2 - rP2);
    auto y = (rQ2*P.C.y - rP2*Q.C.y)/(rQ2 - rP2);
    auto K = (rQ2*P.C.x*P.C.x - rP2*Q.C.x*Q.C.x 
            + rQ2*P.C.y*P.C.y - rP2*Q.C.y*Q.C.y)/(rQ2 - rP2);

    auto r = sqrt(x*x + y*y - K);

    return { x, y, r };
}


template<typename T>
Point<double> intersection(const Line<T>& r, const Line<T>& s)
{
    auto det = r.a * s.b - r.b * s.a;

    // Caso det == 0 ignorado por conta das condições da entrada

    double x = (double) (-r.c * s.b + s.c * r.b) / det;
    double y = (double) (-s.c * r.a + r.c * s.a) / det;

    return { x, y };
}

template<typename T>
Line<T> perpendicular_bisector(const Point<T>& P, const  Point<T>& Q)
{
    auto a = 2*(Q.x - P.x);
    auto b = 2*(Q.y - P.y);
    auto c = (P.x * P.x + P.y * P.y) - (Q.x * Q.x + Q.y * Q.y);
    return { a, b, c };
}

vector<Point<double>> solve(const vector<Circle<int>>& ps)
{
    vector<Point<double>> ans;
    enum { P, Q, R };

    if (ps[P].r == ps[Q].r and ps[Q].r == ps[R].r) {
        auto r = perpendicular_bisector(ps[P].C, ps[Q].C);
        auto s = perpendicular_bisector(ps[Q].C, ps[R].C);
        ans.push_back(intersection(r, s));
    } else 
    {
        vector<Circle<double>> cs;

        if (ps[P].r != ps[Q].r)
            cs.push_back(best_circle(ps[P], ps[Q]));

        if (ps[P].r != ps[R].r)
            cs.push_back(best_circle(ps[P], ps[R]));
            
        if (ps[Q].r != ps[R].r)
            cs.push_back(best_circle(ps[Q], ps[R]));
 
        auto qs = intersection(cs[0], cs[1]);

        if (not qs.empty())
        {
            auto A = qs.front();
            auto B = qs.back();
            auto distA = 1e9, distB = 1e9;

            for (int i = 0; i < 3; ++i)
            {
                Point<double> X { (double) ps[i].C.x, (double) ps[i].C.x };

                distA = min(distA, A.distance(X)); 
                distB = min(distB, B.distance(X)); 
            }

            distA < distB ? ans.push_back(A) : ans.push_back(B);
        }
    }

 
    return ans;
}

int main()
{
    vector<Circle<int>> ps; 

    for (int i = 0; i < 3; ++i)
    {
        int x, y, r;
        cin >> x >> y >> r;

        ps.push_back(Circle<int> { x, y, r });
    }

    auto ans = solve(ps);

    if (not ans.empty())
        printf("%.5f %.5f\n", ans[0].x, ans[0].y);

    return 0;
}

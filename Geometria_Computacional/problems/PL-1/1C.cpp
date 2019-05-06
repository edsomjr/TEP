#include <bits/stdc++.h>

using namespace std;

const double PI { acos(-1.0) };
const int MAX { 110 };

double angles[MAX];

struct Point {
    double x, y;
    
    double distance(const Point& P) const
    {
        return hypot(x - P.x, y - P.y);
    }

    Point translate(const Point& P) const
    {
        return Point { x + P.x, y + P.y };
    }
    
    Point rotate(double angle) const
    {
        auto xv = x*cos(angle) - y*sin(angle);
        auto yv = x*sin(angle) + y*cos(angle);
    
        return Point { xv, yv };
    }

    bool operator==(const Point& P) const
    {
        const double EPS { 1e-5 };

        return fabs(x - P.x) < EPS and fabs(y - P.y) < EPS;
    }
};

struct Triangle {
    Point A, B, C;
    
    double area() const
    {
        auto a = A.distance(B);
        auto b = B.distance(C);
        auto c = C.distance(A);
        auto s = (a + b + c) / 2;
        
        return sqrt(s*(s - a)*(s - b)*(s - c));
    }
    
    double circumradius() const
    {
        auto a = A.distance(B);
        auto b = B.distance(C);
        auto c = C.distance(A);

        return (a * b * c)/(4 * area());
    }

    Point circumcenter() const
    {
        auto d = 2*(A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y));

        auto A2 = A.x*A.x + A.y*A.y;
        auto B2 = B.x*B.x + B.y*B.y;
        auto C2 = C.x*C.x + C.y*C.y;

        auto x = (A2*(B.y - C.y) + B2*(C.y - A.y) + C2*(A.y - B.y))/d;
        auto y = (A2*(C.x - B.x) + B2*(A.x - C.x) + C2*(B.x - A.x))/d;

        return Point { x, y };
    }
};

void precomp()
{
    for (int i = 1; i < MAX; ++i)
        angles[i] = (2.0*PI)/i;
}

int sides(const Point& P, const Point& Q, const Point& R)
{
    for (int i = 3; i < 100; ++i)
    {
        auto angle = angles[i];
        int match = 0;
        Point S { P };

        for (int j = 0; j < i; ++j)
        {
            if (Q == S)
                ++match;

            if (R == S)
                ++match;

            S = S.rotate(angle);
        }

        if (match == 2)
            return i;
    }

    return 100;
}

int main()
{
    precomp();

    Point P, Q, R;
        
    cin >> P.x >> P.y >> Q.x >> Q.y >> R.x >> R.y;
        
    Triangle t { P, Q, R };
        
    auto r = t.circumradius();
    auto C = t.circumcenter();

    P = P.translate(Point { -C.x, -C.y } );
    Q = Q.translate(Point { -C.x, -C.y } );
    R = R.translate(Point { -C.x, -C.y } );
        
    int min_sides = sides(P, Q, R);

    auto area = (r * r * min_sides*sin(angles[min_sides]))/2.0;

    cout.precision(6);
    cout << fixed << area << '\n';

    return 0;
}

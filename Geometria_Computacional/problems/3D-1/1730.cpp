#include <bits/stdc++.h>

using namespace std;

const double R { 6378 };
const double PI { acos(-1) };

struct Query {
    string name;
    double lat, lon;
};

struct Point3D {
    double x, y, z;

    Point3D operator-(const Point3D& P) const
    {
        return Point3D { x - P.x, y - P.y, z - P.z };
    }

    double operator*(const Point3D& P) const
    {
        return x * P.x + y * P.y + z * P.z;
    }
    
    void normalize()
    {
        auto len = length();

        x /= len;
        y /= len;
        z /= len;
    }

    double length() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    static Point3D from_polar(double R, double lat, double lon)
    {
        auto gamma = lat * PI / 180.0;
        auto theta = lon * PI / 180.0;

        // latitude = (90 - gamma), em relação às coordenadas esféricas
        auto x = R*cos(theta)*cos(gamma);
        auto y = R*sin(theta)*cos(gamma);
        auto z = R*sin(gamma);

        return Point3D { x, y, z };
    }
};

double angle(Point3D& P, Point3D& Q)
{
    P.normalize();
    Q.normalize();

    auto dot = P * Q; 

    if (dot > 0)
        dot = min(dot, 1.0);

    if (dot < 0)
        dot = max(dot, -1.0);

    return acos(dot);
}

vector<string>
solve(double lat, double lon, double h, const vector<Query>& qs)
{
    vector<string> ans;

    auto Q = Point3D::from_polar(h + R, lat, lon);

    for (const auto& q : qs)
    {
        auto P = Point3D::from_polar(R, q.lat, q.lon);
        auto u = Q - P;
        auto alpha = angle(P, u);

        if (alpha < PI/2.0)
            ans.push_back(q.name);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int N, test = 0;

    while (cin >> N, N)
    {
        double lat, lon, h;
        cin >> lat >> lon >> h;

        vector<Query> qs;

        while (N--)
        {
            string name;
            double x, y;

            cin >> name >> x >> y;

            qs.push_back({ name, x, y });
        }

        auto ans = solve(lat, lon, h, qs);

        cout << "Test case " << ++test << ":\n";

        for (const auto& name : ans)
            cout << name << '\n';

        cout << '\n';
    }

    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

struct Planet {
    Point P;
    int h;
};

double
distance(const Point& P, const Point& Q)
{
    return hypot(P.x - Q.x, P.y - Q.y);
}

int D(const Point& P, const Point& Q, const Point& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) -
        (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

int main()
{
    ios::sync_with_stdio(false);

    Point P, Q;

    cin >> P.x >> P.y >> Q.x >> Q.y;

    cout << "Relatorio Vogon #35987-2\n";

    cout.precision(2);
    cout << "Distancia entre referencias: " << fixed <<
        distance(P, Q) << " anos-luz\n";

    int N;
    cin >> N;

    vector<Planet> planets;

    for (int i = 0; i < N; i++)
    {
        int x, y, h;
        cin >> x >> y >> h;

        planets.push_back(Planet { Point { x, y }, h });
    }

    int left = 0, right = 0, casualities = 0;
    int hleft = 0, hright = 0;

    for (const auto& p : planets)
    {
        int d = D(P, Q, p.P);

        d == 0 ?  casualities++ :
            (d > 0 ? (left++, hleft += p.h) : (right++, hright += p.h));

    }

    cout << "Setor Oeste:\n";
    cout << "- " << left << " planeta(s)\n";
    cout << "- " << hleft << " bilhao(oes) de habitante(s)\n";

    cout << "Setor Leste:\n";
    cout << "- " << right << " planeta(s)\n";
    cout << "- " << hright << " bilhao(oes) de habitante(s)\n";

    cout << "Casualidades: " << casualities << " planeta(s)\n";

    return 0;
}

#include <bits/stdc++.h>
#define fle(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define flt(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define fgt(i, a, b) for (int (i) = (a); (i) > (b); (i)--)
#define fge(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define log(var, sep) (cerr << #var << " = " << (var) << (sep))
#define pb push_back
#define nl (cout << endl)
#define pf first
#define ps second
using namespace std;

using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vp = vector< ii >;

const int MAX { 1000010 }; // 10^6 + 10
const ll oo { (1ll << 62) }; // 2^62
const ll MOD { 1000000007 }; // 10^9 + 7
const double PI = acos(-1.0); // 3.14
#define EPS 1e-9


bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
}

class Point {
public:
        double x;
        double y;

        Point(double xv = 0, double yv = 0) : x(xv), y(yv) {}
};

ll D(const Point& P, const Point& Q, const Point& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}
double angle(const Point& P, const Point& A, const Point& B)
{
    auto ux = P.x - A.x;
    auto uy = P.y - A.y;

    auto vx = P.x - B.x;
    auto vy = P.y - B.y;

    auto num = ux * vx + uy * vy;
    auto den = hypot(ux, uy) * hypot(vx, vy);

    // Caso especial: se den == 0, algum dos vetores é degenerado: os dois
    // pontos são iguais. Neste caso, o ângulo não está definido

    return acos(num / den);
}

class Polygon {
public:
    // Membros e construtores
	vector<Point> vertices;
    int n;

    // O parâmetro deve conter os n vértices do polígono
    Polygon(const vector<Point>& vs) : vertices(vs), n(vs.size())
    {
        vertices.push_back(vertices[0]);
    }

    bool contains(const Point& P) const
    {
        if (n < 3)
            return false;

        auto sum = 0.0;

        for (int i = 0; i < n; ++i)
        {
            auto d = D(P, vertices[i], vertices[i + 1]);

            // Pontos sobre as arestas ou vértices são considerados interiores
            if (equals(d, 0))
                return true;

            auto a = angle(P, vertices[i], vertices[i + 1]);

            sum += d > 0 ? a : -a;
        }

        return equals(fabs(sum), 2*PI);
    }
};

int main () {
	double n, d, m, x, y;
	cin >> n >> d >> m;
	
	vector< Point > points;
	Point p1(0, d), p2(d, 0), p3(n, n-d), p4(n-d, n);
	points.pb(p1);
	points.pb(p2);
	points.pb(p3);
	points.pb(p4);

	Polygon xd(points);

	flt (i, 0, m) {
		cin >> x >> y;

		Point grass(x, y);

		cout << (xd.contains(grass) ? "YES" : "NO") << "\n";
	}

	return 0;
}
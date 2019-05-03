#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Point { T x, y; };

template<typename T>
class Polygon {
private:
    vector<Point<T>> vs;
    int n;

public:
    // O parâmetro deve conter os n vértices do polígono
    Polygon(const vector<Point<T>>& ps) : vs(ps), n(vs.size())
    {
        vs.push_back(vs.front());
    }

private:
    T D(const Point<T>& P, const Point<T>& Q, const Point<T>& R) const
    {
        return (P.x * Q.y + P.y * R.x + Q.x * R.y) - 
            (R.x * Q.y + R.y * P.x + Q.x * P.y);
    }

public:
    bool convex() const {
        // Um polígono deve ter, no minimo, 3 vértices
        if (n < 3) return false;

        int P = 0, N = 0, Z = 0, M = vs.size();

        for (int i = 0; i < n; ++i) {
            auto d = D(vs[i], vs[(i + 1) % M], vs[(i + 2) % M]);
            d ? (d > 0 ? ++P : ++N) : ++Z;
        }

        return not ((P and N) or (P == 0 and N == 0));
    } 
};

int main()
{

    vector<Point<int>> xs { { 0, 0 }, { 2, 1 }, { 3, 4 }, { 5, 2 }, { 4, 0 } };
    vector<Point<int>> ys { { 6, 1 }, { 9, 3 }, { 9, 1 }, { 6, 3 } };
    vector<Point<int>> zs { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 } };

    Polygon<int> A(xs), B(ys), C(zs);

    cout << "A is convex? " << A.convex() << '\n';
    cout << "B is convex? " << B.convex() << '\n';
    cout << "C is convex? " << C.convex() << '\n';

    return 0;
}

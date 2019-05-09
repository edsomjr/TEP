#include <bits/stdc++.h>

using namespace std;

const double EPS { 1e-6 };

template<typename T>
bool equals(T a, T b)
{
    if (std::is_floating_point<T>::value)
        return fabs(a - b) < EPS;
    else
        return a == b;
}

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
T D(const Point<T>& P, const Point<T>& Q, const Point<T>& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) -
           (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

template<typename T>
class GrahamScan
{
private:
    static Point<T> pivot(vector<Point<T>>& P)
    {
        size_t idx = 0;

        for (size_t i = 1; i < P.size(); ++i)
            if (P[i].y < P[idx].y or 
                (equals(P[i].y, P[idx].y) and P[i].x > P[idx].x))
                    idx = i;

        swap(P[0], P[idx]);

        return P[0];
    }

    static void sort_by_angle(vector<Point<T>>& P)
    {
        auto P0 = pivot(P);

        sort(P.begin() + 1, P.end(),
            [&](const Point<T>& A, const Point<T>& B) {
                // pontos colineares: escolhe-se o mais próximo do pivô
                if (equals(D(P0, A, B), 0))
                    return A.distance(P0) < B.distance(P0);

                auto alfa = atan2(A.y - P0.y, A.x - P0.x);
                auto beta = atan2(B.y - P0.y, B.x - P0.x);

                return alfa < beta;
            }
        );
    }

public:
    static vector<Point<T>> convex_hull(const vector<Point<T>>& points)
    {
        vector<Point<T>> P(points);
        auto N = P.size();

        // Corner case: com 3 vértices ou menos, P é o próprio convex hull
        if (N <= 3)
            return P;

        sort_by_angle(P);

        vector<Point<T>> ch;
        ch.push_back(P[N - 1]);
        ch.push_back(P[0]);
        ch.push_back(P[1]);

        size_t i = 2;

        while (i < N)
        {
            auto j = ch.size() - 1;

            if (D(ch[j - 1], ch[j], P[i]) > 0)
                ch.push_back(P[i++]);
            else
                ch.pop_back();
        }

        // O envoltório é um caminho fechado: o primeiro ponto é igual
        // ao último
        return ch;
    }
};

int main()
{
    vector<Point<int>> P { { 0, 0 }, { 5, 3 }, { 8, -2 }, { 4, 4 }, { 2, 1 }, { 2, 5 }, { 3, -1 },
        { 7, 2 }, { 5, 0 }, { 0, 4 }, { 1, -1 }, { 7, -2 }, { 6, 4 }, { 6, 0 }, { 1, 3 } };

    auto ch = GrahamScan<int>::convex_hull(P);

    for (size_t i = 0; i < ch.size(); ++i)
        cout << i + 1 << ": (" << ch[i].x << ", " << ch[i].y << ")\n";

    return 0;
}

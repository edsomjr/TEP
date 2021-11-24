#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;

    bool operator<(const Point& p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
};

bool has_center_of_symmetry(const set<Point>& S)
{
    auto A = *S.begin();            // Primeiro ponto, após ordenação
    auto B = *S.rbegin();           // Último ponto, após ordenação

    // Candidato à centro de simetria
    auto _2s = Point { A.x + B.x, A.y + B.y };

    // Verifica se o candidato atende todos os pontos de S
    for (auto& p : S)
    {
        auto q = Point { _2s.x - p.x, _2s.y - p.y };

        if (S.count(q) == 0)
            return false;
    }

    return true;
}

int main()
{
    int c, n;
    cin >> c;

    while (c--) {
        cin >> n;

        set<Point> S;

        while (n--)
        {
            int x, y;
            cin >> x >> y;

            S.insert(Point { x, y });
        }

        cout << (has_center_of_symmetry(S) ? "yes" : "no") << '\n';
    }

    return 0;
}

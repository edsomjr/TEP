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
    auto A = *S.begin();                                // Ponto qualquer de S 

    for (auto& B : S) {
        auto _2s = Point { A.x + B.x, A.y + B.y };      // Candidato à centro de simetria
        bool ok = true;

        // Verifica se o candidato atende o critério para todos os pontos de S
        for (auto& p : S)
        {
            auto q = Point { _2s.x - p.x, _2s.y - p.y };

            if (S.count(q) == 0) {
                ok = false;
                break;
            }
        }

        if (ok)
            return true;
    }

    return false;
}

int main() {
    int c, n, x, y;
    cin >> c;

    while (c--) {
        cin >> n;

        set<Point> S;

        while (n--) {
            cin >> x >> y;
            S.insert(Point { x, y });
        }

        cout << (has_center_of_symmetry(S) ? "yes" : "no") << '\n';
    }

    return 0;
}

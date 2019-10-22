#include <iostream>
#include <set>

struct Point {
    int x, y;

    bool operator<(const Point& p) const
    {
        return x == p.x ? y < p.y : x < p.x;
    }
};

bool has_center_of_symmetry(const std::set<Point>& S)
{
    auto A = *S.begin();        // Ponto qualquer de S fixo

    for (auto& B : S)
    {
        // Candidato à centro de simetria
        auto _2s = Point { A.x + B.x, A.y + B.y };
        bool ok = true;

        // Verifica se o candidato atende todos os pontos de S
        for (auto& p : S)
        {
            auto q = Point { _2s.x - p.x, _2s.y - p.y };

            if (S.count(q) == 0)
            {
                ok = false;
                break;
            }
        }

        if (ok)
            return true;
    }

    return false;
}

int main()
{
    int c, n;
    std::cin >> c;

    while (c--) {
        std::cin >> n;

        std::set<Point> S;

        while (n--) {
            int x, y;
            std::cin >> x >> y;
            S.insert(Point { x, y });
        }

        std::cout << (has_center_of_symmetry(S) ? "yes" : "no") << '\n';
    }

    return 0;
}

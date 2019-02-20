// Definição função equals(), das classes Point e Line

const int INF { -1 };

template<typename T>
std::pair<int, Point<T>> intersections(const Line<T>& r, const Line<T>& s)
{
    auto det = r.a * s.b - r.b * s.a;

    if (equals(det, 0))     // Coincidentes ou paralelas
    {
        int qtd = (r == s) ? INF : 0;
        return std::pair<int, Point<T>>(qtd, Point());
    } else                  // Concorrentes
    {
        auto x = (-r.c * s.b + s.c * r.b) / det;
        auto y = (-s.c * r.a + r.c * s.a) / det;

        return std::pair<int, Point<T>>(1, Point<T>(x, y));
    }
}

const int oo { -1 };

template<typename T>
std::pair<int, Point<T>> intersections(const Line<T>& r, const Line<T>& s)
{
    auto det = r.a * s.b - r.b * s.a;

    if (equals(det, 0))     // Coincidentes ou paralelas
    {
        return { (r == s) ? oo : 0, {} };
    }
    else                    // Concorrentes
    {
        auto x = (-r.c * s.b + s.c * r.b) / det;
        auto y = (-s.c * r.a + r.c * s.a) / det;

        return { 1, { x, y } };
    }
}

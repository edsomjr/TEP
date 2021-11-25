template<typename T>
Point<T> translate(const Point<T>& P, T dx, T dy)
{
    return Point<T> { P.x + dx, P.y + dy };
}

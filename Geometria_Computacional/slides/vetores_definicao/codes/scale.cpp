template<typename T>
Vector<T> scale(const Vector<T>& v, T sx, T sy)
{
    return Vector<T> {sx * v.x, sy * v.y};
}

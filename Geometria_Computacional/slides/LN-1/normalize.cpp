// Definição da classe Vector

template<typename T>
Vector<T> normalize(const Vector<T>& v)
{
    auto len = v.length();
    return Vector<T>(v.x / len, v.y / len);
}

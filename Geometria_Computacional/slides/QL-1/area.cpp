template<typename T>
struct Rectangle {
    // Membros e construtores

    T perimeter() const
    {
        return 2 * (b + h);
    }

    T area() const
    {
        return b * h;
    }
};

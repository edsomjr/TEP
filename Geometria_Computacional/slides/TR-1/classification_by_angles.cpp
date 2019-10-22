// Definição da classe Point, da função de comparação equals() e
// da função de distância entre pontos dist()

template<typename T>
struct Triangle {
    Point<T> A, B, C; 

    enum Angles { RIGHT, ACUTE, OBTUSE };

    Angles classification_by_angles() const
    {
        auto a = dist(A, B);
        auto b = dist(B, C);
        auto c = dist(C, A);

        auto alpha = acos((a*a - b*b - c*c)/(-2*b*c));
        auto beta = acos((b*b - a*a - c*c)/(-2*a*c));
        auto gamma = acos((c*c - a*a - b*b)/(-2*a*b));

        auto right = PI / 2.0;

        if (equals(alpha, right) || equals(beta, right) 
            || equals(gamma, right))
            return RIGHT;

        if (alpha > right || beta > right || gamma > right)
            return OBTUSE;

        return ACUTE;
    }
};

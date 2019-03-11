#include <optional>

// Definição da class Point e das funções equals() e distance()

template<typename T>
struct Circle {
    // Membros e construtores

    static std::optional<Circle>
    from_3_points(const Point<T>& P, const Point<T>& Q, const Point<T>& R)
    {
        auto a = 2*(Q.x - P.x);
        auto b = 2*(Q.y - P.y);
        auto c = 2*(R.x - P.x);
        auto d = 2*(R.y - P.y);

        auto det = a*d - b*c;

        // Pontos colineares
        if (equals(det, 0))
            return { };

        auto k1 = (Q.x*Q.x + Q.y*Q.y) - (P.x*P.x + P.y*P.y);
        auto k2 = (R.x*R.x + R.y*R.y) - (P.x*P.x + P.y*P.y);

        // Solução do sistema por Regra de Cramer
        auto cx = (k1*d - k2*b)/det;
        auto cy = (a*k2 - c*k1)/det;

        Point<T> C { cx, cy };
        auto r = distance(P, C);

        return Circle<T>(C, r);
    }
};

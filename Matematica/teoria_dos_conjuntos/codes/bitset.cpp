#include <bits/stdc++.h>

int main()
{
    std::bitset<35> A(2046), B(10412);

    std::cout << A.to_string() << '\n';
    std::cout << B.to_string() << '\n';

    auto C = A | B;
    std::cout << "union = " << C.to_string() << '\n';

    C = A & B;
    std::cout << "interseção = " << C.to_string() << '\n';

    C = A & ~B;
    std::cout << "diferença = " << C.to_string() << '\n';

    return 0;
}

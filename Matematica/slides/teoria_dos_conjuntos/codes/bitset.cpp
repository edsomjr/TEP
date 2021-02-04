#include <bits/stdc++.h>

using namespace std;

int main()
{
    bitset<35> A(2046), B(10412);

    cout << A.to_string() << '\n';
    cout << B.to_string() << '\n';

    auto C = A | B;
    cout << "union = " << C.to_string() << '\n';

    C = A & B;
    cout << "interseção = " << C.to_string() << '\n';

    C = A & ~B;
    cout << "diferença = " << C.to_string() << '\n';

    return 0;
}

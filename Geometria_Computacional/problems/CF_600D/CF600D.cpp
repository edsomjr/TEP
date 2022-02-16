#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr long double PI = acosl(-1.0);

long double intersection_area(long double r, long double R, long double d)
{
    auto angle = acosl((r*r + d*d - R*R)/(2*r*d));  // Lei dos cossenos
    auto sector = angle * r * r;                    // Setor de 2*angle
    auto T = r * r * cosl(angle) * sinl(angle);     // Aŕea do triângulo

    return sector - T;
}

void solve(ll X1, ll Y1, ll R1, ll X2, ll Y2, ll R2)
{
    // Não se interceptam ou se tocam em um único ponto
    auto dist2 = (X1 - X2)*(X1 - X2) + (Y1 - Y2)*(Y1 - Y2);

    if (dist2 >= (R1 + R2)*(R1 + R2))
    {
        cout << "0.00000000000000000000\n";
        return;
    }

    // O primeiro círculo será o de maior raio
    if (R2 > R1)
    {
        swap(X1, X2);
        swap(Y1, Y2);
        swap(R1, R2);
    }

    // O menor está contido no maior: a resposta é a área do menor
    if (dist2 <= (R1 - R2)*(R1 - R2))
    {
        cout.precision(20);
        cout << PI*R2*R2 << '\n';
        return;
    } 

    // Dois pontos de interseção
    auto d = sqrtl(dist2);
    auto A1 = intersection_area(R1, R2, d);
    auto A2 = intersection_area(R2, R1, d);

    cout.precision(20);
    cout << A1 + A2 << endl;
}

int main()
{
    ios::sync_with_stdio(false);

    int X1, Y1, R1, X2, Y2, R2;
    cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;

    solve(X1, Y1, R1, X2, Y2, R2);

    return 0;
}

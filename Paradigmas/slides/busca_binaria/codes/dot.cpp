#include <bits/stdc++.h>

using namespace std;

int main()
{
    int xs[] { -1, 0, 4 }, ys[] { 2, 3, -3 }, zs[3];

    transform(xs, xs + 3, zs, [](int x) { return abs(x); });

    for (int i = 0; i < 3; ++i)
        cout << z[i] << (i + 1 == 3 ? '\n' : ' ');
    
    transform(xs, xs + 3, ys, zs, [](int x, int y) { return x * y; });

    for (int i = 0; i < 3; ++i)
        cout << z[i] << (i + 1 == 3 ? '\n' : ' ');

    return 0;
}

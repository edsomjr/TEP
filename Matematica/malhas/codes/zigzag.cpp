#include <bits/stdc++.h>

using namespace std;

int position(int x, int y, int W)
{
    int pos = (y - 1)*W + (y % 2 ? x : W - x + 1);

    return pos; 
}

pair<int, int> coordinates(int n, int W)
{
    auto y = ((n - 1) / W) + 1;
    auto x = y % 2 ? ((n - 1) % W) + 1 : W - ((n - 1) % W);

    return { x, y };
}

int main()
{
    int W, H, op, x, y, n;
    cin >> W >> H >> op;

    switch (op) {
    case 1:
        cin >> x >> y;
        cout << "(" << x << ", " << y << ") = point " << position(x, y, W) << '\n';

        break;

    default:
        cin >> n;

        auto [a, b] = coordinates(n, W);

        cout << "point " << n << " = (" << a << ", " << b << ")\n";
    }

    return 0;
}

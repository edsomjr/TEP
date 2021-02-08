#include <bits/stdc++.h>

using namespace std;

int position(int x, int y, int W, int)
{
    int pos = (x - 1)*W + (x % 2 ? y : W - y + 1);

    return pos; 
}

void coordinates(int n, int& x, int& y, int W, int)
{
    x = ((n - 1) / W) + 1;
    y = x % 2 ? ((n - 1) % W) + 1 : W - ((n - 1) % W);
}

int main()
{
    int W, H, op, x, y, n;
    cin >> W >> H >> op;

    switch (op) {
    case 1:
        cin >> x >> y;
        cout << "(" << x << ", " << y << ") = point " << position(x, y, W, H) << '\n';

        break;

    default:
        cin >> n;

        coordinates(n, x, y, W, H);

        cout << "point " << x << " = (" << x << ", " << y << ")\n";
    }

    return 0;
}

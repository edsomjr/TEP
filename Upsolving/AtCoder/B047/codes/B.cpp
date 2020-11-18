#include <bits/stdc++.h>

using namespace std;

int main()
{
    int W, H, N;
    cin >> W >> H >> N;

    int xL = 0, xR = W, yL = 0, yR = H;

    while (N--)
    {
        int x, y, a;
        cin >> x >> y >> a;

        switch (a) {
        case 1:
            xL = max(xL, x);
            break;

        case 2:
            xR = min(xR, x);
            break;

        case 3:
            yL = max(yL, y);
            break;

        case 4:
            yR = min(yR, y);
            break;
        }
    }

    auto w = max(xR - xL, 0), h = max(yR - yL, 0);
    int ans = w*h;

    cout << ans << '\n';

    return 0;
}

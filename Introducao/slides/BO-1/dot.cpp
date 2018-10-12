#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int xs[] { -1, 0, 4 }, ys[] { 2, 3, -3 }, zs[3];

    transform(xs, xs + 3, zs, [](int x) { return abs(x); });

    for (int i = 0; i < 3; ++i)
        printf("%d%c", zs[i], " \n"[i + 1 == 3]);
    
    transform(xs, xs + 3, ys, zs, [](int x, int y) { return x * y; });

    for (int i = 0; i < 3; ++i)
        printf("%d%c", zs[i], " \n"[i + 1 == 3]);

    return 0;
}

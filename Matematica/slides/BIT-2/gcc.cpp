#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 1968;       // 123 x 16 = 11110110000

    cout << __builtin_popcount(x) << '\n';      // 6
    cout << __builtin_ffs(x) << '\n';           // 5
    cout << __builtin_clz(x) << '\n';           // 21
    cout << __builtin_ctz(x) << '\n';           // 4

    return 0;
}

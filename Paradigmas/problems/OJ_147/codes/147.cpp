#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 30010 };
const vector<int> cs { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5 };

ll st[MAX];

void precomp()
{
    st[0] = 1;

    for (auto c : cs)
        for (int m = c; m < MAX; m += 5)
                st[m] += st[m - c];
}

int main()
{
    precomp();

    int d, c;

    while (scanf("%d.%d", &d, &c) == 2 and d + c)
        printf("%3d.%02d%17lld\n", d, c, st[100*d + c]);

    return 0;
}

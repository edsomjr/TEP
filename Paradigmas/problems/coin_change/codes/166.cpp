#include <bits/stdc++.h>

using namespace std;

const int oo { 1000000010 }, N = 6;
const vector<int> cs { 5, 10, 20, 50, 100, 200 }, ys(cs.size(), oo);

int greedy(int m, const vector<int>& qs)
{
    int res = 0;

    for (int i = N - 1; i >= 0; --i)
    {
        auto k = min(qs[i], m / cs[i]);
        m -= k*cs[i];
        res += k;
    }

    return m > 0 ? oo : res;
}
        
int solve(int M, const vector<int>& xs)
{
    int total = 0, ans = oo;

    for (int i = 0; i < N; ++i)
        total += xs[i] * cs[i];

    for (int m = M; m <= total; m += 5)
        ans = min(ans, greedy(m, xs) + greedy(m - M, ys));

    return ans;
}

int main()
{
    while (true)
    {
        vector<int> xs(6);

        for (int i = 0; i < N; ++i)
            scanf("%d", &xs[i]);

        if (accumulate(xs.begin(), xs.end(), 0) == 0)
            break;

        int d, c;
        scanf("%d.%d", &d, &c);

        auto ans = solve(100*d + c, xs);

        printf("%3d\n", ans);
    }

    return 0;
}

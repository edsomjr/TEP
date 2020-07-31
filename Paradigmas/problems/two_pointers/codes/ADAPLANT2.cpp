#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int oo { 1000000010 };

struct StackM {

    function<int(int, int)> op;
    stack<ii> in, out;

    void add(int x) { add(x, in); }

    int top()
    {
        if (in.empty())
            return out.top().second;
        else if (out.empty())
            return in.top().second;

        return op(in.top().second, out.top().second);
    }

    void pop()
    {
        move();
        out.pop();
    }

    void move()
    {
        if (out.empty())
        {
            while (not in.empty())
            {
                auto x = in.top().first;
                in.pop();
                add(x, out);
            }
        }
    }

    void add(int x, stack<ii>& s)
    {
        int m = s.empty() ? x : op(s.top().second, x);
        s.push(ii(x, m));
    }
};

int solve(int N, int K, const vector<int>& xs)
{
    K = min(N - 1, K + 1);

    auto min_of = [](int x, int y) { return min(x, y); };
    auto max_of = [](int x, int y) { return max(x, y); };

    StackM smin { min_of, {}, {} };
    StackM smax { max_of, {}, {} };

    int L = 0, R;

    for (R = 0; R <= K; ++R)
    {
        smin.add(xs[R]);
        smax.add(xs[R]);
    }

    int ans = smax.top() - smin.top();

    while (R < N)
    {
        smin.pop();
        smax.pop();

        smin.add(xs[R]);
        smax.add(xs[R]);

        ++L;
        ++R;

        ans = max(ans, smax.top() - smin.top());
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int N, K;
        cin >> N >> K;

        vector<int> xs(N);

        for (int i = 0; i < N; ++i)
            cin >> xs[i];

        auto ans = solve(N, K, xs);

        cout << ans << endl;
    }

    return 0;
}

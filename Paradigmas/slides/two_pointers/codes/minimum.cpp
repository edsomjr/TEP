#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
const int oo { 1000000010 };

void insert(stack<ii>& s, int x)
{
    int m = s.empty() ? x : min(s.top().second, x);
    s.push(ii(x, m));
}

void move(stack<ii>& out, stack<ii>& in)
{
    while (not in.empty())
    {
        auto x = in.top().first;
        in.pop();
        insert(out, x);
    }
}

vector<int> minimum(int N, int K, const vector<int>& xs)
{
    stack<ii> in, out;

    int L = 0, R;

    for (R = 0; R < K; ++R)
        insert(in, xs[R]);

    move(out, in);

    vector<int> ans(N - K + 1, -1);

    ans[L] = out.top().second;

    while (R < N)
    {
        if (out.empty())
            move(out, in);

        insert(in, xs[R]); 
        out.pop();

        ++L;
        ++R;

        auto a = in.empty() ? oo : in.top().second;
        auto b = out.empty() ? oo : out.top().second;

        ans[L] = min(a, b);
    }

    return ans;
}

int main()
{
    vector<int> xs { 1, 3, 2, 3, 4, 5, 8, 2, 7, 5, 3, 10, 6, 9 };
    int K = 3;

    auto ans = minimum((int) xs.size(), K, xs);

    for (size_t i = 0; i < ans.size(); ++i)
    {
        cout << "[";

        for (int j = 0; j < K; ++j) 
            cout << xs[i + j] << (j + 1 == K ? "]" : ", ");

        cout << " -> " << ans[i] << '\n';
    }

    return 0;
}

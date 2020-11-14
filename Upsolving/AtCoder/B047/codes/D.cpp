#include <bits/stdc++.h>

using namespace std;

int solve(int N, int T, const vector<int>& xs)
{
    priority_queue<int> pq;
    int best = xs[N - 1];

    for (int i = N - 2; i >= 0; --i)
    {
        pq.push(best - xs[i]);
        best = max(best, xs[i]);
    }

    auto m = pq.top(), ans = 0;
    
    while (not pq.empty() and pq.top() == m)
    {
        ++ans;
        pq.pop();
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, T;
    cin >> N >> T;

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    cout << solve(N, T, xs) << '\n';

    return 0;
}

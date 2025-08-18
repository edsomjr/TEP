#include <bits/stdc++.h>

using namespace std;

auto mesw(int n, int k, const vector<int>& xs)
{
    deque<int> q;

    for (int i = 0; i < k; ++i)
    {
        while (not q.empty() and xs[q.back()] >= xs[i])
            q.pop_back();

        q.emplace_back(i);
    }

    vector<int> ms { xs[q.front()] };

    for (int L = 0, R = k; R < n; ++L, ++R)
    {
        if (q.front() == L)
            q.pop_front();

        while (not q.empty() and xs[q.back()] >= xs[R])
            q.pop_back();

        q.emplace_back(R);
        ms.emplace_back(xs[q.front()]);
    }

    return ms;
}

int main()
{
    vector<int> as { 1, 4, 3, 4, 2, 1, 3 };
    int N = (int) as.size();

    auto ms = mesw(N, 3, as);

    for (int i = 0; i < N - 3 + 1; ++i)
    {
        cout << "min(";
        for (int j = 0; j < 3; ++j)
            cout << as[i + j] << (j == 2 ? ") = " : ", ");

        cout << ms[i] << '\n';
    }

    return 0;
}

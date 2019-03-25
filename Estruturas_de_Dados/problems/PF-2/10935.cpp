#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n)
{
    queue<int> q;

    for (int i = 1; i <= n; ++i)
        q.push(i);

    vector<int> ans;

    while (q.size() > 1)
    {
        auto x = q.front();
        q.pop();

        ans.push_back(x);

        auto y = q.front();
        q.pop();

        q.push(y);
    }

    ans.push_back(q.front());

    return ans;
}

int main()
{
    int n;

    while (cin >> n, n)
    {
        auto order = solve(n);

        cout << "Discarded cards:";

        for (int i = 0; i < n - 1; ++i)
            cout << (i ? ", " : " ") << order[i];

        cout << "\nRemaining card: " << order.back() << '\n';
    }

    return 0;
} 

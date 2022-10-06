#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> xs { 40, 68, 15, 99, 24, 6, 51, 77 };

    priority_queue<int> p;

    for (auto x : xs)
        p.push(-x);

    while (not p.empty())
    { 
        cout << -p.top() << ' ';
        p.pop();
    }

    cout << '\n';       // 6 15 24 40 51 68 77 99

    priority_queue<int, vector<int>, greater<int>> q(xs.begin(), xs.end());

    while (not q.empty())
    { 
        cout << q.top() << ' ';
        q.pop();
    }

    cout << '\n';       // 6 15 24 40 51 68 77 99


    return 0;
}

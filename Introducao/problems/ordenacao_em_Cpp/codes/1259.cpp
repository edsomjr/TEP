#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& ns)
{
    sort(ns.begin(), ns.end(), [](int a, int b)
        {
            int pa = a % 2, pb = b % 2;

            return pa == pb ? (pa ? a > b : a < b) : pa < pb;
        }
    );
}

int main()
{
    int N;
    
    while (cin >> N)
    {
        vector<int> ns(N);

        for (int i = 0; i < N; i++)
            cin >> ns[i];

        solve(ns);

        for (const auto& n : ns)
            cout << n << '\n';
    }

    return 0;
}

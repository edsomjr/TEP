#include <bits/stdc++.h>

using namespace std;

string solve(int a, int b, int c)
{
    vector<int> xs { a, b, c };
    sort(xs.begin(), xs.end());

    return xs[2] == xs[0] + xs[1] ? "Yes" : "No";
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    cout << solve(a, b, c) << '\n';

    return 0;
}

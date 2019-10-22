#include <bits/stdc++.h>

using namespace std;

string solve(string& a, string& b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    string ans;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(),
        back_inserter(ans));

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    string a, b;

    while (getline(cin, a), getline(cin, b))
    {
        auto ans = solve(a, b);

        cout << ans << endl;
    }

    return 0;
}

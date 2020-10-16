#include <bits/stdc++.h>

using namespace std;

int main()
{
    string w;
    cin >> w;

    vector<int> hw(26, 0);

    for (auto c : w)
        hw[c - 'a'] ^= 1;

    auto ans = accumulate(hw.begin(), hw.end(), 0)
        ? "No" : "Yes";

    cout << ans << '\n';

    return 0;
}

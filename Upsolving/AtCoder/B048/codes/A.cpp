#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    string ans { "AxC" };
    ans[1] = b.front();

    cout << ans << '\n';

    return 0;
}

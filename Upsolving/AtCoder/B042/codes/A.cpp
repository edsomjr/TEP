#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;

    if ((A == 5 and B == 5 and C == 7) or
        (A == 5 and B == 7 and C == 5) or
        (A == 7 and B == 5 and C == 5))
            cout << "YES\n";
    else
            cout << "NO\n";

    return 0;
}

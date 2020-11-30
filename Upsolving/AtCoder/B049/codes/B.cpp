#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    vector<string> M(H);

    for (int i = 0; i < H; ++i)
        cin >> M[i];

    for (auto x : M)
        cout << x << '\n' << x << '\n';

    return 0;
}

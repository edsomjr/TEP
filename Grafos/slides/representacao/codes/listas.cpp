#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

vector<ii> adj[] { {}, { { 2, 2 }, { 3, 1 }, { 4, 8 } }, 
    { { 1, 5 }, { 4, 7 }, { 5, 2 } }, { { 1, 3 }, { 4, 9 }, { 6, 4 } }, 
    { { 3, 1 } }, { { 2, 3 }, { 6, 6 } }, { { 4, 5 } }, };

int main()
{
    for (int u = 1; u <= 6; ++u) {
        cout << u << ":";

        for (auto [v, w] : adj[u])
            cout << " (" << v << ", " << w << ')';
        cout << '\n';
    }

    return 0;
}

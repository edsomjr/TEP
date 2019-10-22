#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

vector<ii> adj[] { {}, { { 2, 2 }, { 3, 1 }, { 4, 8 } }, 
    { { 1, 5 }, { 4, 7 }, { 5, 2 } }, { { 1, 3 }, { 4, 9 }, { 6, 4 } }, 
    { { 3, 1 } }, { { 2, 3 }, { 6, 6 } }, { { 4, 5 } }, };

int main()
{
    for (int u = 1; u <= 6; ++u) {
        cout << u << ": ";

        for (size_t v = 0; v < adj[u].size(); ++v)
            cout << "(" << adj[u][v].first << ", " << adj[u][v].second 
                << ")" << (v + 1 == adj[u].size() ? '\n' : ' ');
    }

    return 0;
}

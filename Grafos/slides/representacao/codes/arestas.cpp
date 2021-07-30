#include <bits/stdc++.h>

using namespace std;
using edge = tuple<int, int, int>;

vector<edge> es { { 1, 2, 2 }, { 1, 3, 1 }, { 1, 4, 8 }, { 2, 1, 5 }, 
    { 2, 4, 7 }, { 2, 5, 2 }, { 3, 1, 3 }, { 3, 4, 9 }, { 3, 6, 4 }, 
    { 4, 3, 1 }, { 5, 2, 3 }, { 5, 6, 6 }, { 6, 4, 5 } };

int main()
{
    for (auto [u, v, w] : es)
        cout << "(" << u << ", " << v << ", " << w << ")\n";

    return 0;
}

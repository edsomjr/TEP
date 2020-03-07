#include <bits/stdc++.h>
#include "segtree.h"

using namespace std;

int main()
{
    vector<int> xs { 1, 2, 3, 4, 5, 6, 7, 8 };

    SegmentTree<int> tree(xs);

    cout << tree.RSQ(2, 6) << endl;

    return 0;
}

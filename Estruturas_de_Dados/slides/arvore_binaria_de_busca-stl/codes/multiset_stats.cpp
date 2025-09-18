#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_multiset;

int main()
{
    ordered_multiset s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);

    // s = 1 2 2 3 3 3
    for (auto x : s)
        cout << x << ' ';
    cout << '\n';

    s.erase(s.find_by_order(s.order_of_key(3)));

    // s = 1 2 2 3 3
    for (auto x : s)
        cout << x << ' ';
    cout << '\n';

    return 0;
}

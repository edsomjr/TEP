#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s;
    int x;

    for (int i = 0; i < 3; ++i)
    {
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int solve(multiset<int>& s, const multiset<int>& r)
{
    vector<int> xs;
    set_intersection(s.begin(), s.end(), r.begin(), r.end(), 
        back_inserter(xs));
    return s.size() + r.size() - 2*xs.size();
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M, x;
        cin >> N >> M;

        multiset<int> s, r;

        while (N--)
        {
            cin >> x;
            s.insert(x);
        }

        while (M--)
        {
            cin >> x;
            r.insert(x);
        }

        cout << solve(s, r) << '\n';
    }

    return 0;
}

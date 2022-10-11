#include <bits/stdc++.h>

using namespace std;

set<int> subset_sum(const vector<int>& xs)
{
    set<int> s;

    for (size_t i = 0; i < (1ul << xs.size()); ++i) {
        int sum = 0;

        for (size_t j = 0; j < xs.size(); ++j)
            if ((1 << j) & i)
                sum += xs[j];

       s.insert(sum);
    }

    return s;
}

bool solve(int x, const vector<int>& xs)
{
    int N = xs.size();

    vector<int> g1(xs.begin(), xs.begin() + N/2);
    vector<int> g2(xs.begin() + N/2, xs.end());

    auto s1 = subset_sum(g1), s2 = subset_sum(g2);

    for (auto s : s1)
        if (s2.count(x - s))
            return true;
 
    return false;
}

int main()
{
    vector<int> xs { 2, 5, -3, 4, -1, 8 };
    int x = 10;

    cout << solve(x, xs) << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long solve(const vector<int>& as)
{
    map<int, int> R;                // Histograma à direita
    set<int> processed;
    long long ans = 0;

    for (auto a : as)
        ++R[a];

    for (auto a : as)
    {
        --R[a];

        if (R[a] == 0)
            R.erase(a);

        if (processed.count(a))
            continue;

        ans += R.size();            // Soma os elementos distintos à direita
        processed.insert(a);
    }
 
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> as(N);

    for (int i = 0; i < N; ++i)
        cin >> as[i];

    auto ans = solve(as);

    cout << ans << '\n';

    return 0;
}

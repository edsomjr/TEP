#include <bits/stdc++.h>
 
using namespace std;
 
pair<int, int> solve(vector<int>& as) {
    sort(as.begin(), as.end());

    auto ai = as.back(), aj = -1, dist = 2000000010;
    as.pop_back();

    for (auto a : as) {
        auto k = min(a, ai - a);

        if (ai/2 - k < dist) {
            aj = a;
            dist = ai/2 - k;
        }
    }

    return { ai, aj };
}
 
int main()
{
    ios::sync_with_stdio(false);
 
    int N;
    cin >> N;
 
    vector<int> as(N);

    for (int i = 0; i < N; ++i)
        cin >> as[i];
 
    auto [ai, aj] = solve(as);
 
    cout << ai << " " << aj << '\n';
 
    return 0;
}

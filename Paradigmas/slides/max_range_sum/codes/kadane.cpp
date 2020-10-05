#include <bits/stdc++.h>

using namespace std;

int kadane(const vector<int>& as)
{
    vector<int> s(as.size());
    s[0] = as[0];

    for (size_t i = 1; i < as.size(); ++i)
        s[i] = max(as[i], s[i - 1] + as[i]);

    return *max_element(s.begin(), s.end());
}

int main()
{
    int N;
    cin >> N;

    vector<int> as(N);

    for (int i = 0; i < N; ++i)
        cin >> as[i];

    auto ans = kadane(as);

    cout << ans << '\n';

    return 0;
}

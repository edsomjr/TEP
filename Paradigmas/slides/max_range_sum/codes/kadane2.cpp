#include <bits/stdc++.h>

using namespace std;

int kadane(const vector<int>& as)
{
    int ans = as[0], sum = ans;

    for (size_t i = 1; i < as.size(); ++i)
    {
        if (sum < 0)
            sum = 0;

        sum += as[i];
        ans = max(ans, sum);
    } 

    return ans;
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

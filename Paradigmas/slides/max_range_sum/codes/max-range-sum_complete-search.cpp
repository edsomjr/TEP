#include <bits/stdc++.h>

using namespace std;

long long oo { 1LL << 62 };

long long MRS(const vector<int>& as)
{
    auto N = as.size();
    long long ans = -oo;

    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = i; j < N; ++j)
        {
            long long sum = 0;

            for (size_t k = i; k <= j; ++k)
                sum += as[k];

            ans = max(ans, sum);
        }
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

    auto ans = MRS(as);

    cout << ans << '\n';

    return 0;
}

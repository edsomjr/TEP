#include <bits/stdc++.h>

using namespace std;

int solve(int N, const vector<int>& xs)
{
    vector<int> st(N, 1);

    st[0] = 1;

    for (int i = 1; i < N; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
            if (xs[i] > xs[j])
                st[i] = max(st[i], st[j] + 1); 
    }

    return *max_element(st.begin(), st.end());
}

int main()
{
    int N;
    cin >> N;

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, xs);

    cout << ans << '\n';

    return 0;
}

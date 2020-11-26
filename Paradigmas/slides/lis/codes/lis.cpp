#include <bits/stdc++.h>

using namespace std;

int LIS(int N, const vector<int>& xs)
{
    vector<int> lis(N, 1);

    for (int i = 1; i < N; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (xs[i] > xs[j])
                lis[i] = max(lis[i], lis[j] + 1); 
        }
    }

    return *max_element(lis.begin(), lis.end());
}

int main()
{
    vector<int> xs { 4, 1, 5, 2, 6, 3 };

    cout << LIS((int) xs.size(), xs) << '\n';

    return 0;
}

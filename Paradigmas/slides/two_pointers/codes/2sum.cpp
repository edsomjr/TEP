#include <bits/stdc++.h>

using namespace std;

bool _2sum(int N, int S, vector<int>& xs)
{
    sort(xs.begin(), xs.end());

    int L = 0, R = N - 1;

    // A solução exige dois elementos distintos de xs
    while (L < R)
    {
        while (R > L and xs[L] + xs[R] > S)
            --R;

        if (R <= L)
            break;

        if (xs[L] + xs[R] == S)
            return true;

        ++L;
    }

    return false;
}

int main()
{
    vector<int> xs { 1, -2, 5, 8, -3, 7, -5 };
    int N = (int) xs.size();

    cout << _2sum(N, 0, xs) << endl;
    cout << _2sum(N, 1, xs) << endl;
    cout << _2sum(N, 4, xs) << endl;
    cout << _2sum(N, 14, xs) << endl;

    return 0;
}

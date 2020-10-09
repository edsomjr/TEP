#include <bits/stdc++.h>

using namespace std;

bitset<10> ds;

bool is_valid(int n)
{
    while (n)
    {
        auto d = n % 10;
        n /= 10;

        if (ds[d])
            return false;
    }

    return true;
}

int solve(int N)
{
    while (not is_valid(N))
        ++N;

    return N;
}

int main() {
    int N, K, d;
    cin >> N >> K;

    while (K--) {
        cin >> d;
        ds[d] = true;
    }

    cout << solve(N) << '\n';

    return 0;
}

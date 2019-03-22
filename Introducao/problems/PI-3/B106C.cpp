#include <iostream>

using namespace std;
using ll = long long;

char solve(const string& S, ll K)
{
    for (const auto& c : S)
    {
        if (c != '1')
            return c;

        if (not (--K))
            break;
    }

    return '1';
}

int main()
{
    ios::sync_with_stdio(false);

    string S;
    ll K;

    cin >> S >> K;
    
    cout << solve(S, K) << '\n';

    return 0;
}

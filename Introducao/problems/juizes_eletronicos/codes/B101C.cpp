#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    auto ans = (N - 1 + K - 2)/(K - 1);

    cout << ans << '\n';

    return 0;
}

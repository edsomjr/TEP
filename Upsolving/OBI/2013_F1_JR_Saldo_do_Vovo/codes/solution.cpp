#include <iostream>

using namespace std;

int main()
{
    int N, S;
    cin >> N >> S;

    int ans = S;

    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;

        S += x;

        if (S < ans)
            ans = S;
    }

    cout << ans << "\n";

    return 0;
}

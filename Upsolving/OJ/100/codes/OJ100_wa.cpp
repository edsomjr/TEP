#include <iostream>

using namespace std;

int cycle_length(int n)
{
    int ans = 1;

    while (n > 1)
    {
        if (n % 2)
            n = 3*n + 1;
        else
            n /= 2;

        ans++;
    }

    return ans;
}

int main()
{
    int i, j;

    while (cin >> i >> j)
    {
        int ans = 0;

        for (int n = i; n <= j; n++)
            ans = max(ans, cycle_length(n));

        cout << i << " " << j << " " << ans << '\n';
    }

    return 0;
}

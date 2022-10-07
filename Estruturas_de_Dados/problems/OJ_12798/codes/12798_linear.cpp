#include <bits/stdc++.h>

using namespace std;

const int MAX { 110 };

int main()
{
    ios::sync_with_stdio(false);

    size_t N, M;

    while (cin >> N >> M)
    {
        bitset<MAX> bs;

        for (size_t i = 1; i <= N; ++i)
        {
            bs[i] = true;

            for (size_t j = 1; j <= M; ++j)
            {
                int goals;
                cin >> goals;

                if (goals == 0) 
                    bs[i] = false;
            }
        }

        cout << bs.count() << '\n';
    }

    return 0;
}

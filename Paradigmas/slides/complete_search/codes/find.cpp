#include <bits/stdc++.h>

int find(int x, int N, const std::vector<int>& xs)
{
    for (int i = 0; i < N; ++i)
        if (x == xs[i])
            return i;

    return -1;
}

int main()
{
    std::vector<int> xs { 2, 3, 5, 7, 11, 13, 17, 19 };

    std::cout << find(13, 8, xs) << '\n' << find(9, 8, xs) << '\n';

    return 0;
}

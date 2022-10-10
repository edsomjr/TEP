#include <bits/stdc++.h>

template<typename T>
int find(const T& x, const std::vector<T>& xs)
{
    for (size_t i = 0; i < xs.size(); ++i)
        if (x == xs[i])
            return i;

    return -1;
}

int main()
{
    std::vector<int> xs { 2, 3, 5, 7, 11, 13, 17, 19 };

    std::cout << find(13, xs) << '\n' << find(9, xs) << '\n';

    return 0;
}

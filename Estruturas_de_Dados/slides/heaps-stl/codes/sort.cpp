#include <bits/stdc++.h>

int main()
{
    std::vector<int> xs { 99, 40, 68, 15, 24, 77, 6, 51 };
    int k = 3;

    std::partial_sort(xs.begin(), xs.begin() + k, xs.end());

    // xs = {6, 15, 24, 99, 68, 77, 40, 51}
    for (size_t i = 0; i < xs.size(); ++i)
        std::cout << xs[i] << (i + 1 == xs.size() ? "\n" : " ");

    std::sort(xs.begin(), xs.end(), std::greater<int>());

    // xs = {99, 77, 68, 51, 40, 24, 15, 6}
    for (size_t i = 0; i < xs.size(); ++i)
        std::cout << xs[i] << (i + 1 == xs.size() ? "\n" : " ");

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

template<typename T> int find(const T& x, const vector<T>& xs)
{
    for (size_t i = 0; i < xs.size(); ++i)
        if (x == xs[i])
            return i;

    return -1;
}

int main()
{
    vector<int> xs { 2, 3, 5, 7, 11, 13, 17, 19 };

    cout << find(13, xs) << '\n' << find(9, xs) << '\n';

    return 0;
}

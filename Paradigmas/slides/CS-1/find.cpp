#include <bits/stdc++.h>

using namespace std;

template<typename T> int find(const T& x, const vector<T>& as)
{
    for (size_t i = 0; i < as.size(); ++i)
        if (x == as[i])
            return i;

    return -1;
}

int main()
{
    vector<int> as { 2, 3, 5, 7, 11, 13, 17, 19 };

    cout << find(13, as) << '\n' << find(9, as) << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename RandIt>
ll merge(size_t N, RandIt first, RandIt middle, RandIt last)
{
    vector<typename iterator_traits<RandIt>::value_type> temp(N);
    auto it = first, jt = middle;
    auto k = 0;
    ll inversions = 0;

    while (it != middle and jt != last) {
        temp[k++] = min(*it, *jt);

        if (temp[k - 1] == *it)
            inversions += (jt - middle);

        temp[k - 1] == *it ? ++it : ++jt;
    }

    while (it != middle)
    {
        temp[k++] = *it++;
        inversions += (last - middle);
    }

    while (jt != last)
        temp[k++] = *jt++;

    for (const auto& elem : temp)
        *first++ = elem;

    return inversions;
}

template<typename RandomAccessIterator>
ll mergesort(RandomAccessIterator first, RandomAccessIterator last)
{
    auto N = last - first;

    if (N == 1)
        return 0;

    auto middle = first + (N + 1)/2;
    ll inversions = 0;

    inversions += mergesort(first, middle);
    inversions += mergesort(middle, last);
    inversions += merge(N, first, middle, last);

    return inversions;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N)
    {
        vector<int> xs(N);

        for (int i = 0; i < N; ++i)
            cin >> xs[i];

        auto ans = mergesort(xs.begin(), xs.end());

        cout << "Minimum exchange operations : " << ans << '\n';
    }

    return 0;
}
